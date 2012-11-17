#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "data.h"

void init_graphics(GameState *state);
ALLEGRO_BITMAP *get_board_bitmap(GameState *state);
ALLEGRO_BITMAP *get_black_square_bitmap(GameState *state);
ALLEGRO_BITMAP *get_white_square_bitmap(GameState *state);
ALLEGRO_BITMAP *get_square_highlight_bitmap(GameState *state);
ALLEGRO_BITMAP *get_piece_bitmap(GameState *state, int piece, int color);
ALLEGRO_FONT *get_default_font(GameState *state);

#endif
