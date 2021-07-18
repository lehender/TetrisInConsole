// Levi Henderson
// Started July 14th, 2021

#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Header.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

bool playing = true;
bool keypress = false;
display di;

int i = 0;

void setup()
{
 
}


void input()
{

    keypress = true;

    if (_kbhit() && keypress)
    {
        switch (_getch())
        {
        case KEY_UP:
            std::cout << "UP";
            di.rotate();
            keypress = false;
            break;
        case KEY_LEFT:
            di.moveLeft();
            keypress = false;
            break;
        case KEY_RIGHT:
            di.moveRight();
            keypress = false;
            break;
        case KEY_DOWN:
            di.moveDown();
            std::cout << "DOWN";
            //keypress = false;
            break;
        }
    }

}

void draw()
{
    system("cls");
    di.drawTable();

    std::cout << "X1 = " << di.getPosition(0) << " x2 = " << di.getPosition(1) << " x3 = " << di.getPosition(2) << " x4 = " << di.getPosition(3) << "\n"; // DEBUG
    std::cout << "y1 = " << di.getPosition(4) << " y2 = " << di.getPosition(5) << " y3 = " << di.getPosition(6) << " y4 = " << di.getPosition(7) << "\n"; // DEBUG
    
    std::cout << "piece = " << di.getpiece() << " rotate = " << /*di.getrotate() <<*/ "\n"; // DEBUG
}

void logic()
{

    while (di.piecePresent() == false) { // checks if piece is present
            //di.callPiece();
            di.setpiecePresent(di.callPiece()); // i put callpiece to return a bool balue, false if the piece was just called and true if its a new piece, this allows me to make sure the same peice is not called twice.
    }
    if (di.collisoncheck()) {
            di.advance();
    }
    else {
        di.addToArray();
        di.setpiecePresent(false);
    }
  
}

static void tempo()
{
    bool advance = true;
    if (advance)
    {

    }

}


int main()
{
    setup();
    while (playing)
    {
        draw();
        logic();
        input();
        Sleep(50);
    }
}
