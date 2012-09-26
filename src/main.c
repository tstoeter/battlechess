#include <stdio.h>
#include <glib.h>
#include <allegro5/allegro.h>

#define NEW(x) (x*)g_malloc(sizeof(x))

const short board_width  = 8;
const short board_height = 8;

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
	Position pos;
	bool alive;
} ChessPiece;

/*
 * Initialize a new piece. Note that this must be freed manually.
 */
ChessPiece *new_piece(int type, int color, int x, int y)
{
	ChessPiece *piece = NEW(ChessPiece);
	piece->pos.x = x;
	piece->pos.y = y;
	piece->type = type;
	piece->color = color;
	piece->alive = 1;
	return piece;
}

/*
 * Creates a list of chess pieces in the default starting configuration.
 */
GList *init_pieces()
{
	GList *pieces = NULL;
	// TODO: verify the position of knight/queen
	pieces = g_list_prepend(pieces, new_piece(ROOK, WHITE, 0, 0));
	pieces = g_list_prepend(pieces, new_piece(KNIGHT, WHITE, 1, 0));
	pieces = g_list_prepend(pieces, new_piece(BISHOP, WHITE, 2, 0));
	pieces = g_list_prepend(pieces, new_piece(QUEEN, WHITE, 3, 0));
	pieces = g_list_prepend(pieces, new_piece(KING, WHITE, 4, 0));
	pieces = g_list_prepend(pieces, new_piece(BISHOP, WHITE, 5, 0));
	pieces = g_list_prepend(pieces, new_piece(KNIGHT, WHITE, 6, 0));
	pieces = g_list_prepend(pieces, new_piece(ROOK, WHITE, 7, 0));
	pieces = g_list_prepend(pieces, new_piece(PAWN, WHITE, 0, 1));
	pieces = g_list_prepend(pieces, new_piece(PAWN, WHITE, 1, 1));
	pieces = g_list_prepend(pieces, new_piece(PAWN, WHITE, 2, 1));
	pieces = g_list_prepend(pieces, new_piece(PAWN, WHITE, 3, 1));
	pieces = g_list_prepend(pieces, new_piece(PAWN, WHITE, 4, 1));
	pieces = g_list_prepend(pieces, new_piece(PAWN, WHITE, 5, 1));
	pieces = g_list_prepend(pieces, new_piece(PAWN, WHITE, 6, 1));
	pieces = g_list_prepend(pieces, new_piece(PAWN, WHITE, 7, 1));

	pieces = g_list_prepend(pieces, new_piece(ROOK, BLACK, 0, 6));
	pieces = g_list_prepend(pieces, new_piece(KNIGHT, BLACK, 1, 6));
	pieces = g_list_prepend(pieces, new_piece(BISHOP, BLACK, 2, 6));
	pieces = g_list_prepend(pieces, new_piece(KING, BLACK, 3, 6));
	pieces = g_list_prepend(pieces, new_piece(QUEEN, BLACK, 4, 6));
	pieces = g_list_prepend(pieces, new_piece(BISHOP, BLACK, 5, 6));
	pieces = g_list_prepend(pieces, new_piece(KNIGHT, BLACK, 6, 6));
	pieces = g_list_prepend(pieces, new_piece(PAWN, BLACK, 0, 6));
	pieces = g_list_prepend(pieces, new_piece(PAWN, BLACK, 1, 6));
	pieces = g_list_prepend(pieces, new_piece(PAWN, BLACK, 2, 6));
	pieces = g_list_prepend(pieces, new_piece(PAWN, BLACK, 3, 6));
	pieces = g_list_prepend(pieces, new_piece(PAWN, BLACK, 4, 6));
	pieces = g_list_prepend(pieces, new_piece(PAWN, BLACK, 5, 6));
	pieces = g_list_prepend(pieces, new_piece(PAWN, BLACK, 6, 6));
	pieces = g_list_prepend(pieces, new_piece(PAWN, BLACK, 7, 6));

	return pieces;
}

/*
 * Convenience function for creating lists of positions.
 */
GList *g_list_add_pos(GList *list, short x, short y)
{
	Position *pos = NEW(Position);
	pos->x = x;
	pos->y = y;
	return g_list_prepend(list, pos);
}

/*
 * Gets the piece at the given position, or NULL if there is none.
 */
ChessPiece *get_piece_for_pos(GList *pieces, short x, short y)
{
	while (pieces != NULL) {
		ChessPiece *piece = (ChessPiece*)pieces->data;
		if (piece->pos.x == x && piece->pos.y == y) {
			return piece;
		} else {
			pieces = g_list_next(pieces);
		}
	}

	return NULL;
}

GList *get_valid_pawn_moves(GList *pieces, ChessPiece *pawn)
{
	GList *moves = NULL;
	short dir = (pawn->color == WHITE ? 1 : -1);

	short x = pawn->pos.x;
	short y = pawn->pos.y;

	y += dir;
	if (get_piece_for_pos(pieces, x, y) == NULL) {
		moves = g_list_add_pos(moves, x, y);
	}

	if ((pawn->color == WHITE && pawn->pos.y == 1) || (pawn->color == BLACK && pawn->pos.y == 6)) {
		y += dir;
		if (get_piece_for_pos(pieces, x, y) == NULL) {
			moves = g_list_add_pos(moves, x, y);
		}
	}

	x = pawn->pos.x - 1;
	y = pawn->pos.y + dir;
	ChessPiece *enemy = get_piece_for_pos(pieces, x, y);
	if (enemy != NULL && pawn->color != enemy->color) {
		moves = g_list_add_pos(moves, x, y);
	}

	x = pawn->pos.x + 1;
	enemy = get_piece_for_pos(pieces, x, y);
	if (enemy != NULL && pawn->color != enemy->color) {
		moves = g_list_add_pos(moves, x, y);
	}
	
	return moves;
}

/*
 * Returns a list of Positions indicating all of the piece's valid moves.
 */
GList *get_valid_moves(GList *pieces, ChessPiece *p)
{
	switch (p->type) {
		case PAWN:
			return get_valid_pawn_moves(pieces, p);
		default:
			printf("Error, move not yet implemented.\n");
			return NULL;
	}
}

int main(int argc, char *argv[])
{
	GList *pieces = init_pieces();
	
	// clean up
	g_list_free_full(pieces, &g_free);
	return 0;
}
