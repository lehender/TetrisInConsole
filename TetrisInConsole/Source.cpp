#include <iostream>
#include <iomanip>
#include <array>
#include <stdexcept>

#include "Header.h"

bool pieces::callPiece() // there are 7 pieces, so we need 7 random numbers. if we want one to be more likely we can raise this number and assign more numbers to a specific piece.
{
	srand(time(NULL));

	piece = nextpiece;

	// std::cout << piece << "\n"; DEBUG
	//lastpiece = 3; // DEBUG
	//piece = 3; // DEBUG
	
	switch (piece)
	{
	case 1:
		if (lastpiece != 1) {
			lastpiece = 1;
			Oblock(position);
			return true;
		}
		break;
	case 2:
		if (lastpiece != 2) {
			lastpiece = 2;
			iblock(position);
			return true;
		}
		break;
	case 3:
		if (lastpiece != 3) {
			lastpiece = 3;
			jblock(position);
			return true;
		}
		break;
	case 4:
		if (lastpiece != 4) {
			lastpiece = 4;
			lblock(position);
			return true;
		}
		break;
	case 5:
		if (lastpiece != 5) {
			lastpiece = 5;
			sblock(position);
			return true;
		}
	case 6:
		if (lastpiece != 6) {
			lastpiece = 6;
			zblock(position);
			return true;
		}
	case 7:
		if (lastpiece != 7) {
			lastpiece = 7;
			tblock(position);
			return true;
		}
	default:
		std::cout << "???BAD\n";
		break;
	}

	return false;
}

int pieces::getNextPiece()
{
	return nextpiece;
}
int pieces::setNextPiece()
{
	while (nextpiece == lastpiece) {
		nextpiece = rand() % 7 + 1;
	}



	switch (nextpiece)
	{
	case 1:
		Oblock(nextPositionArray);
		break;
	case 2:
		iblock(nextPositionArray);
		break;
	case 3:
		jblock(nextPositionArray);
		break;
	case 4:
		lblock(nextPositionArray);
		break;
	case 5:
		sblock(nextPositionArray);
		break;
	case 6:
		zblock(nextPositionArray);
		break;
	case 7:
		tblock(nextPositionArray);
		break;
	}
	return nextpiece;
}

void pieces::Oblock(std::array<int, numXYPositions>& arr)
{
	arr = { 5,6,5,6,0,0,1,1 };
	//x1 = 5; x2 = 6;//x3 = 5; x4 = 6;
	//y1 = 1; y2 = 1;//y3 = 2; y4 = 2;
}

void pieces::iblock(std::array<int, numXYPositions>& arr)
{
	arr = { 5,5,5,5,0,1,2,3 };
	//x1 = 5; x2 = 5;//x3 = 5; x4 = 5;
	//y1 = 1; y2 = 2;//y3 = 3; y4 = 4;
}

void pieces::jblock(std::array<int, numXYPositions>& arr)
{
	arr = { 5,5,5,4,0,1,2,2 };
	//x1 = 5; x2 = 5;x3 = 5; x4 = 4;
	//y1 = 1; y2 = 2;y3 = 3; y4 = 3;
}

void pieces::lblock(std::array<int, numXYPositions>& arr)
{
	arr = { 5,5,5,6,0,1,2,2 };
	//x1 = 5; x2 = 5; x3 = 5; x4 = 6;
	//y1 = 1; y2 = 2; y3 = 3; y4 = 3;
}

void pieces::sblock(std::array<int, numXYPositions>& arr)
{
	arr = { 5,6,4,5,0,0,1,1 };
	//x1 = 5; x2 = 6;//x3 = 4; x4 = 5;
	//y1 = 1; y2 = 1;//y3 = 2; y4 = 2;
}
void pieces::zblock(std::array<int, numXYPositions>& arr)
{
	arr = { 4,5,5,6,0,0,1,1 };
	//x1 = 4; x2 = 5; //x3 = 5; x4 = 6;
	//y1 = 1; y2 = 1;//y3 = 2; y4 = 2;
}
void pieces::tblock(std::array<int, numXYPositions>& arr)
{
	arr = { 5,4,5,6,0,1,1,1 };
	//x1 = 5; x2 = 4;//x3 = 5; x4 = 6;
	//y1 = 1; y2 = 2;//y3 = 2; y4 = 2;
}


