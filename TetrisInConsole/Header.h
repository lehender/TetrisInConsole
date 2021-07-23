#pragma once

#include <array>


class pieces
{
private:
	constexpr static std::size_t numXYPositions = 8;
	std::array<int, numXYPositions> position; // each tetris piece has 4 squares

	int lastpiece = 0, piece = 0;
	bool piecepresent = false;

public:
	bool callPiece(); // there are 7 pieces, so we need 7 random numbers. if we want one to be more likely we can raise this number and assign more numbers to a specific piece.

	void Oblock();

	void iblock();

	void jblock();

	void lblock();
		
	void sblock();

	void zblock();

	void tblock();

	void advance();

	bool piecePresent();

	void setpiecePresent(bool);

	//--------------getX
	int getPosition(int ); // x1,x2,x3,x4,y1,y2,y3,y4

	//--------------setX
	void modPosition(int, int);

	int getpiece();

	int getNumXYPositions();

};

class display : public pieces
{
private:
	constexpr static std::size_t columns = 12;
	constexpr static std::size_t rows = 22;
	std::array<std::array<int, columns>, rows> board; // Y and X

	int rota = 0;

public:
	bool ycollisioncheck();

	void moveLeftRightDown(int,int, int);

	void rotate(); // IMPORTANT instead of return true or false, try shifting this can help with collision

	void xlrCollisionCheck(int, int); // IMPORTANT instead of return true or false, try shifting this can help with collision

	void addToArray();

	void drawTable();

	int getRota();

	void setRota(int);

};


