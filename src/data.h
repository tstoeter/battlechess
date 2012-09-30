#ifndef DATA_H
#define DATA_H

#define NEW(x) (x*)g_malloc(sizeof(x))

#define SQUARE_SIZE 50
#define PIECE_SIZE  36

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

enum GameState {
	PLAYING
};

int screen_width;
int screen_height;

int mouse_x;
int mouse_y;

#endif
