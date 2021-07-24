#pragma once

#include <array>
#include <windows.h>



class pieces
{
private:
	constexpr static std::size_t numXYPositions = 8;
	std::array<int, numXYPositions> position; // each tetris piece has 4 squares

	std::array<int, numXYPositions> nextPositionArray; // each tetris piece has 4 squares

	int lastpiece = 1, piece = 1, nextpiece = 1;
	bool piecepresent = false;

public:
	bool callPiece(); // there are 7 pieces, so we need 7 random numbers. if we want one to be more likely we can raise this number and assign more numbers to a specific piece.

	int getNextPiece();

	int setNextPiece();

	void Oblock(std::array<int, numXYPositions>&);

	void iblock(std::array<int, numXYPositions>&);

	void jblock(std::array<int, numXYPositions>&);

	void lblock(std::array<int, numXYPositions>&);
		
	void sblock(std::array<int, numXYPositions>&);

	void zblock(std::array<int, numXYPositions>&);

	void tblock(std::array<int, numXYPositions>&);

	void advance(int);

	bool piecePresent();

	void setpiecePresent(bool);

	//--------------getX
	int getPosition(int ); // x1,x2,x3,x4,y1,y2,y3,y4

	int getNextPosition(int);

	//--------------setX
	void modPosition(int, int);

	int getpiece();

	int getNumXYPositions();

};

class display : public pieces
{
private:
	constexpr static std::size_t columns = 24;
	constexpr static std::size_t rows = 22;
	std::array<std::array<int, columns>, rows> board; // Y and X
	
	std::string nextPieceText= "Next Piece";
	std::string scoreText = "Score:";
	std::string tetrisText = "  TETRIS    ";

	int rota = 0, score = 50;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	bool ycollisioncheck();

	void moveLeftRightDown(int,int, int);

	void rotate(); // IMPORTANT instead of return true or false, try shifting this can help with collision

	void xlrCollisionCheck(int, int); // IMPORTANT instead of return true or false, try shifting this can help with collision

	void addToArray();

	void drawTable();

	int getRota();

	void setRota(int);

	void drawPieceinNext(int,int);

	void drawPieceinBoard(int, int);

	void drawPiece(int);

	void color(std::string );

	void checkLines();

	bool failCheck();

	int getScore();

};


