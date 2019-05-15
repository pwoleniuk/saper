#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
MSSFMLView::MSSFMLView()
{
    MSSFMLView::MSSFMLView(MSBoardTextView &display)
    :view(display)
    {
    }
    void MSSFMLView::draw(sf::RenderWindow &win)
    {
    float sizeField=50;
    int width=10, height=3;
    sf::Vector2f position(50.f,250.f);
    sf::VertexArray win(sf::Lines);
    for(int line=0;line<=height;++line)
    {
        board.append(sf::Vector2f(position.x,position.y+line*sizeField));
        board.append(sf::Vector2f(position.x+width*sizeField,position.y+line*sizeField));
    }
    for(int col=0;col<=width;++col)
    {
        board.append(sf::Vector2f(position.x+col*sizeField,position.y));
        board.append(sf::Vector2f(position.x+col*sizeField,height*sizeField+position.y));
    }
        win.draw();
    }
}
