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
	int lastpiece = 0, piece = 0;
	bool piecepresent = false;

public:
	bool callPiece() // there are 7 pieces, so we need 7 random numbers. if we want one to be more likely we can raise this number and assign more numbers to a specific piece.
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
	void Oblock()
	{
		x1 = 5; x2 = 6;
		x3 = 5; x4 = 6;

		y1 = 1; y2 = 1;
		y3 = 2; y4 = 2;
	}

	void iblock()
	{
		x1 = 5; x2 = 5;
		x3 = 5; x4 = 5;

		y1 = 1; y2 = 2;
		y3 = 3; y4 = 4;
	}

	void jblock()
	{
		x1 = 5; x2 = 5;x3 = 5; x4 = 4;
		y1 = 1; y2 = 2;y3 = 3; y4 = 3;
	}

	void lblock()
	{
		x1 = 5; x2 = 5; x3 = 5; x4 = 6;
		y1 = 1; y2 = 2; y3 = 3; y4 = 3;
	}

	void sblock()
	{
		x1 = 5; x2 = 6;
		x3 = 4; x4 = 5;

		y1 = 1; y2 = 1;
		y3 = 2; y4 = 2;
	}
	void zblock()
	{
		x1 = 5; x2 = 6;
		x3 = 4; x4 = 5;

		y1 = 1; y2 = 1;
		y3 = 2; y4 = 2;
	}
	void tblock()
	{
		x1 = 5; x2 = 4;
		x3 = 5; x4 = 6;

		y1 = 1; y2 = 2;
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
		x1 = value;
	}
	void setX2(int value)
	{
		x2 = value;
	}
	void setX3(int value)
	{
		x3 = value;
	}
	void setX4(int value)
	{
		x4 = value;
	}
	//--------------setY
	void setY1(int value)
	{
		y1 = value;
	}
	void setY2(int value)
	{
		y2 = value;
	}
	void setY3(int value)
	{
		y3 = value;
	}
	void setY4(int value)
	{
		y4 = value;
	}
	//--------------setX
	void incX1(int value)
	{
		x1 += value;
	}
	void incX2(int value)
	{
		x2 += value;
	}
	void incX3(int value)
	{
		x3 += value;
	}
	void incX4(int value)
	{
		x4 += value;
	}
	//--------------setY
	void incY1(int value)
	{
		y1 += value;
	}
	void incY2(int value)
	{
		y2 += value;
	}
	void incY3(int value)
	{
		y3 += value;
	}
	void incY4(int value)
	{
		y4 += value;
	}

	int getpiece()
	{
		return piece;
	}

};

class display : public pieces
{
private:
	int board[21][11]; // Y and X
	// need to create a matrix for all available open spots, 0 unoccupied 1 occupied
	int rota = 0;

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

		if (board[futureY1][getX1()] == 1 || board[futureY2][getX2()] == 1 || board[futureY3][getX3()] == 1 || board[futureY4][getX4()] == 1) // IMPORTANT instead of return true or false, try shifting this can help with collision
			return false;
		else
			return true;
	}
	void moveRight()
	{
		if (xrCollisionCheck()) { // IMPORTANT instead of return true or false, try shifting this can help with collision
			incX1(1);
			incX2(1);
			incX3(1);
			incX4(1);
		}
	}

	void moveLeft()
	{
		if (xlCollisionCheck()) { // IMPORTANT instead of return true or false, try shifting this can help with collision
			incX1(-1);
			incX2(-1);
			incX3(-1);
			incX4(-1);
		}
	}
	void moveDown()
	{
		incY1(1);
		incY2(1);
		incY3(1);
		incY4(1);
	}


	void rotate() // IMPORTANT instead of return true or false, try shifting this can help with collision
	{
		int hx1 = getX1(), hx2 = getX2(), hx3 = getX3(), hx4 = getX4(), hy1 = getY1(), hy2 = getY2(), hy3 = getY3(), hy4 = getY4() ;

		std::cout << rota;
		switch (getpiece())
		{
		case 0: // oblock no need to rotate
			break;
		case 1: // i block, 2 states of rotation
			switch (rota)
			{
			case 0:
				setX1(hx1 - 3);
				setX2(hx2 - 2);
				setX3(hx3 - 1);
				setX4(hx4);
				setY1(hy1 + 1);
				setY2(hy2);
				setY3(hy3 + 1);
				setY4(hy4 + 2);
				rota = 1;
				break;
			case 1:
				setX1(hx1 + 3);
				setX2(hx2 + 2);
				setX3(hx3 + 1);
				setX4(hx4);
				setY1(hy1 - 1);
				setY2(hy2);
				setY3(hy3 - 1);
				setY4(hy4 - 2);
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
	bool xrCollisionCheck() // IMPORTANT instead of return true or false, try shifting this can help with collision
	{
		int futureX1 = getX1() + 1; 
		int futureX2 = getX2() + 1;
		int futureX3 = getX3() + 1;
		int futureX4 = getX4() + 1;

		if (board[getY1()][futureX1] == 1 || board[getY2()][futureX2] == 1 || board[getY3()][futureX3] == 1 || board[getY4()][futureX4] == 1)
			return false;
		else
			return true;
	}
	bool xlCollisionCheck() // IMPORTANT instead of return true or false, try shifting this can help with collision
	{
		int futureX1 = getX1() - 1;
		int futureX2 = getX2() - 1;
		int futureX3 = getX3() - 1;
		int futureX4 = getX4() - 1;

		if (board[getY1()][futureX1] == 1 || board[getY2()][futureX2] == 1 || board[getY3()][futureX3] == 1 || board[getY4()][futureX4] == 1)
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


