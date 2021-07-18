#include <iostream>
#include <array>
#include <stdexcept>

#include "Header.h"



bool pieces::callPiece() // there are 7 pieces, so we need 7 random numbers. if we want one to be more likely we can raise this number and assign more numbers to a specific piece.
{
	srand(time(NULL));

	piece = rand() % 6;
	// std::cout << piece << "\n"; DEBUG
	lastpiece = 1; // DEBUG
	piece = 1; // DEBUG
	switch (piece)
	{
	case 0:
		std::cout << "piece 0\n";
		if (lastpiece != 0) {
			lastpiece = 0;
			Oblock();
			return true;
		}
		break;
	case 1:
		std::cout << "piece 1\n";
		if (lastpiece == 1) {
			lastpiece = 1;
			iblock();
			return true;
		}
		break;
	case 2:
		std::cout << "piece 2\n";
		if (lastpiece != 2) {
			lastpiece = 2;
			jblock();
			return true;
		}
		break;
	case 3:
		std::cout << "piece 3\n";
		if (lastpiece != 3) {
			lastpiece = 3;
			lblock();
			return true;
		}
		break;
	case 4:
		std::cout << "piece 4\n";
		if (lastpiece != 4) {
			lastpiece = 4;
			sblock();
			return true;
		}
	case 5:
		std::cout << "piece 5\n";
		if (lastpiece != 5) {
			lastpiece = 5;
			zblock();
			return true;
		}
	case 6:
		std::cout << "piece 6\n";
		if (lastpiece != 6) {
			lastpiece = 6;
			tblock();
			return true;
		}
	default:
			
		std::cout << "???BAD\n";
		break;
	}
	return false;
}
void pieces::Oblock()
{
	position = { 5,6,5,6,1,1,2,2 };
	//x1 = 5; x2 = 6;//x3 = 5; x4 = 6;
	//y1 = 1; y2 = 1;//y3 = 2; y4 = 2;
}

void pieces::iblock()
{
	position = { 5,5,5,5,1,2,3,4 };
	//x1 = 5; x2 = 5;//x3 = 5; x4 = 5;
	//y1 = 1; y2 = 2;//y3 = 3; y4 = 4;
}

void pieces::jblock()
{
	position = { 5,5,5,4,1,2,3,3 };
	//x1 = 5; x2 = 5;x3 = 5; x4 = 4;
	//y1 = 1; y2 = 2;y3 = 3; y4 = 3;
}

void pieces::lblock()
{
	position = { 5,5,5,6,1,2,3,3 };
	//x1 = 5; x2 = 5; x3 = 5; x4 = 6;
	//y1 = 1; y2 = 2; y3 = 3; y4 = 3;
}

void pieces::sblock()
{
	position = { 5,6,4,5,1,1,2,2 };
	//x1 = 5; x2 = 6;//x3 = 4; x4 = 5;
	//y1 = 1; y2 = 1;//y3 = 2; y4 = 2;
}
void pieces::zblock()
{
	position = { 5,6,4,5,1,1,2,2 };
	//x1 = 5; x2 = 6; //x3 = 4; x4 = 5;
	//y1 = 1; y2 = 1;//y3 = 2; y4 = 2;
}
void pieces::tblock()
{
	position = { 5,4,5,6,1,2,2,2 };
	//x1 = 5; x2 = 4;//x3 = 5; x4 = 6;
	//y1 = 1; y2 = 2;//y3 = 2; y4 = 2;
}


void pieces::advance()
{
	int stopwait = 15; // this in combination with the sleep timer in main allows the piece to float without advancing every tick (without using a C++ timer import)
	static int wait = stopwait;

	if (wait > 0)
		wait--;
	else {
		for (int i = 4; i < numXYPositions; i++) // increase all y values by 1
			position[i]++;
		wait = stopwait;
	}
}

bool pieces::piecePresent()
{
	return piecepresent;
}

void pieces::setpiecePresent(bool value)
{
	pieces::piecepresent = value;
}
//--------------getX
int pieces::getPosition(int pos) // x1,x2,x3,x4,y1,y2,y3,y4
{
	return position[pos];
}

//--------------setX
void pieces::modPosition(int pos, int value)
{
	position[pos] += value;
}

int pieces::getpiece()
{
	return piece;
}
int pieces::getNumXYPositions()
{
	return numXYPositions;
}

