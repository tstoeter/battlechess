#include "game.h"

#include <allegro5/allegro.h>
#include <glib.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"
#include "movement.h"
#include "piece.h"

static GList 			*threats;
static ALLEGRO_BITMAP 	*threat_ghost;

/*
 * Draw a ghost
 */
static ALLEGRO_BITMAP *draw_ghost(ALLEGRO_BITMAP *bmp, ALLEGRO_COLOR color, bool full)
{
	ALLEGRO_BITMAP *backbuffer = al_get_target_bitmap();

	ALLEGRO_BITMAP *ghost = al_create_bitmap(PIECE_SIZE, PIECE_SIZE);
	al_set_target_bitmap(ghost);

	if (full) {
		al_draw_bitmap(bmp, 0, 0, 0);
	}

	al_lock_bitmap(bmp, al_get_bitmap_format(bmp), ALLEGRO_LOCK_READONLY);
	al_lock_bitmap(ghost, al_get_bitmap_format(backbuffer), ALLEGRO_LOCK_READWRITE);

	int x;
	int y;
	for (y = 0; y<PIECE_SIZE ; y++) {
		for (x = 0; x<PIECE_SIZE; x++) {
			ALLEGRO_COLOR pixel = al_get_pixel(bmp, x, y);
			unsigned char r, g, b, a;
			al_unmap_rgba(pixel, &r, &g, &b, &a);
			if (a > 0) {
				al_draw_pixel(x, y, color);
			}
		}
	}

	al_unlock_bitmap(bmp);
	al_unlock_bitmap(ghost);
	al_set_target_bitmap(backbuffer);

	return ghost;
}

/*
 * Returns true if the current player is in check
 */
static bool is_in_check(GameState *state)
{
	bool in_check = false;
	short x, y;
	for (y = 0; y<8; y++) {
		for (x = 0; x<8; x++) {
			ChessPiece *current = state->board[y][x].piece;
			if (current == NULL) {
				continue;
			}

			if (state->turn != current->color) {
				GList *moves = get_valid_moves(&state->board, &state->board[y][x], true);
				GList *iter = moves;
				while (iter != NULL) {
					Square *move = (Square*)iter->data;
					if (move->piece != NULL && move->piece->color != current->color && move->piece->type == KING) {
						in_check = true;
					}

					iter = g_list_next(iter);
					if (in_check) {
						break;
					}
				}
			}

			if (in_check) {
				break;
			}
		}

		if (in_check) {
			break;
		}
	}

	return in_check;
}

/*
 * Tests whether or not the current player is in checkmate
 */
static bool is_checkmate(GameState *state)
{
	bool checkmate = true;
	short x, y;
	for (y = 0; y<8; y++) {
		for (x = 0; x<8; x++) {
			ChessPiece *moving_piece = state->board[y][x].piece;
			if (moving_piece == NULL) {
				continue;
			}

			if (state->turn == moving_piece->color) {
				GList *moves = get_valid_moves(&state->board, &state->board[y][x], true);
				GList *iter = moves;
				while (iter != NULL) {
					Square *move = (Square*)iter->data;
					ChessPiece *existing_piece = move->piece;

					move->piece = moving_piece;
					state->board[y][x].piece = NULL;
					if (!is_in_check(state)) {
						checkmate = false;
					}

					move->piece = existing_piece;
					state->board[y][x].piece = moving_piece;

					if (!checkmate) {
						break;
					}

					iter = g_list_next(iter);
				}
			}

			if (!checkmate) {
				break;
			}
		}

		if (!checkmate) {
			break;
		}
	}

	return checkmate;
}

/*
 * Checks if the piece on the currently selected square can move to the target
 * square or not
 */
static bool is_invalid_move(GameState *state, Square *target)
{
	ChessPiece *victim = target->piece;
	ChessPiece *attacker = state->selected_square->piece;
	target->piece = attacker;
	state->selected_square->piece = NULL;

	bool in_check = is_in_check(state);

	state->selected_square->piece = attacker;
	target->piece = victim;

	return in_check;
}

/*
 * Event handler for clicking on the board
 */
