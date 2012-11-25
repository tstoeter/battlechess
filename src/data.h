#ifndef DATA_H
#define DATA_H

#include <stdbool.h>
#include <allegro5/allegro.h>

#define NEW(x) (x*)g_malloc(sizeof(x))

#define SQUARE_SIZE  50
#define BORDER_WIDTH 25
#define PIECE_SIZE   36

typedef struct
{
	short x, y;
} Position;

typedef struct
{
	enum { BISHOP, KING, KNIGHT, PAWN, QUEEN, ROOK } type;
	enum { WHITE, BLACK } color;
	bool moved; /* whether or not the piece has moved yet */
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
	/* pointers to allegro state structs */
	ALLEGRO_MOUSE_STATE *mouse_state;

	/* useful globals */
	int screen_width;
	int screen_height;

	int turn;
	Square *selected_square;
	Square board[8][8];
	Position *board_position; /* where to draw the board on screen */

	bool in_check;
	bool checkmate;
	Square *en_passant; /* a square holding a pawn that can be captured via en passant */
} GameState;

#endif
