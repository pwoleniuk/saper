#ifndef MSSFMLCONTROLLER_H
#define MSSFMLCONTROLLER_H
#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>


class MSSFMLController
{
    MSSFMLView& view;
    MinesweeperBoard& board;
    public:
        MSSFMLController(MSSFMLView& display, MinesweeperBoard& plansza);
        void play(sf::RenderWindow &win);
        void intro(sf::RenderWindow &win);
        void run(sf::RenderWindow &win);
};
#endif // MSSFMLCONTROLLER_H