static void handle_click(GameState *state, Square *square)
{
	// if the selected square was clicked again, de-select it
	if (state->selected_square == square) {
		state->selected_square = NULL;
		g_list_free(threats);
		// ???: not sure why free'ing alone isn't enough, check for memory leaks
		threats = NULL;
	}
	// if we click one of our pieces, select it
	else if (square->piece != NULL && square->piece->color == state->turn) {
		state->selected_square = square;
		ALLEGRO_BITMAP *bmp = get_piece_bitmap(state, square->piece->type, square->piece->color);
		threat_ghost = draw_ghost(bmp, al_map_rgba(255, 0, 0, 0), true);
		threats = get_valid_moves(&state->board, square, false);
	}
	// if we clicked on a threatened square, move it
	else if (g_list_find(threats, square)) {
		// make sure this move won't put us in check
		if (is_invalid_move(state, square)) {
			printf("Can't move there, you're in check!\n");
			return;
		}

		if (square->piece != NULL) {
			al_free(square->piece);
		}

		ChessPiece *moving_piece = state->selected_square->piece;

		// check if this is a special move
		if (moving_piece->type == KING && !moving_piece->moved) {
			if (square->pos.x == (state->selected_square->pos.x - 2)) {
				Square *rook_square = &state->board[square->pos.y][0];
				(&state->board[square->pos.y][square->pos.x+1])->piece = rook_square->piece;
				rook_square->piece = NULL;
			} else if (square->pos.x == (state->selected_square->pos.x + 2)) {
				Square *rook_square = &state->board[square->pos.y][7];
				(&state->board[square->pos.y][square->pos.x-1])->piece = rook_square->piece;
				rook_square->piece = NULL;
			}
		}

		// disable first-move-only moves like castling
		moving_piece->moved = true;

		// do the move
		square->piece = moving_piece;
		state->selected_square->piece = NULL;
		state->selected_square = NULL;

		// check for promotion
		if (square->piece->type == PAWN && (square->pos.y == 0 || square->pos.y == 7)) {
			// TODO: prompt the player for a piece to promote to
			square->piece->type = QUEEN;
		}

		g_list_free(threats);
		threats = NULL;

		state->turn = !state->turn;

		state->in_check = is_in_check(state);
		if (state->in_check) {
			state->checkmate = is_checkmate(state);
			if (state->checkmate) {
				printf("CHECKMATE!!!\n");
			}
		}
	}
}

/*
 * foreach method for drawing threat ghosts
 */
static void draw_threat(void *data, void *user_data)
{
	Square *threat = (Square*)data;
	GameState *state = (GameState*)user_data;
	if (threat) {
		int px = state->board_position->x + (threat->pos.x * SQUARE_SIZE) + (SQUARE_SIZE - PIECE_SIZE)/2;
		int py = state->board_position->y + (threat->pos.y * SQUARE_SIZE) + (SQUARE_SIZE - PIECE_SIZE)/2;
		al_draw_bitmap(threat_ghost, px, py, 0);
	}
}

/*
 * Initialize the game
 */
void load_game(GameState *state)
{
	short y;
	short x;
	for (y = 0; y<8; y++) {
		for (x = 0; x<8; x++) {
			state->board[y][x].pos.x = x;
			state->board[y][x].pos.y = y;
			state->board[y][x].piece = NULL;
		}
	}

	state->board[0][0].piece = new_piece(ROOK,   BLACK);
	state->board[0][1].piece = new_piece(KNIGHT, BLACK);
	state->board[0][2].piece = new_piece(BISHOP, BLACK);
	state->board[0][3].piece = new_piece(QUEEN,  BLACK);
	state->board[0][4].piece = new_piece(KING,   BLACK);
	state->board[0][5].piece = new_piece(BISHOP, BLACK);
	state->board[0][6].piece = new_piece(KNIGHT, BLACK);
	state->board[0][7].piece = new_piece(ROOK,   BLACK);
	state->board[1][0].piece = new_piece(PAWN,   BLACK);
	state->board[1][1].piece = new_piece(PAWN,   BLACK);
	state->board[1][2].piece = new_piece(PAWN,   BLACK);
	state->board[1][3].piece = new_piece(PAWN,   BLACK);
	state->board[1][4].piece = new_piece(PAWN,   BLACK);
	state->board[1][5].piece = new_piece(PAWN,   BLACK);
	state->board[1][6].piece = new_piece(PAWN,   BLACK);
	state->board[1][7].piece = new_piece(PAWN,   BLACK);

	state->board[7][0].piece = new_piece(ROOK,   WHITE);
	state->board[7][1].piece = new_piece(KNIGHT, WHITE);
	state->board[7][2].piece = new_piece(BISHOP, WHITE);
	state->board[7][3].piece = new_piece(QUEEN,  WHITE);
	state->board[7][4].piece = new_piece(KING,   WHITE);
	state->board[7][5].piece = new_piece(BISHOP, WHITE);
	state->board[7][6].piece = new_piece(KNIGHT, WHITE);
	state->board[7][7].piece = new_piece(ROOK,   WHITE);
	state->board[6][0].piece = new_piece(PAWN,   WHITE);
	state->board[6][1].piece = new_piece(PAWN,   WHITE);
	state->board[6][2].piece = new_piece(PAWN,   WHITE);
	state->board[6][3].piece = new_piece(PAWN,   WHITE);
	state->board[6][4].piece = new_piece(PAWN,   WHITE);
	state->board[6][5].piece = new_piece(PAWN,   WHITE);
	state->board[6][6].piece = new_piece(PAWN,   WHITE);
	state->board[6][7].piece = new_piece(PAWN,   WHITE);

	state->board_position = NEW(Position);
	state->board_position->x = (state->screen_width  - (8*SQUARE_SIZE)) / 2;
	state->board_position->y = (state->screen_height - (8*SQUARE_SIZE)) / 2;

	state->turn = WHITE;
	state->in_check = false;
	state->checkmate = false;
}

