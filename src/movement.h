#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <glib.h>
#include "data.h"

GList *get_valid_moves(Square (*board)[8][8], short x, short y);

#endif
