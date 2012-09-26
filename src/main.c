#include <stdio.h>
#include <glib.h>
#include <allegro5/allegro.h>

#define NEW(x) (x*)g_malloc(sizeof(x))

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

/*
 * Initialize a new piece. Note that this must be freed manually.
 */
ChessPiece *new_piece(int type, int color)
{
	ChessPiece *piece = NEW(ChessPiece);
	piece->type = type;
	piece->color = color;
	return piece;
}

int main(int argc, char *argv[])
{
	Square board[8][8];
	short y, x;
	for (y = 0; y<board_height; y++) {
		for (x = 0; x<board_width; x++) {
			board[y][x] = NEW(Square);
			board[y][x]->pos.x = x;
			board[y][x]->pos.y = y;
			board[y][x]->piece = NULL;
		}
	}

	return 0;
}
