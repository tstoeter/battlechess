#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <glib.h>
#include "data.h"

GList *get_valid_moves(GameState *state, Square (*board)[8][8], Square *square, bool checking);

#endif
