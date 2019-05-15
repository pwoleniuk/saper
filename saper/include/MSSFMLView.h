#ifndef MSSFMLVIEW_H
#define MSSFMLVIEW_H
#include "MSBoardTextView.h"
#include <SFML/Graphics.hpp>
enum StateWindow{Intro,Run,Outro};
class MSSFMLView
{
    MinesweeperBoard &view;
    float sizeField;
    sf::Vector2f position;
    StateWindow window;;

public:
    MSSFMLView(MinesweeperBoard &display);
    void draw(sf::RenderWindow &win);
    float getSizeField()const;
    StateWindow getState()const;
    void setState(StateWindow w);
    sf::Vector2f getPosition()const;
    void intro(sf::RenderWindow &win);
    void run(sf::RenderWindow &win);
    void outro(sf::RenderWindow &win);
};

#endif // MSSFMLVIEW_H
