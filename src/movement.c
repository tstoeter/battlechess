#include <glib.h>
#include <stdio.h>
#include <assert.h>

#include "game.h"
#include "piece.h"
#include "data.h"

static GList *get_valid_pawn_moves(Square (*board)[8][8], short _x, short _y)
{
	GList *results = NULL;
	ChessPiece *piece = (*board)[_y][_x].piece;
	assert(piece != NULL);
	short dir = (piece->color == WHITE ? -1 : 1);

	short x = _x;
	short y = _y + dir;

	if (IN_BOUNDS(x, y) && (*board)[y][x].piece == NULL) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x - 1;
	// can we attack the guy (if any) to the left?
	if (IN_BOUNDS(x,y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	// can we attack the guy (if any) to the right?
	x = _x + 1;
	if (IN_BOUNDS(x,y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	// if this pawn is in its starting position, it can move another space (provided it's empty)
	if (((piece->color == WHITE && _y == 6) || (piece->color == BLACK && _y == 1))) {
		y += dir;
		x = _x;
		if (IN_BOUNDS(x, y) && (*board)[y][x].piece == NULL) {
			results = g_list_prepend(results, &(*board)[y][x]);
		}
	}

	return results;
}

static GList *get_valid_rook_moves(Square (*board)[8][8], short _x, short _y)
{
	GList *results = NULL;
	ChessPiece *piece = (*board)[_y][_x].piece;
	assert(piece != NULL);

	short x = _x;
	short y = _y;

	// move right
	x = _x + 1;
	while (IN_BOUNDS(x,y) && (*board)[y][x].piece == NULL) {
		results = g_list_prepend(results, &(*board)[y][x]);
		x++;
	}

	if (IN_BOUNDS(x,y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	// move left
	x = _x - 1;
	while (IN_BOUNDS(x,y) && (*board)[y][x].piece == NULL) {
		results = g_list_prepend(results, &(*board)[y][x]);
		x--;
	}

	if (IN_BOUNDS(x,y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x;

	// move up
	y = _y - 1;
	while (IN_BOUNDS(x,y) && (*board)[y][x].piece == NULL) {
		results = g_list_prepend(results, &(*board)[y][x]);
		y--;
	}

	if (IN_BOUNDS(x,y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	// move down
	y = _y + 1;
	while (IN_BOUNDS(x,y) && (*board)[y][x].piece == NULL) {
		results = g_list_prepend(results, &(*board)[y][x]);
		y++;
	}

	if (IN_BOUNDS(x,y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	return results;
}

static GList *get_valid_knight_moves(Square (*board)[8][8], short _x, short _y)
{
	GList *results = NULL;
	ChessPiece *piece = (*board)[_y][_x].piece;
	assert(piece != NULL);

	short x = _x;
	short y = _y;

	x = _x + 1;
	y = _y - 2;
	if (IN_BOUNDS(x,y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	y = _y + 2;
	if (IN_BOUNDS(x,y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x - 1;
	y = _y - 2;
	if (IN_BOUNDS(x,y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	y = _y + 2;
	if (IN_BOUNDS(x,y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}
	
	x = _x + 2;
	y = _y - 1;
	if (IN_BOUNDS(x,y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	y = _y + 1;
	if (IN_BOUNDS(x,y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x - 2;
	y = _y - 1;
	if (IN_BOUNDS(x,y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	y = _y + 1;
	if (IN_BOUNDS(x,y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	return results;
}

static GList *get_valid_bishop_moves(Square (*board)[8][8], short _x, short _y)
{
	GList *results = NULL;
	ChessPiece *piece = (*board)[_y][_x].piece;
	assert(piece != NULL);

	short x = _x;
	short y = _y;

	// up-right
	x = _x + 1;
	y = _y - 1;
	while (IN_BOUNDS(x,y) && (*board)[y][x].piece == NULL) {
		results = g_list_prepend(results, &(*board)[y][x]);
		x++;
		y--;
	}

	if (IN_BOUNDS(x,y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	// up-left
	x = _x - 1;
	y = _y - 1;
	while (IN_BOUNDS(x,y) && (*board)[y][x].piece == NULL) {
		results = g_list_prepend(results, &(*board)[y][x]);
		x--;
		y--;
	}

	if (IN_BOUNDS(x,y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	// down-right
	x = _x + 1;
	y = _y + 1;
	while (IN_BOUNDS(x,y) && (*board)[y][x].piece == NULL) {
		results = g_list_prepend(results, &(*board)[y][x]);
		x++;
		y++;
	}

	if (IN_BOUNDS(x,y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	// down-left
	x = _x - 1;
	y = _y + 1;
	while (IN_BOUNDS(x,y) && (*board)[y][x].piece == NULL) {
		results = g_list_prepend(results, &(*board)[y][x]);
		x--;
		y++;
	}

	if (IN_BOUNDS(x,y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	return results;
}

static GList *get_valid_queen_moves(Square (*board)[8][8], short _x, short _y)
{
	return g_list_concat(get_valid_rook_moves(board, _x, _y),
			             get_valid_bishop_moves(board, _x, _y));
}

// NOTE: this doesn't take checking into account
static GList *get_valid_king_moves(Square (*board)[8][8], short _x, short _y)
{
	GList *results = NULL;
	ChessPiece *piece = (*board)[_y][_x].piece;
	assert(piece != NULL);

	short x = _x;
	short y = _y;

	x = _x - 1;
	y = _y - 1;
	if (IN_BOUNDS(x, y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x;
	y = _y - 1;
	if (IN_BOUNDS(x, y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x + 1;
	y = _y - 1;
	if (IN_BOUNDS(x, y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x - 1;
	y = _y;
	if (IN_BOUNDS(x, y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x;
	y = _y;
	if (IN_BOUNDS(x, y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x + 1;
	y = _y;
	if (IN_BOUNDS(x, y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x - 1;
	y = _y + 1;
	if (IN_BOUNDS(x, y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x;
	y = _y + 1;
	if (IN_BOUNDS(x, y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	x = _x + 1;
	y = _y + 1;
	if (IN_BOUNDS(x, y) && ((*board)[y][x].piece == NULL || are_enemies(piece, (*board)[y][x].piece))) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	return results;
}

/*
 * Get a list of valid moves.
 */
GList *get_valid_moves(Square (*board)[8][8], Square *square, bool checking)
{
	GList *moves = NULL;
	ChessPiece *king = NULL;
	short x, y;

	switch (square->piece->type)
	{
		case PAWN:
			return get_valid_pawn_moves(board, square->pos.x, square->pos.y);
		case ROOK:
			return get_valid_rook_moves(board, square->pos.x, square->pos.y);
		case KNIGHT:
			return get_valid_knight_moves(board, square->pos.x, square->pos.y);
		case BISHOP:
			return get_valid_bishop_moves(board, square->pos.x, square->pos.y);
		case QUEEN:
			return get_valid_queen_moves(board, square->pos.x, square->pos.y);
		case KING:
			moves = get_valid_king_moves(board, square->pos.x, square->pos.y);
			if (checking) {
				return moves;
			}

			// since we're moving the king, make sure no move would put it in check
			king = square->piece;
			square->piece = NULL;

			// iterate through each of the possible moves, maintaining a separate list
			// of which ones are threatened
			GList *threats = NULL;
			GList *move = moves;
			while (move != NULL) {
				// for each move, move the king over and see if any piece is attacking it
				bool done = false;
				ChessPiece *existing = ((Square*)move->data)->piece;
				((Square*)move->data)->piece = king;
				for (y = 0; y<8; y++) {
					for (x = 0; x<8; x++) {
						Square *s = &(*board)[y][x];
						if (s->piece != NULL && are_enemies(s->piece, king)) {
							GList *attacks = get_valid_moves(board, s, true);
							if (g_list_find(attacks, move->data)) {
								// this move was threatened, so add it to the threats and break out
								threats = g_list_prepend(threats, move->data);
								done = true;
							}
						}
					}

					if (done)
						break;
				}

				((Square*)move->data)->piece = existing;
				move = g_list_next(move);
			}

			GList *threat = threats;
			while (threat != NULL) {
				moves = g_list_remove(moves, threat->data);
				threat = g_list_next(threat);
			}

			g_list_free(threats);
			square->piece = king;
			return moves;
		default:
			fprintf(stderr, "error: unrecognized piece type: %d\n", square->piece->type);
			return NULL;
	}
}