void pieces::advance(int score)
{
	int stopwait; // this in combination with the sleep timer in main allows the piece to float without advancing every tick (without using a C++ timer import)
	if (score < 50)
		stopwait = 5;
	if (score >= 50)
		stopwait = 4;
	if (score >= 100)
		stopwait = 3;
	if (score >= 150)
		stopwait = 2;
	if (score >= 200)
		stopwait = 1;
	if (score > 275)
		stopwait = 0;
	//std::cout << stopwait;
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
int pieces::getNextPosition(int pos) // x1,x2,x3,x4,y1,y2,y3,y4
{
	return nextPositionArray[pos];
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

	if (board[getPosition(4) + 1][getPosition(0)] != 0 || board[getPosition(5) + 1][getPosition(1)] != 0 || board[getPosition(6) + 1][getPosition(2)] != 0 || board[getPosition(7) + 1][getPosition(3)] != 0) // IMPORTANT instead of return true or false, try shifting this can help with collision
		return false;
	else
		return true;
}
void display::moveLeftRightDown(int setn, int value, int divisor)
{
	//std::cout << "SETN = " << setn << " Value = " << value << " div = " << divisor << "\n";
	xlrCollisionCheck(value, setn);
	for(int i = setn; i < getNumXYPositions() / divisor; i++) // i = starting pos, for y(down) = 4, for left/right = 0, getnumxypos default 8 need 4 if starting at y
		modPosition(i, value); 

}

void display::rotate() 
{
	int hx1 = getPosition(0), hx2 = getPosition(1), hx3 = getPosition(2), hx4 = getPosition(3), hy1 = getPosition(4), hy2 = getPosition(5), hy3 = getPosition(6), hy4 = getPosition(7);

	switch (getpiece())
	{
	case 1: // oblock no need to rotate
		break;
	case 2: // i block, 2 states of rotation
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
	case 3: // j block rotation
		switch (rota)
		{
		case 0:
			modPosition(0, -2); //x1
			modPosition(1, -1); //x2
			modPosition(2, 0); //x3
			modPosition(3, 1); //x4

			modPosition(4, 1); //y1
			modPosition(5, 0); //y2
			modPosition(6, -1); //y3
			modPosition(7, 0); //y4
			rota = 1;
			break;
		case 1:
			modPosition(0, 1); //x1
			modPosition(1, 0); //x2
			modPosition(2, -1); //x3
			modPosition(3, 0); //x4

			modPosition(4, 2); //y1
			modPosition(5, 1); //y2
			modPosition(6, 0); //y3
			modPosition(7, -1); //y4
			rota = 2;
			break;
		case 2:
			modPosition(0, 1); //x1
			modPosition(1, 0); //x2
			modPosition(2, -1); //x3
			modPosition(3, -2); //x4

			modPosition(4, -1); //y1
			modPosition(5, 0); //y2
			modPosition(6, 1); //y3
			modPosition(7, 0); //y4
			rota = 3;
			break;
		case 3:
			modPosition(0, 0); //x1
			modPosition(1, 1); //x2
			modPosition(2, 2); //x3
			modPosition(3, 1); //x4

			modPosition(4, -2); //y1
			modPosition(5, -1); //y2
			modPosition(6, 0); //y3
			modPosition(7, 1); //y4
			rota = 0;
			break;
		}
		break;
	case 4: // L block
		switch (rota)
		{
		case 0:
			modPosition(0, -2); //x1
			modPosition(1, -1); //x2
			modPosition(2, 0); //x3
			modPosition(3, -1); //x4

			modPosition(4, 1); //y1
			modPosition(5, 0); //y2
			modPosition(6, -1); //y3
			modPosition(7, -2); //y4
			rota = 1;
			break;
		case 1:
			modPosition(0, 1); //x1
			modPosition(1, 0); //x2
			modPosition(2, -1); //x3
			modPosition(3, -2); //x4

			modPosition(4, 2); //y1
			modPosition(5, 1); //y2
			modPosition(6, 0); //y3
			modPosition(7, 1); //y4
			rota = 2;
			break;
		case 2:
			modPosition(0, 1); //x1
			modPosition(1, 0); //x2
			modPosition(2, -1); //x3
			modPosition(3, 0); //x4

			modPosition(4, -1); //y1
			modPosition(5, 0); //y2
			modPosition(6, 1); //y3
			modPosition(7, 2); //y4
			rota = 3;
			break;
		case 3:
			modPosition(0, 0); //x1
			modPosition(1, 1); //x2
			modPosition(2, 2); //x3
			modPosition(3, 3); //x4

			modPosition(4, -2); //y1
			modPosition(5, -1); //y2
			modPosition(6, 0); //y3
			modPosition(7, -1); //y4
			rota = 0;
			break;
		}
		break;
	case 5: // s block
		switch (rota)
		{
		case 0:
			modPosition(0, 1); //x1
			modPosition(1, 0); //x2
			modPosition(2, 1); //x3
			modPosition(3, 0); //x4

			modPosition(4, 1); //y1
			modPosition(5, 2); //y2
			modPosition(6, -1); //y3
			modPosition(7, 0); //y4
			rota = 1;
			break;
		case 1:
			modPosition(0, -1); //x1
			modPosition(1, 0); //x2
			modPosition(2, -1); //x3
			modPosition(3, 0); //x4

			modPosition(4, -1); //y1
			modPosition(5, -2); //y2
			modPosition(6, 1); //y3
			modPosition(7, 0); //y4
			rota = 0;
			break;
		}
		break;
	case 6: // z block
		switch (rota)
		{
		case 0:
			modPosition(0, 1); //x1
			modPosition(1, 0); //x2
			modPosition(2, 1); //x3
			modPosition(3, 0); //x4

			modPosition(4, 2); //y1
			modPosition(5, 1); //y2
			modPosition(6, 0); //y3
			modPosition(7, -1); //y4
			rota = 1;
			break;
		case 1:
			modPosition(0, -1); //x1
			modPosition(1, 0); //x2
			modPosition(2, -1); //x3
			modPosition(3, 0); //x4

			modPosition(4, -2); //y1
			modPosition(5, -1); //y2
			modPosition(6, 0); //y3
			modPosition(7, 1); //y4
			rota = 0;
			break;
		}
		break;
	case 7: // t block
		switch (rota)
		{
		case 0:
			modPosition(0, 1); //x1
			modPosition(1, 1); //x2
			modPosition(2, 0); //x3
			modPosition(3, -1); //x4

			modPosition(4, 1); //y1
			modPosition(5, -1); //y2
			modPosition(6, 0); //y3
			modPosition(7, 1); //y4
			rota = 1;
			break;
		case 1:
			modPosition(0, -1); //x1
			modPosition(1, 1); //x2
			modPosition(2, 0); //x3
			modPosition(3, -1); //x4

			modPosition(4, 1); //y1
			modPosition(5, 1); //y2
			modPosition(6, 0); //y3
			modPosition(7, -1); //y4
			rota = 2;
			break;
		case 2:
			modPosition(0, -1); //x1
			modPosition(1, -1); //x2
			modPosition(2, 0); //x3
			modPosition(3, 1); //x4

			modPosition(4, -1); //y1
			modPosition(5, 1); //y2
			modPosition(6, 0); //y3
			modPosition(7, -1); //y4
			rota = 3;
			break;
		case 3:
			modPosition(0, 1); //x1
			modPosition(1, -1); //x2
			modPosition(2, 0); //x3
			modPosition(3, 1); //x4

			modPosition(4, -1); //y1
			modPosition(5, -1); //y2
			modPosition(6, 0); //y3
			modPosition(7, 1); //y4
			rota = 0;
			break;
		}
		break;
	}
	if (getPosition(0) >= 5) // check after rotation that piece is not in the wall. Check that x1 is greater than or equal to 5, similar to moving right, we send it a +1, which will move the piece LEFT, else right.
		xlrCollisionCheck(1, 0);
	else
		xlrCollisionCheck(-1, 0);
		
}

void display::xlrCollisionCheck(int inc, int setn)
{
	if (setn != 4) { // dont want to check if moving down, only l or r
		for (int i = 4; i < getNumXYPositions(); i++) {
			//std::cout << "CHECK1\n"; // DEBUG
			if (board[getPosition(i)][getPosition(i - 4) + (inc)] != 0) {
				//std::cout << "CHECK2\n"; // DEBUB
				for (int c = 0; c < getNumXYPositions() / 2; c++) {
					//std::cout << "CHECK3\n"; // DEBUG
					modPosition(c, (inc * -1)); // This pushes the piece away OPPOSITE of the direction it is moving. 
				}

			}
		}
	}
}

void display::addToArray()
{
	for (int i = 0; i < (getNumXYPositions() / 2); i++) { // goes through all values and sets board position = piece position to 1, creating a new boundary
		if (getPosition(i + 4) == 0)
		{
			std::cout << "GAME OVER";
			std::cin.get();
		}
		board[getPosition(i + 4)][getPosition(i)] = getpiece();
	}
}
void display::drawTable()
{
	for (int i = 0; i < rows; i++) { // height
		for (int c = 0; c < columns; c++) // width
		{
			if (i == 0 || i == rows - 1) { // top and bottom border
				color("board"); std::cout << "#"; color("default");
				board[i][c] = 1;
				// std::cout << board[i][c]; // DEBUG
			}
			else {
				if (c == 0 || c >= (columns / 2) - 1) { // left and right walls/table
					board[i][c] = 1;
					//std::cout << board[i][c]; // DEBUG
					// Table detail drawing
					if (i > 0 && i < 7 && c > 11 && c < columns - 1) {
						if (i == 1 && c < (columns - 2))
							std::cout << nextPieceText[(c - 12)];
						else if (i > 1 && i < 8)
							drawPieceinNext((rows - i), (columns - c));
						else
							std::cout << " ";
					}
					else if (i == 9 && c > 11 && c < columns - 1) {
						if (c > 11 && c < 18)
							std::cout << scoreText[(c - 12)];
						else
							std::cout << " ";
					}
					else if (i == 10 && c > 11 && c < columns - 1) {
						if (c == 12)
							std::cout << std::setw(11) << score;
						else
							std::cout << "";
					}
					else if (i == 12 && c > 11 && c < columns - 1) {
						color("redblack");
						std::cout << tetrisText[(c - 12)];
						color("default");
					}
					else {
						color("board"); std::cout << "#"; color("default");
					}
						
					// End of table detail drawing
				}
				else if (board[i][c] != 0) {
					drawPiece(board[i][c]);
				}
				else if (i > 0 && i < rows && c > 0 && c <= columns / 2) {
					drawPieceinBoard(i, c);
					//std::cout << board[i][c]; // DEBUG
				}

				else if (c < columns / 2) {
					board[i][c] = 0;
					//std::cout << board[i][c]; // DEBUG
					std::cout << " ";
				}
			}
		}
		std::cout << "\n";
	}
}
void display::drawPieceinNext(int y, int x)
{
	y -= 16;
	x -= 2;
	//std::cout << "y = " << y << " x = " << x << "\n";
	if (x == getNextPosition(0) && y == getNextPosition(4) || x == getNextPosition(1) && y == getNextPosition(5) || x == getNextPosition(2) && y == getNextPosition(6) || x == getNextPosition(3) && y == getNextPosition(7))
		drawPiece(getNextPiece());
	else
		std::cout << " ";
}

void display::drawPieceinBoard(int y, int x)
{

	if (x == getPosition(0) && y == getPosition(4) || x == getPosition(1) && y == getPosition(5) || x == getPosition(2) && y == getPosition(6) || x == getPosition(3) && y == getPosition(7))
		drawPiece(getpiece());
	else
		std::cout << " ";
}

void display::drawPiece(int piece)
{
	switch (piece)
	{
	case 1:
		color("lightblue"); 
		std::cout << " ";
		color("default");
		break;
	case 2:
		color("lightgreen");
		std::cout << " ";
		color("default");
		break;
	case 3:
		color("pink");
		std::cout << " ";
		color("default");
		break;
	case 4:
		color("purple");
		std::cout << " ";
		color("default");
		break;
	case 5:
		color("tan");
		std::cout << " ";
		color("default");
		break;
	case 6:
		color("darkblue");
		std::cout << " ";
		color("default");
		break;
	case 7:
		color("yellow");
		std::cout << " ";
		color("default");
		break;
	}
}
int display::getRota()
{
	return rota;
}

void display::setRota(int val)
{
	rota = val;
}


void display::color(std::string col)
{
	if (col == "default")
		SetConsoleTextAttribute(hConsole, 7);

	if (col == "lightblue")
		SetConsoleTextAttribute(hConsole, 153);
	if (col == "lightgreen")
		SetConsoleTextAttribute(hConsole, 170);
	if (col == "pink")
		SetConsoleTextAttribute(hConsole, 204);
	if (col == "purple")
		SetConsoleTextAttribute(hConsole, 221);
	if (col == "tan")
		SetConsoleTextAttribute(hConsole, 238);
	if (col == "darkblue")
		SetConsoleTextAttribute(hConsole, 17);
	if (col == "yellow")
		SetConsoleTextAttribute(hConsole, 102);

	if (col == "redblack")
		SetConsoleTextAttribute(hConsole, 64);
	if (col == "board")
		SetConsoleTextAttribute(hConsole, 136);
	if (col == "test")
		for (int i = 0; i < 255; i++)
		{
			SetConsoleTextAttribute(hConsole, i);
			std::cout << i << "THIS IS a test!!!" << std::endl;
		}
}

void display::checkLines()
{
	int count, tetris_row;

	for (int i = rows - 2; i > 0; i--) { // height
		count = 0;
		for (int c = columns - 14; c > 0; c--) {// width
			if (board[i][c] > 0 && board[i][c] < 8) {
				count++;
				tetris_row = i;
			}
				
		}
		//std::cout << " " << count;
		if (count == 10) {
			score += 25;
			for (int i = tetris_row; i > 2; i--) { // height
				for (int c = columns - 14; c > 0; c--) {// width
					board[i][c] = board[i-1][c];
				}
			}
			std::cout << "TETRIS";
		}
		//count = 0;
	}
}

int display::getScore()
{
	return score;
}