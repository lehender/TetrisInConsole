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

    std::cout << di.getX1() << " " << di.getX2() << " " << di.getX3() << " " << di.getX4() << "\n"; // DEBUG
    std::cout << di.getY1() << " " << di.getY2() << " " << di.getY3() << " " << di.getY4() << "\n"; // DEBUG
}

void logic()
{

    if (di.piecePresent() == false) {
        di.callPiece();
        di.setpiecePresent(true);
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

    while (playing)
    {
        setup();
        draw();
        logic();
        input();
        Sleep(50);
    }
}
