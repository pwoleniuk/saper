#include <SFML/Graphics.hpp>
#include <MinesweeperBoard.h>
#include <MSBoardTextView.h>
#include <MSTextController.h>
#include <MSSFMLView.h>
#include <MSSFMLController.h>
#include <iostream>
using namespace std;
int main()
{
    sf::RenderWindow win(sf::VideoMode(800, 600), "My window");
    MinesweeperBoard board(7,4,DEBUG);
    MSSFMLView view (board);
    MSSFMLController cont(view,board);

    // rysujemy
    while (win.isOpen())
    {
        // obsługa zdarzeń
        //
        cont.play(win);
        win.clear();
        view.draw(win);   // wywołujemy funkcję draw i dostarczamy jej okno na którym ma odbyć sie rysowanie
        win.display();
    }

}