/*
 * Main game loop, runs once per frame.
 */
void game_run()
{
}

void game_event(GameState *state, ALLEGRO_EVENT *event)
{
	short x;
	short y;

	switch (event->type) {
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			x = (short)floor((event->mouse.x - state->board_position->x) / SQUARE_SIZE);
			y = (short)floor((event->mouse.y - state->board_position->y) / SQUARE_SIZE);
			if (IN_BOUNDS(x,y)) {
				handle_click(state, &state->board[y][x]);
			}
			break;
		default:
			break;
	}
}

void game_redraw(GameState *state)
{
	short y;
	short x;
	short mx = (short)floor((state->mouse_x - state->board_position->x) / SQUARE_SIZE);
	short my = (short)floor((state->mouse_y - state->board_position->y) / SQUARE_SIZE);

	al_clear_to_color(al_map_rgb(100, 100, 0));
	al_draw_bitmap(get_board_bitmap(state), state->board_position->x, state->board_position->y, 0);

	for (y = 0; y<8; y++) {
		for (x = 0; x<8; x++) {
			ChessPiece *piece = state->board[y][x].piece;
			if (piece != NULL) {
				int piece_x = state->board_position->x + (x*SQUARE_SIZE) + (SQUARE_SIZE - PIECE_SIZE)/2;
				int piece_y = state->board_position->y + (y*SQUARE_SIZE) + (SQUARE_SIZE - PIECE_SIZE)/2;
				ALLEGRO_BITMAP *bmp = get_piece_bitmap(state, piece->type, piece->color);
				if (bmp) {
					al_draw_bitmap(bmp, piece_x, piece_y, 0);
					// highlight it?
					if (&state->board[y][x] == state->selected_square) {
						ALLEGRO_BITMAP *selected_ghost = draw_ghost(bmp, al_map_rgba(0, 255, 0, 0), false);
						al_draw_bitmap(selected_ghost, piece_x, piece_y, 0);
					} else if (piece->color == state->turn && state->selected_square == NULL && mx == x && my == y) {
						ALLEGRO_BITMAP *hover_ghost = draw_ghost(bmp, al_map_rgba(100, 100, 100, 0), false);
						al_draw_bitmap(hover_ghost, piece_x, piece_y, 0);
					}
				}
			}
		}
	}

	g_list_foreach(threats, draw_threat, state);

	char *turn_txt = (state->turn == WHITE ? "White" : "Black");
	ALLEGRO_COLOR turn_color = (state->turn == WHITE ? al_map_rgb(255, 255, 255) : al_map_rgb(0, 0, 0));
	al_draw_text(get_default_font(state), turn_color, state->board_position->x / 2, 50, ALLEGRO_ALIGN_CENTRE, turn_txt);
	if (state->in_check) {
		ALLEGRO_COLOR col = al_map_rgb(255, 0, 0);
		al_draw_text(get_default_font(state), col, state->board_position->x / 2, 75, ALLEGRO_ALIGN_CENTRE, "Check!");
	}

	al_flip_display();
}