// BEGIN DISPLAY:PIECES CLASS// BEGIN DISPLAY:PIECES CLASS// BEGIN DISPLAY:PIECES CLASS
// BEGIN DISPLAY:PIECES CLASS// BEGIN DISPLAY:PIECES CLASS// BEGIN DISPLAY:PIECES CLASS
// BEGIN DISPLAY:PIECES CLASS// BEGIN DISPLAY:PIECES CLASS// BEGIN DISPLAY:PIECES CLASS
// BEGIN DISPLAY:PIECES CLASS// BEGIN DISPLAY:PIECES CLASS// BEGIN DISPLAY:PIECES CLASS
// BEGIN DISPLAY:PIECES CLASS// BEGIN DISPLAY:PIECES CLASS// BEGIN DISPLAY:PIECES CLASS

bool display::ycollisioncheck()
{ // if x+1 = board[i][c] = 1 then STOP and board[i][c] = 1;

	if (board[getPosition(4) + 1][getPosition(0)] == 1 || board[getPosition(5) + 1][getPosition(1)] == 1 || board[getPosition(6) + 1][getPosition(2)] == 1 || board[getPosition(7) + 1][getPosition(3)] == 1) // IMPORTANT instead of return true or false, try shifting this can help with collision
		return false;
	else
		return true;
}
void display::moveLeftRightDown(int setn, int value, int divisor)
{
	if (xlrCollisionCheck(value)) { // IMPORTANT instead of return true or false xrCollisionCheck(), try shifting this can help with collision
		for(int i = setn; i < getNumXYPositions() / divisor; i++) // i = starting pos, for y(down) = 4, for left/right = 0, getnumxypos default 8 need 4 if starting at y
			modPosition(i, value); // BUG Need to run modified collision check here, to move newly applied pieces
	}
}

void display::rotate() // IMPORTANT instead of return true or false, try shifting this can help with collision
{
	int hx1 = getPosition(0), hx2 = getPosition(1), hx3 = getPosition(2), hx4 = getPosition(3), hy1 = getPosition(4), hy2 = getPosition(5), hy3 = getPosition(6), hy4 = getPosition(7);

	std::cout << rota;
	switch (getpiece())
	{
	case 0: // oblock no need to rotate
		break;
	case 1: // i block, 2 states of rotation
		switch (rota)
		{
		case 0: 
			modPosition(0,-1); //x1
			modPosition(1, 0); //x2
			modPosition(2, 1); //x3
			modPosition(3, 2); //x4

			modPosition(4, 2); //y1
			modPosition(5, 1); //y2
			modPosition(6, 0); //y3
			modPosition(7,-1); //y4
			rota = 1;
			break;
		case 1:
			modPosition(0, 1); //x1
			modPosition(1, 0); //x2
			modPosition(2, -1); //x3
			modPosition(3, -2); //x4

			modPosition(4, -2); //y1
			modPosition(5, -1); //y2
			modPosition(6, 0); //y3
			modPosition(7, 1); //y4
			rota = 0;
			break;
		}
		break;
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		break;
	}
		
}

bool display::xlrCollisionCheck(int inc) // IMPORTANT instead of return true or false, try shifting this can help with collision
{
	for (int i = 4; i < getNumXYPositions(); i++)
		if (board[getPosition(i)][getPosition(i - 4) + inc] == 1)
		{
			for (int c = 0; c < getNumXYPositions() / 2; c++) { // TRY PUTTING THIS IN MODPOSITION to edit as the pieces are being placed.
				modPosition(c, (inc * -1));
			}

		}
		//return false;
	return true;
}

void display::addToArray()
{
	for (int i = 0; i < (getNumXYPositions() / 2); i++) { // goes through all values and sets board position = piece position to 1, creating a new boundary
		board[getPosition(i + 4)][getPosition(i)] = 1;
	}

}
void display::drawTable()
{
	for (int i = 0; i < rows; i++) { // height
		for (int c = 0; c < columns; c++) // cout ###########
		{
			if (i == 0 || i == rows - 1) {
				std::cout << "#";
				board[i][c] = 1;
				// std::cout << board[i][c]; // DEBUG
			}
			else
				if (c == 0 || c == columns - 1) {
					board[i][c] = 1;
					// std::cout << board[i][c]; // DEBUG
					std::cout << "#";
				}
				else if (c == getPosition(0) && i == getPosition(4) || c == getPosition(1) && i == getPosition(5) || c == getPosition(2) && i == getPosition(6) || c == getPosition(3) && i == getPosition(7)) {
					std::cout << "0";
				}
				else if (board[i][c] == 1)
					std::cout << "Q";
				else{
					board[i][c] = 0;
					//std::cout << board[i][c]; // DEBUG
					std::cout << " ";
				}

		}
		std::cout << "\n";
	}
}
int display::getRota()
{
	return rota;
}