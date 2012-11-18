#ifndef DATA_H
#define DATA_H

#include <stdbool.h>

#define NEW(x) (x*)g_malloc(sizeof(x))

#define SQUARE_SIZE 50
#define PIECE_SIZE  36

typedef struct
{
	short x, y;
} Position;

typedef struct
{
	enum { BISHOP, KING, KNIGHT, PAWN, QUEEN, ROOK } type;
	enum { WHITE, BLACK } color;
} ChessPiece;

typedef struct
{
	Position pos;
	ChessPiece *piece;
} Square;

typedef struct
{
	Square *square;
	bool threatened;
} SquareThreat;

typedef struct
{
	/* useful globals */
	int screen_width;
	int screen_height;
	int mouse_x;
	int mouse_y;

	int turn;
	Square *selected_square;
	Square board[8][8];
	Position *board_position; /* where to draw the board */

	bool in_check;
	bool checkmate;
} GameState;

#endif
