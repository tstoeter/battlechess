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
static Square 			*selected_square;
static ALLEGRO_BITMAP 	*threat_ghost;
static int 				turn;

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

static void handle_click(Square *square)
{
	// if the selected square was clicked again, de-select it
	if (selected_square == square) {
		selected_square = NULL;
		g_list_free(threats);
		// ???: not sure why free'ing alone isn't enough, check for memory leaks
		threats = NULL;
	}
	// if we click one of our pieces, select it
	else if (square->piece != NULL && square->piece->color == turn) {
		selected_square = square;
		ALLEGRO_BITMAP *bmp = get_piece_bitmap(square->piece->type, square->piece->color);
		threat_ghost = draw_ghost(bmp, al_map_rgba(255, 0, 0, 0), true);
		threats = get_valid_moves(&board, square, false);
	}
	// if we clicked on a threatened square, move it
	else if (g_list_find(threats, square)) {
		if (square->piece != NULL) {
			al_free(square->piece);
		}
		square->piece = selected_square->piece;
		selected_square->piece = NULL;
		selected_square = NULL;
		g_list_free(threats);
		threats = NULL;
		turn = !turn;
	}
}

/*
 * foreach method for drawing threat ghosts
 */
static void draw_threat(gpointer data, gpointer user_data)
{
	Square *threat = (Square*)data;
	if (threat) {
		int px = board_x + (threat->pos.x * SQUARE_SIZE) + (SQUARE_SIZE - PIECE_SIZE)/2;
		int py = board_y + (threat->pos.y * SQUARE_SIZE) + (SQUARE_SIZE - PIECE_SIZE)/2;
		al_draw_bitmap(threat_ghost, px, py, 0);
	}
}

/*
 * Initialize the game
 */
void load_game()
{
	short y;
	short x;
	for (y = 0; y<8; y++) {
		for (x = 0; x<8; x++) {
			board[y][x].pos.x = x;
			board[y][x].pos.y = y;
			board[y][x].piece = NULL;
		}
	}

	// TODO: verify the positions of the queen and king
	board[0][0].piece = new_piece(ROOK,   WHITE);
	board[0][1].piece = new_piece(KNIGHT, WHITE);
	board[0][2].piece = new_piece(BISHOP, WHITE);
	board[0][3].piece = new_piece(QUEEN,  WHITE);
	board[0][4].piece = new_piece(KING,   WHITE);
	board[0][5].piece = new_piece(BISHOP, WHITE);
	board[0][6].piece = new_piece(KNIGHT, WHITE);
	board[0][7].piece = new_piece(ROOK,   WHITE);
	board[1][0].piece = new_piece(PAWN,   WHITE);
	board[1][1].piece = new_piece(PAWN,   WHITE);
	board[1][2].piece = new_piece(PAWN,   WHITE);
	board[1][3].piece = new_piece(PAWN,   WHITE);
	board[1][4].piece = new_piece(PAWN,   WHITE);
	board[1][5].piece = new_piece(PAWN,   WHITE);
	board[1][6].piece = new_piece(PAWN,   WHITE);
	board[1][7].piece = new_piece(PAWN,   WHITE);

	board[7][0].piece = new_piece(ROOK,   BLACK);
	board[7][1].piece = new_piece(KNIGHT, BLACK);
	board[7][2].piece = new_piece(BISHOP, BLACK);
	board[7][3].piece = new_piece(KING,   BLACK);
	board[7][4].piece = new_piece(QUEEN,  BLACK);
	board[7][5].piece = new_piece(BISHOP, BLACK);
	board[7][6].piece = new_piece(KNIGHT, BLACK);
	board[7][7].piece = new_piece(ROOK,   BLACK);
	board[6][0].piece = new_piece(PAWN,   BLACK);
	board[6][1].piece = new_piece(PAWN,   BLACK);
	board[6][2].piece = new_piece(PAWN,   BLACK);
	board[6][3].piece = new_piece(PAWN,   BLACK);
	board[6][4].piece = new_piece(PAWN,   BLACK);
	board[6][5].piece = new_piece(PAWN,   BLACK);
	board[6][6].piece = new_piece(PAWN,   BLACK);
	board[6][7].piece = new_piece(PAWN,   BLACK);

	board_x = (screen_width  - (8*SQUARE_SIZE)) / 2;
	board_y = (screen_height - (8*SQUARE_SIZE)) / 2;

	turn = WHITE;
}

/*
 * Main game loop, runs once per frame.
 */
void game_run()
{
}

void game_event(ALLEGRO_EVENT *event)
{
	short x;
	short y;

	switch (event->type) {
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			x = (short)floor((event->mouse.x - board_x) / SQUARE_SIZE);
			y = (short)floor((event->mouse.y - board_y) / SQUARE_SIZE);
			if (IN_BOUNDS(x,y)) {
				handle_click(&board[y][x]);
			}
			break;
		default:
			break;
	}
}

void game_redraw()
{
	short y;
	short x;
	short mx = (short)floor((mouse_x - board_x) / SQUARE_SIZE);
	short my = (short)floor((mouse_y - board_y) / SQUARE_SIZE);

	al_clear_to_color(al_map_rgb(100, 100, 0));
	al_draw_bitmap(get_board_bitmap(), board_x, board_y, 0);

	for (y = 0; y<8; y++) {
		for (x = 0; x<8; x++) {
			ChessPiece *piece = board[y][x].piece;
			if (piece != NULL) {
				int piece_x = board_x + (x*SQUARE_SIZE) + (SQUARE_SIZE - PIECE_SIZE)/2;
				int piece_y = board_y + (y*SQUARE_SIZE) + (SQUARE_SIZE - PIECE_SIZE)/2;
				ALLEGRO_BITMAP *bmp = get_piece_bitmap(piece->type, piece->color);
				if (bmp) {
					al_draw_bitmap(bmp, piece_x, piece_y, 0);
					// highlight it?
					if (&board[y][x] == selected_square) {
						ALLEGRO_BITMAP *selected_ghost = draw_ghost(bmp, al_map_rgba(0, 255, 0, 0), false);
						al_draw_bitmap(selected_ghost, piece_x, piece_y, 0);
					} else if (piece->color == turn && selected_square == NULL && mx == x && my == y) {
						ALLEGRO_BITMAP *hover_ghost = draw_ghost(bmp, al_map_rgba(100, 100, 100, 0), false);
						al_draw_bitmap(hover_ghost, piece_x, piece_y, 0);
					}
				}
			}
		}
	}

	g_list_foreach(threats, draw_threat, NULL);
	al_flip_display();
}
