#include <glib.h>
#include <stdio.h>

#include "piece.h"
#include "data.h"

static GList *get_valid_pawn_moves(Square (*board)[8][8], short _x, short _y)
{
	GList *results = NULL;
	ChessPiece *piece = board[_y][_x]->piece;
	short dir = (piece->color == WHITE ? 1 : -1);

	short x = _x;
	short y = _y + dir;

	if (IN_BOUNDS(x, y) && board[y][x]->piece == NULL) {
		results = g_list_prepend(results, board[y][x]);
	}

	// can we attack the guy (if any) to the left?
	x = _x - 1;
	if (IN_BOUNDS(x, y) && board[y][x]->piece != NULL && are_enemies(piece, board[y][x]->piece)) {
		results = g_list_prepend(results, board[y][x]);
	}

	// can we attack the guy (if any) to the right?
	x = _x + 1;
	if (IN_BOUNDS(x, y) && board[y][x]->piece != NULL && are_enemies(piece, board[y][x]->piece)) {
		results = g_list_prepend(results, board[y][x]);
	}

	// if this pawn is in its starting position, it can move another space (provided it's empty)
	if ((piece->color == WHITE && _y == 1) || (piece->color == BLACK && _y == 6)) {
		y += dir;
		if (IN_BOUNDS(x, y) && board[y][x]->piece == NULL) {
			results = g_list_prepend(results, board[y][x]);
		}
	}

	return results;
}

static GList *get_valid_rook_moves(Square (*board)[8][8], short _x, short _y)
{
	GList *results = NULL;
	ChessPiece *piece = board[_y][_x]->piece;

	short x = _x;
	short y = _y;

	// move right
	x = _x + 1;
	while (IN_BOUNDS(x,y) && board[y][x]->piece == NULL) {
		results = g_list_prepend(results, board[y][x]);
		x++;
	}

	if (IN_BOUNDS(x,y) && board[y][x]->piece != NULL && are_enemies(piece, board[y][x]->piece)) {
		results = g_list_prepend(results, board[y][x]);
	}

	// move left
	x = _x - 1;
	while (IN_BOUNDS(x,y) && board[y][x]->piece == NULL) {
		results = g_list_prepend(results, board[y][x]);
		x--;
	}

	if (IN_BOUNDS(x,y) && board[y][x]->piece != NULL && are_enemies(piece, board[y][x]->piece)) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x;

	// move up
	y = _y - 1;
	while (IN_BOUNDS(x,y) && board[y][x]->piece == NULL) {
		results = g_list_prepend(results, board[y][x]);
		y--;
	}

	if (IN_BOUNDS(x,y) && board[y][x]->piece != NULL && are_enemies(piece, board[y][x]->piece)) {
		results = g_list_prepend(results, board[y][x]);
	}

	// move down
	y = _y + 1;
	while (IN_BOUNDS(x,y) && board[y][x]->piece == NULL) {
		results = g_list_prepend(results, board[y][x]);
		y++;
	}

	if (IN_BOUNDS(x,y) && board[y][x]->piece != NULL && are_enemies(piece, board[y][x]->piece)) {
		results = g_list_prepend(results, board[y][x]);
	}

	return results;
}

