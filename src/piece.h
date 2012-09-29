#ifndef PIECE_H
#define PIECE_H

#include <stdbool.h>
#include "data.h"

#define IN_BOUNDS(x,y) (x>-1 && x<8 && y>-1 && y<8)

bool are_enemies(ChessPiece *p1, ChessPiece *p2);

#endif
