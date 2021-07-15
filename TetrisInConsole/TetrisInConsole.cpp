// Levi Henderson
// Started July 14th, 2021

#include "Source.cpp"

bool playing = true;
display di;

int i = 0;

void setup()
{

}

void draw()
{
    system("cls");
    di.drawTable();

    std::cout << di.getX1() << " " << di.getX2() << " " << di.getX3() << " " << di.getX4() << "\n";
    std::cout << di.getY1() << " " << di.getY2() << " " << di.getY3() << " " << di.getY4() << "\n";
}

void logic()
{

    if (di.piecePresent() == false) {
        di.callPiece();
        di.setpiecePresent(true);
    }
    di.advance();
  
}


int main()
{

    while (playing)
    {
        setup();
        draw();
        logic();
        Sleep(1000);
    }
}