static GList *get_valid_knight_moves(Square (*board)[8][8], short _x, short _y)
{
	GList *results = NULL;
	ChessPiece *piece = board[_y][_x]->piece;

	short x = _x;
	short y = _y;

	x = _x + 1;
	y = _y - 2;
	if (IN_BOUNDS(x,y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	y = _y + 2;
	if (IN_BOUNDS(x,y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x - 1;
	y = _y - 2;
	if (IN_BOUNDS(x,y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	y = _y + 2;
	if (IN_BOUNDS(x,y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}
	
	x = _x + 2;
	y = _y - 1;
	if (IN_BOUNDS(x,y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	y = _y + 1;
	if (IN_BOUNDS(x,y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x - 2;
	y = _y - 1;
	if (IN_BOUNDS(x,y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	y = _y + 1;
	if (IN_BOUNDS(x,y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	return results;
}

static GList *get_valid_bishop_moves(Square (*board)[8][8], short _x, short _y)
{
	GList *results = NULL;
	ChessPiece *piece = board[_y][_x]->piece;

	short x = _x;
	short y = _y;

	// up-right
	x = _x + 1;
	y = _y - 1;
	while (IN_BOUNDS(x,y) && board[y][x]->piece == NULL) {
		results = g_list_prepend(results, board[y][x]);
		x++;
		y--;
	}

	if (IN_BOUNDS(x,y) && board[y][x]->piece != NULL && are_enemies(piece, board[y][x]->piece)) {
		results = g_list_prepend(results, board[y][x]);
	}

	// up-left
	x = _x - 1;
	y = _y - 1;
	while (IN_BOUNDS(x,y) && board[y][x]->piece == NULL) {
		results = g_list_prepend(results, board[y][x]);
		x--;
		y--;
	}

	if (IN_BOUNDS(x,y) && board[y][x]->piece != NULL && are_enemies(piece, board[y][x]->piece)) {
		results = g_list_prepend(results, board[y][x]);
	}

	// down-right
	x = _x + 1;
	y = _y + 1;
	while (IN_BOUNDS(x,y) && board[y][x]->piece == NULL) {
		results = g_list_prepend(results, board[y][x]);
		x++;
		y++;
	}

	if (IN_BOUNDS(x,y) && board[y][x]->piece != NULL && are_enemies(piece, board[y][x]->piece)) {
		results = g_list_prepend(results, board[y][x]);
	}

	// down-left
	x = _x - 1;
	y = _y + 1;
	while (IN_BOUNDS(x,y) && board[y][x]->piece == NULL) {
		results = g_list_prepend(results, board[y][x]);
		x--;
		y++;
	}

	if (IN_BOUNDS(x,y) && board[y][x]->piece != NULL && are_enemies(piece, board[y][x]->piece)) {
		results = g_list_prepend(results, board[y][x]);
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
	ChessPiece *piece = board[_y][_x]->piece;

	short x = _x;
	short y = _y;

	x = _x - 1;
	y = _y - 1;
	if (IN_BOUNDS(x, y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x;
	y = _y - 1;
	if (IN_BOUNDS(x, y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x + 1;
	y = _y - 1;
	if (IN_BOUNDS(x, y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x - 1;
	y = _y;
	if (IN_BOUNDS(x, y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x;
	y = _y;
	if (IN_BOUNDS(x, y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x + 1;
	y = _y;
	if (IN_BOUNDS(x, y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x - 1;
	y = _y + 1;
	if (IN_BOUNDS(x, y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x;
	y = _y + 1;
	if (IN_BOUNDS(x, y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	x = _x + 1;
	y = _y + 1;
	if (IN_BOUNDS(x, y) && (board[y][x]->piece == NULL || are_enemies(piece, board[y][x]->piece))) {
		results = g_list_prepend(results, board[y][x]);
	}

	return results;
}

GList *get_valid_moves(Square (*board)[8][8], short x, short y)
{
	Square *square = board[y][x];
	if (square->piece == NULL) {
		fprintf(stderr, "Error: no piece at (%d,%d)\n", square->pos.x, square->pos.y);
		return NULL;
	}

	switch (square->piece->type)
	{
		case PAWN:
			return get_valid_pawn_moves(board, x, y);
		case ROOK:
			return get_valid_rook_moves(board, x, y);
		case KNIGHT:
			return get_valid_knight_moves(board, x, y);
		case BISHOP:
			return get_valid_bishop_moves(board, x, y);
		case QUEEN:
			return get_valid_queen_moves(board, x, y);
		case KING:
			return get_valid_king_moves(board, x, y);
		default:
			fprintf(stderr, "Error: unrecognized piece type: %d\n", square->piece->type);
			return NULL;
	}
}
