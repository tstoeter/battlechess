#include "piece.h"

bool are_enemies(ChessPiece *p1, ChessPiece *p2)
{
	return p1->color != p2->color;
}
