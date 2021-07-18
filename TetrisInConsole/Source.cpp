#include <iostream>
#include <array>
#include <stdexcept>

#include "Header.h"



bool pieces::callPiece() // there are 7 pieces, so we need 7 random numbers. if we want one to be more likely we can raise this number and assign more numbers to a specific piece.
{
	srand(time(NULL));

	piece = rand() % 6;
	// std::cout << piece << "\n";
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
		if (lastpiece != 1) {
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
	//x1 = 5; x2 = 6;
	//x3 = 5; x4 = 6;

	//y1 = 1; y2 = 1;
	//y3 = 2; y4 = 2;
}

void pieces::iblock()
{
	position = { 5,5,5,5,1,2,3,4 };
	//x1 = 5; x2 = 5;
	//x3 = 5; x4 = 5;

	//y1 = 1; y2 = 2;
	//y3 = 3; y4 = 4;
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
	//x1 = 5; x2 = 6;
	//x3 = 4; x4 = 5;

	//y1 = 1; y2 = 1;
	//y3 = 2; y4 = 2;
}
void pieces::zblock()
{
	position = { 5,6,4,5,1,1,2,2 };
	//x1 = 5; x2 = 6;
	//x3 = 4; x4 = 5;

	//y1 = 1; y2 = 1;
	//y3 = 2; y4 = 2;
}
void pieces::tblock()
{
	position = { 5,4,5,6,1,2,2,2 };
	//x1 = 5; x2 = 4;
	//x3 = 5; x4 = 6;

	//y1 = 1; y2 = 2;
	//y3 = 2; y4 = 2;
}


void pieces::advance()
{
	int stopwait = 15; // this in combination with the sleep timer in main allows the piece to float without advancing every tick (without using a C++ timer import)
	static int wait = stopwait;

	if (wait > 0)
		wait--;
	else {
		//y1++;
		//y2++;
		//y3++;
		//y4++;
		for (int i = 4; i < numXYPositions; i++)
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
void pieces::setPosition(int pos, int value)
{
	position[pos] = value;
}
	
//--------------setX
void pieces::incPosition(int pos, int value)
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


bool display::collisoncheck()
{ // if x+1 = board[i][c] = 1 then STOP and board[i][c] = 1;

	int futureY1 = getPosition(4) + 1;
	int futureY2 = getPosition(5) + 1;
	int futureY3 = getPosition(6) + 1;
	int futureY4 = getPosition(7) + 1;

	std::cout << board[futureY1][getPosition(0)];
	std::cout << board[futureY2][getPosition(1)];
	std::cout << board[futureY3][getPosition(2)];
	std::cout << board[futureY4][getPosition(3)];

	if (board[futureY1][getPosition(0)] == 1 || board[futureY2][getPosition(1)] == 1 || board[futureY3][getPosition(2)] == 1 || board[futureY4][getPosition(3)] == 1) // IMPORTANT instead of return true or false, try shifting this can help with collision
		return false;
	else
		return true;
}
void display::moveRight()
{
	if (xrCollisionCheck()) { // IMPORTANT instead of return true or false, try shifting this can help with collision
		incPosition(0, 1);
		incPosition(1, 1);
		incPosition(2, 1);
		incPosition(3, 1);
	}
}

void display::moveLeft()
{
	if (xlCollisionCheck()) { // IMPORTANT instead of return true or false, try shifting this can help with collision
		incPosition(0, -1);
		incPosition(1, -1);
		incPosition(2, -1);
		incPosition(3, -1);
	}
}
void display::moveDown()
{
	incPosition(4, 1);
	incPosition(5, 1);
	incPosition(6, 1);
	incPosition(7, 1);
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
			setPosition(0,1);
			setPosition(0, 1);
			setPosition(0, 1);
			setPosition(0, 1);
			setPosition(0, 1);
			setPosition(0, 1);
			setPosition(0, 1);
			setPosition(0, 1);
			rota = 1;
			break;
		case 1:
			setPosition(0, 5);
			setPosition(0, 5);
			setPosition(0, 5);
			setPosition(0, 5);
			setPosition(0, 2);
			setPosition(0, 3);
			setPosition(0, 4);
			setPosition(0, 5);
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
bool display::xrCollisionCheck() // IMPORTANT instead of return true or false, try shifting this can help with collision
{
	int futureX1 = getPosition(0) + 1; 
	int futureX2 = getPosition(1) + 1;
	int futureX3 = getPosition(2) + 1;
	int futureX4 = getPosition(3) + 1;

	if (board[getPosition(4)][futureX1] == 1 || board[getPosition(5)][futureX2] == 1 || board[getPosition(6)][futureX3] == 1 || board[getPosition(7)][futureX4] == 1)
		return false;
	else
		return true;
}
bool display::xlCollisionCheck() // IMPORTANT instead of return true or false, try shifting this can help with collision
{
	int futureX1 = getPosition(0) - 1;
	int futureX2 = getPosition(1) - 1;
	int futureX3 = getPosition(2) - 1;
	int futureX4 = getPosition(3) - 1;

	if (board[getPosition(4)][futureX1] == 1 || board[getPosition(5)][futureX2] == 1 || board[getPosition(6)][futureX3] == 1 || board[getPosition(7)][futureX4] == 1)
		return false;
	else
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
				std::cout << "X";
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