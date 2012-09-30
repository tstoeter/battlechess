#include <glib.h>
#include <stdio.h>

#include "game.h"
#include "piece.h"
#include "data.h"

static GList *get_valid_pawn_moves(Square (*board)[8][8], short _x, short _y, bool check)
{
	GList *results = NULL;
	ChessPiece *piece = (*board)[_y][_x].piece;
	short dir = (piece->color == WHITE ? 1 : -1);

	short x = _x;
	short y = _y + dir;

	if (IN_BOUNDS(x, y) && (*board)[y][x].piece == NULL && !check) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	// can we attack the guy (if any) to the left?
	x = _x - 1;
	if (check) {
		results = g_list_prepend(results, &(*board)[y][x]);
	} else if (IN_BOUNDS(x, y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	// can we attack the guy (if any) to the right?
	x = _x + 1;
	if (check) {
		results = g_list_prepend(results, &(*board)[y][x]);
	} else if (IN_BOUNDS(x, y) && (*board)[y][x].piece != NULL && are_enemies(piece, (*board)[y][x].piece)) {
		results = g_list_prepend(results, &(*board)[y][x]);
	}

	// if this pawn is in its starting position, it can move another space (provided it's empty)
	if (!check && ((piece->color == WHITE && _y == 1) || (piece->color == BLACK && _y == 6))) {
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
 * Used to remove threatened location from a King's list of valid moves.
 */
static void remove_threats(gpointer data, gpointer user_data)
{
	Square *threat = (Square*)data;
	GList *moves = (GList*)user_data;
	moves = g_list_remove(moves, threat);
}

/*
 * Get a list of valid moves.
 */
GList *get_valid_moves(Square (*board)[8][8], Square *square, bool check)
{
	if (square->piece == NULL) {
		//fprintf(stderr, "error: no piece at (%d,%d)\n", square->pos.x, square->pos.y);
		return NULL;
	}

	GList *moves = NULL;

	switch (square->piece->type)
	{
		case PAWN:
			return get_valid_pawn_moves(board, square->pos.x, square->pos.y, check);
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
			// since we're the king, prevent movements into check
			if (!check) {
				GList *threats = NULL;
				short x;
				short y;
				for (y = 0; y<8; y++) {
					for (x = 0; x<8; x++) {
						if ((*board)[y][x].piece != NULL && are_enemies(square->piece, (*board)[y][x].piece)) {
							threats = g_list_concat(threats, get_valid_moves(board, &(*board)[y][x], true));
						}
					}
				}

				g_list_foreach(threats, &remove_threats, moves);
			}
			return moves;
		default:
			fprintf(stderr, "error: unrecognized piece type: %d\n", square->piece->type);
			return NULL;
	}
}
