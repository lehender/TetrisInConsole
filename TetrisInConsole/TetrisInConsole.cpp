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
bool keypress = true;
display di;

int i = 0;

void setup()
{
 
}


void input()
{

    //if (_kbhit() == NULL) want to work out a way to make sure key is released before allowing another key press, except for DOWN
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
            di.moveLeftRightDown(0,-1,2); //start at 0, change x by -1, divide total location points by 2
            keypress = false;
            break;
        case KEY_RIGHT:
            di.moveLeftRightDown(0, 1, 2);
            keypress = false;
            break;
        case KEY_DOWN:
            di.moveLeftRightDown(4, 1, 1);
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
    
    std::cout << "piece = " << di.getpiece() << " rotate = " << di.getRota() << "\n"; // DEBUG
}

void logic()
{

    while (di.piecePresent() == false) { // checks if piece is present
            //di.callPiece();
            di.setpiecePresent(di.callPiece()); // i put callpiece to return a bool balue, false if the piece was just called and true if its a new piece, this allows me to make sure the same peice is not called twice.
    }
    if (di.ycollisioncheck()) {
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
