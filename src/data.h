#ifndef DATA_H
#define DATA_H

typedef struct
{
	short x, y;
} Position;

typedef struct
{
	enum {
		BISHOP,
		KING,
		KNIGHT,
		PAWN,
		QUEEN,
		ROOK
	} type;
	enum { WHITE, BLACK } color;
} ChessPiece;

typedef struct
{
	Position pos;
	ChessPiece *piece;
} Square;

#endif
