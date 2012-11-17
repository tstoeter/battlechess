#ifndef GAME_H
#define GAME_H

#include "data.h"
#include <allegro5/allegro.h>

void load_game(GameState *state);
void game_run(GameState *state);
void game_event(GameState *state, ALLEGRO_EVENT *event);
void game_redraw(GameState *state);

#endif
