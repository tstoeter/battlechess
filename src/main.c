#include <stdio.h>
#include <glib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "board.h"
#include "movement.h"

#define FPS 60
#define NEW(x) (x*)g_malloc(sizeof(x))

/*
 * Initialize a new piece. Note that this must be freed manually.
 */
ChessPiece *new_piece(int type, int color)
{
	ChessPiece *piece = NEW(ChessPiece);
	piece->type = type;
	piece->color = color;
	return piece;
}

void clear_board(Square (*board)[8][8])
{
	short y;
	short x;
	for (y = 0; y<8; y++) {
		for (x = 0; x<8; x++) {
			if (board[y][x]->piece != NULL) {
				al_free(board[y][x]->piece);
			}
			board[y][x]->piece = NULL;
		}
	}
}

/*
 * Initialize a board and place the pieces down.
 * Note: be sure to clear the board before re-initializing it.
 */
void init_board(Square (*board)[8][8])
{
	short y;
	short x;
	for (y = 0; y<8; y++) {
		for (x = 0; x<8; x++) {
			board[y][x]->pos.x = 0;
			board[y][x]->pos.y = 0;
			board[y][x]->piece = NULL;
		}
	}

	// TODO: verify the positions of the queen and king
	board[0][0]->piece = new_piece(ROOK,   WHITE);
	board[0][1]->piece = new_piece(KNIGHT, WHITE);
	board[0][2]->piece = new_piece(BISHOP, WHITE);
	board[0][3]->piece = new_piece(QUEEN,  WHITE);
	board[0][4]->piece = new_piece(KING,   WHITE);
	board[0][5]->piece = new_piece(BISHOP, WHITE);
	board[0][6]->piece = new_piece(KNIGHT, WHITE);
	board[0][7]->piece = new_piece(ROOK,   WHITE);
	board[1][0]->piece = new_piece(PAWN,   WHITE);
	board[1][1]->piece = new_piece(PAWN,   WHITE);
	board[1][2]->piece = new_piece(PAWN,   WHITE);
	board[1][3]->piece = new_piece(PAWN,   WHITE);
	board[1][4]->piece = new_piece(PAWN,   WHITE);
	board[1][5]->piece = new_piece(PAWN,   WHITE);
	board[1][6]->piece = new_piece(PAWN,   WHITE);
	board[1][7]->piece = new_piece(PAWN,   WHITE);

	board[7][0]->piece = new_piece(ROOK,   BLACK);
	board[7][1]->piece = new_piece(KNIGHT, BLACK);
	board[7][2]->piece = new_piece(BISHOP, BLACK);
	board[7][3]->piece = new_piece(KING,   BLACK);
	board[7][4]->piece = new_piece(QUEEN,  BLACK);
	board[7][5]->piece = new_piece(BISHOP, BLACK);
	board[7][6]->piece = new_piece(KNIGHT, BLACK);
	board[7][7]->piece = new_piece(ROOK,   BLACK);
	board[6][0]->piece = new_piece(PAWN,   BLACK);
	board[6][1]->piece = new_piece(PAWN,   BLACK);
	board[6][2]->piece = new_piece(PAWN,   BLACK);
	board[6][3]->piece = new_piece(PAWN,   BLACK);
	board[6][4]->piece = new_piece(PAWN,   BLACK);
	board[6][5]->piece = new_piece(PAWN,   BLACK);
	board[6][6]->piece = new_piece(PAWN,   BLACK);
	board[6][7]->piece = new_piece(PAWN,   BLACK);
}

int main(int argc, char *argv[])
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	//ALLEGRO_KEYBOARD_STATE keyboard_state;

	bool running = true;
	bool redraw = true;

	int screen_width = 640;
	int screen_height = 480;

	//{{{ initialization
	
	// Initialize allegro
	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro.\n");
		return 1;
	}

	// Initialize allegro_image addon
	if (!al_init_image_addon()) {
		fprintf(stderr, "Failed to initialize image addon.\n");
		return 1;
	}

	// Initialize the timer
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "Failed to create timer.\n");
		return 1;
	}

	// Install the keyboard
	if (!al_install_keyboard()) {
		fprintf(stderr, "Failed to install keyboard.\n");
		return 1;
	}

	// Create the display
	display = al_create_display(screen_width, screen_height);
	if (!display) {
		fprintf(stderr, "Failed to create display.\n");
		return 1;
	} else {
		al_set_window_title(display, "Hello Tiled!");
	}

	// Create the event queue
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "Failed to create event queue.\n");
		return 1;
	}

	// Register event sources
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	//}}}
	
	// Start the timer
	al_start_timer(timer);

	ALLEGRO_EVENT event;
	ALLEGRO_TIMEOUT	timeout;
	al_init_timeout(&timeout, 0.06);

	al_clear_to_color(al_map_rgb(100, 100, 100));
	al_flip_display();

	// Main loop
	while (running) {
		// Fetch the event (if one exists)
		bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
		if (get_event) {
			switch (event.type) {
				case ALLEGRO_EVENT_TIMER:
					// process logic
					redraw = true;
					break;
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					running = false;
					break;
				default:
					// fprintf(stderr, "unsupported event received: %d\n", event.type);
					break;
			}
		}

		if (!running) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			al_clear_to_color(al_map_rgb(100, 100, 0));
			al_draw_bitmap(get_board_bitmap(), 10, 10, 0);
			al_flip_display();
		}
	}
}
