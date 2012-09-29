#include <allegro5/allegro.h>

#define SQUARE_SIZE 30

ALLEGRO_BITMAP *black_square;
ALLEGRO_BITMAP *white_square;
ALLEGRO_BITMAP *board;

static void init_squares()
{
	if (black_square != NULL || white_square != NULL) {
		return;
	}

	// create the square bitmaps
	black_square = al_create_bitmap(SQUARE_SIZE, SQUARE_SIZE);
	white_square = al_create_bitmap(SQUARE_SIZE, SQUARE_SIZE);

	ALLEGRO_BITMAP *screen = al_get_target_bitmap();

	// draw the black one
	al_set_target_bitmap(black_square);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	// draw the white one
	al_set_target_bitmap(white_square);
	al_clear_to_color(al_map_rgb(255, 255, 255));

	// reset to the original
	al_set_target_bitmap(screen);
}

ALLEGRO_BITMAP *get_board_bitmap()
{
	if (board != NULL) {
		return board;
	}

	init_squares();
	board = al_create_bitmap(8*SQUARE_SIZE, 8*SQUARE_SIZE);

	ALLEGRO_BITMAP *screen = al_get_target_bitmap();

	al_set_target_bitmap(board);
	
	// TODO: check where the bitmap is drawn relative to
	al_draw_bitmap(white_square, 0*SQUARE_SIZE, 0*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 1*SQUARE_SIZE, 0*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 2*SQUARE_SIZE, 0*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 3*SQUARE_SIZE, 0*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 4*SQUARE_SIZE, 0*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 5*SQUARE_SIZE, 0*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 6*SQUARE_SIZE, 0*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 7*SQUARE_SIZE, 0*SQUARE_SIZE, 0);

	al_draw_bitmap(black_square, 0*SQUARE_SIZE, 1*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 1*SQUARE_SIZE, 1*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 2*SQUARE_SIZE, 1*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 3*SQUARE_SIZE, 1*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 4*SQUARE_SIZE, 1*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 5*SQUARE_SIZE, 1*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 6*SQUARE_SIZE, 1*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 7*SQUARE_SIZE, 1*SQUARE_SIZE, 0);

	al_draw_bitmap(white_square, 0*SQUARE_SIZE, 2*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 1*SQUARE_SIZE, 2*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 2*SQUARE_SIZE, 2*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 3*SQUARE_SIZE, 2*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 4*SQUARE_SIZE, 2*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 5*SQUARE_SIZE, 2*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 6*SQUARE_SIZE, 2*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 7*SQUARE_SIZE, 2*SQUARE_SIZE, 0);

	al_draw_bitmap(black_square, 0*SQUARE_SIZE, 3*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 1*SQUARE_SIZE, 3*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 2*SQUARE_SIZE, 3*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 3*SQUARE_SIZE, 3*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 4*SQUARE_SIZE, 3*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 5*SQUARE_SIZE, 3*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 6*SQUARE_SIZE, 3*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 7*SQUARE_SIZE, 3*SQUARE_SIZE, 0);

	al_draw_bitmap(white_square, 0*SQUARE_SIZE, 4*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 1*SQUARE_SIZE, 4*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 2*SQUARE_SIZE, 4*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 3*SQUARE_SIZE, 4*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 4*SQUARE_SIZE, 4*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 5*SQUARE_SIZE, 4*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 6*SQUARE_SIZE, 4*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 7*SQUARE_SIZE, 4*SQUARE_SIZE, 0);

	al_draw_bitmap(black_square, 0*SQUARE_SIZE, 5*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 1*SQUARE_SIZE, 5*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 2*SQUARE_SIZE, 5*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 3*SQUARE_SIZE, 5*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 4*SQUARE_SIZE, 5*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 5*SQUARE_SIZE, 5*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 6*SQUARE_SIZE, 5*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 7*SQUARE_SIZE, 5*SQUARE_SIZE, 0);

	al_draw_bitmap(white_square, 0*SQUARE_SIZE, 6*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 1*SQUARE_SIZE, 6*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 2*SQUARE_SIZE, 6*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 3*SQUARE_SIZE, 6*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 4*SQUARE_SIZE, 6*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 5*SQUARE_SIZE, 6*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 6*SQUARE_SIZE, 6*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 7*SQUARE_SIZE, 6*SQUARE_SIZE, 0);

	al_draw_bitmap(black_square, 0*SQUARE_SIZE, 7*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 1*SQUARE_SIZE, 7*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 2*SQUARE_SIZE, 7*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 3*SQUARE_SIZE, 7*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 4*SQUARE_SIZE, 7*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 5*SQUARE_SIZE, 7*SQUARE_SIZE, 0);
	al_draw_bitmap(black_square, 6*SQUARE_SIZE, 7*SQUARE_SIZE, 0);
	al_draw_bitmap(white_square, 7*SQUARE_SIZE, 7*SQUARE_SIZE, 0);

	// reset target bitmap
	al_set_target_bitmap(screen);
	return board;
}
