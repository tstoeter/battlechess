#ifndef GAME_H
#define GAME_H

#include "data.h"
#include <allegro5/allegro.h>

int board_x;
int board_y;

Square board[8][8];

void load_game();
void game_run();
void game_event(ALLEGRO_EVENT *event);
void game_redraw();

void test();

#endif
