#include "Piece.h"
#include <iostream>
#include "assert.h"

using namespace std;

Piece::Piece()
{
	pieceID = (rand() % 4) + 1;
	setPiece(pieceID);
}

Piece::Piece(int id)
{
	pieceID = id;
	setPiece(id);
}

void Piece::setPiece(int id)
{
	//Reserved id for empty spaces
	assert(id != 0);

	switch(pieceID){
		case 1:	
			// X.
			// XX
			piece[0][0] = 1;
			piece[1][0] = 0;
			piece[0][1] = 1;
			piece[1][1] = 1;
			break;
		case 2:
			// XX
			// XX
			piece[0][0] = 1;
			piece[1][0] = 1;
			piece[0][1] = 1;
			piece[1][1] = 1;
			break;
		case 3:
			// XX
			// .X
			piece[0][0] = 1;
			piece[1][0] = 1;
			piece[0][1] = 0;
			piece[1][1] = 1;
			break;
		case 4:
			// X.
			// X.
			piece[0][0] = 1;
			piece[1][0] = 0;
			piece[0][1] = 1;
			piece[1][1] = 0;
			break;
		default:
			cerr << "BAD PIECE ID " << pieceID;
			exit(1);
	}
}

int Piece::getPieceID()
{
	return pieceID;
}

void Piece::copyPiece(bool buf[PIECESIZE][PIECESIZE])
{
	for (int x = 0; x < PIECESIZE; x++) {
		for (int y = 0; y < PIECESIZE; y++) {
			buf[x][y] = piece[x][y];
		}
	}
}

int Piece::pieceWidth()
{
	int width = 0;
	for (int x = 0; x < PIECESIZE; x++) {
		for (int y = 0; y < PIECESIZE; y++) {
			if (piece[x][y]) {
				width = x;
			}
		}
	}
	return width;
}

void Piece::printPiece()
{
	for (int y = 0; y < PIECESIZE; y++) {
		for (int x = 0; x < PIECESIZE; x++) {
			cout << piece[x][y];
		}
		cout << endl;
	}
}