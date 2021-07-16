#include <iostream>
#include <Windows.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class pieces
{
private:
	int x1, x2, x3, x4, y1, y2, y3, y4; // each tetris piece has 4 squares
	bool piecepresent = false;

public:
	void callPiece() // there are 7 pieces, so we need 7 random numbers. if we want one to be more likely we can raise this number and assign more numbers to a specific piece.
	{
		srand(time(NULL));

		int piece;
		piece = rand() % 6;
		// std::cout << piece << "\n";
		switch (piece + 1)
		{
		case 1:
			std::cout << "piece 1\n";
			Oblock();
			break;
		case 2:
			std::cout << "piece 2\n"; // make it a 2d array/matrix each row is a ... row with 25 spaces and 25 rows // tetris board is 10w 20h
			Oblock();
			break;
		case 3:
			std::cout << "piece 3\n";
			Oblock();
			break;
		case 4:
			std::cout << "piece 4\n";
			Oblock();
			break;
		case 5:
			std::cout << "piece 5\n";
			Oblock();
			break;
		case 6:
			std::cout << "piece 6\n";
			Oblock();
			break;
		case 7:
			std::cout << "piece 7\n";
			Oblock();
			break;
		default:
			std::cout << "???BAD\n";
			break;
		}
	}
	void Oblock()
	{
		x1 = 5; x2 = 6;
		x3 = 5; x4 = 6;

		y1 = 1; y2 = 1;
		y3 = 2; y4 = 2;
	}

	void advance()
	{
		int stopwait = 15; // this in combination with the sleep timer in main allows the piece to float without advancing every tick (without using a C++ timer import)
		static int wait = stopwait;

		if (wait > 0)
			wait--;
		else {
			y1++;
			y2++;
			y3++;
			y4++;
			wait = stopwait;
		}

	}

	bool piecePresent()
	{
		return piecepresent;
	}

	void setpiecePresent(bool value)
	{
		piecepresent = value;
	}
	//--------------getX
	int getX1()
	{
		return x1;
	}
	int getX2()
	{
		return x2;
	}
	int getX3()
	{
		return x3;
	}
	int getX4()
	{
		return x4;
	}
	//--------------getX
	int getY1()
	{
		return y1;
	}
	int getY2()
	{
		return y2;
	}
	int getY3()
	{
		return y3;
	}
	int getY4()
	{
		return y4;
	}
	//--------------setX
	void setX1(int value)
	{
		x1 += value;
	}
	void setX2(int value)
	{
		x2 += value;
	}
	void setX3(int value)
	{
		x3 += value;
	}
	void setX4(int value)
	{
		x4 += value;
	}
	//--------------setY
	void setY1(int value)
	{
		y1 += value;
	}
	void setY2(int value)
	{
		y2 += value;
	}
	void setY3(int value)
	{
		y3 += value;
	}
	void setY4(int value)
	{
		y4 += value;
	}

};

class display : public pieces
{
private:
	int board[21][11]; // Y and X
	// need to create a matrix for all available open spots, 0 unoccupied 1 occupied
	// pieces pie;

public:
	bool collisoncheck()
	{ // if x+1 = board[i][c] = 1 then STOP and board[i][c] = 1;
		//int futureX1 = getX1() + 1; // dont think i need these for collision but I will wait until adding more shapes before i remove them
		//int futureX2 = getX2() + 1;
		//int futureX3 = getX3() + 1;
		//int futureX4 = getX4() + 1;

		int futureY1 = getY1() + 1;
		int futureY2 = getY2() + 1;
		int futureY3 = getY3() + 1;
		int futureY4 = getY4() + 1;

		std::cout << board[futureY1][getX1()];
		std::cout << board[futureY2][getX2()];
		std::cout << board[futureY3][getX3()];
		std::cout << board[futureY4][getX4()];

		if (board[futureY1][getX1()] == 1 || board[futureY2][getX2()] == 1 || board[futureY3][getX3()] == 1 || board[futureY4][getX4()] == 1)
			return false;
		else
			return true;
	}
	void moveRight()
	{
		if (xrCollisionCheck()) {
			setX1(1);
			setX2(1);
			setX3(1);
			setX4(1);
		}
	}

	void moveLeft()
	{
		if (xlCollisionCheck()) {
			setX1(-1);
			setX2(-1);
			setX3(-1);
			setX4(-1);
		}
	}
	void moveDown()
	{
		setY1(1);
		setY2(1);
		setY3(1);
		setY4(1);
	}

	bool xrCollisionCheck()
	{
		int futureX1 = getX1() + 1; 
		int futureX2 = getX2() + 1;
		int futureX3 = getX3() + 1;
		int futureX4 = getX4() + 1;

		if (board[getY1()][futureX1] == 1 || board[getY2()][futureX2] == 1 || board[getY2()][futureX2] == 1 || board[getY2()][futureX2] == 1)
			return false;
		else
			return true;
	}
	bool xlCollisionCheck()
	{
		int futureX1 = getX1() - 1;
		int futureX2 = getX2() - 1;
		int futureX3 = getX3() - 1;
		int futureX4 = getX4() - 1;

		if (board[getY1()][futureX1] == 1 || board[getY2()][futureX2] == 1 || board[getY2()][futureX2] == 1 || board[getY2()][futureX2] == 1)
			return false;
		else
			return true;
	}
	void addToArray()
	{
		board[getY1()][getX1()] = 1;
		board[getY2()][getX2()] = 1;
		board[getY3()][getX3()] = 1;
		board[getY4()][getX4()] = 1;
	}
	void drawTable()
	{
		for (int i = 0; i < 22; i++) { // height
			for (int c = 0; c < 12; c++) // cout ###########
			{
				if (i == 0 || i == 21) {
					std::cout << "#";
					board[i][c] = 1;
					// std::cout << board[i][c]; // DEBUG
				}
				else
					if (c == 0 || c == 11) {
						board[i][c] = 1;
						// std::cout << board[i][c]; // DEBUG
						std::cout << "#";
					}
					else if (c == getX1() && i == getY1() || c == getX2() && i == getY2() || c == getX3() && i == getY3() || c == getX4() && i == getY4()) {
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


};


