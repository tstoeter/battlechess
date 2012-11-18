#include "piece.h"

#include <glib.h>
#include <stdio.h>
#include "data.h"

/*
 * Initialize a new piece. Note that this must be freed manually.
 */
ChessPiece *new_piece(int type, int color)
{
	ChessPiece *piece = NEW(ChessPiece);
	piece->type = type;
	piece->color = color;
	piece->moved = false;
	return piece;
}

bool are_enemies(ChessPiece *p1, ChessPiece *p2)
{
	return p1->color != p2->color;
}

