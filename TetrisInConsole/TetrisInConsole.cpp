// Levi Henderson
// Started July 14th, 2021

#include "Source.cpp"

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

    std::cout << "X1 = " << di.getX1() << " x2 = " << di.getX2() << " x3 = " << di.getX3() << " x4 = " << di.getX4() << "\n"; // DEBUG
    std::cout << "y1 = " << di.getY1() << " y2 = " << di.getY2() << " y3 = " << di.getY3() << " y4 = " << di.getY4() << "\n"; // DEBUG
    
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
