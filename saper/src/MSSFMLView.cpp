#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include<vector>
using namespace std;
MSSFMLView::MSSFMLView(MinesweeperBoard &display)
    :view(display)
{
    window=Intro;
}
void MSSFMLView::draw(sf::RenderWindow &win)
{

    sf::Texture backg;
    backg.loadFromFile("background.jpg");
    sf::Sprite background;
    background.setTexture(backg);
    win.draw(background);

    if(window==Intro)
    {
        intro(win);
    }
    else if(window==Run)
    {
        run(win);
    }
else if(window==Outro)
{
        outro(win);
}
}
float MSSFMLView::getSizeField()const
{
    return sizeField;
}
StateWindow MSSFMLView::getState()const{
return window;
}
void MSSFMLView::setState(StateWindow w)
{
    window=w;
}
sf::Vector2f MSSFMLView::getPosition()const
{
    return position;
}
void MSSFMLView::intro(sf::RenderWindow &win)
{
    sf::Texture button;
        sf::Texture start;
        button.loadFromFile( "button.png" );
        start.loadFromFile("start.png");
        sf::Sprite image1;
        sf::Sprite image2;
        image1.setTexture(button);
        image1.setPosition(50.f, 400.f);
        win.draw(image1);
        image1.setPosition(200.f,400.f);
        win.draw(image1);
        image1.setPosition(350.f,400.f);
        win.draw(image1);
        image1.setPosition(50.f,475.f);
        win.draw(image1);
         image1.setPosition(200.f,475.f);
        win.draw(image1);
         image1.setPosition(350.f,475.f);
        win.draw(image1);
        image2.setTexture(start);
        image2.setPosition(550.f, 410.f);
        win.draw(image2);
         sf::Font font;
    bool first=true;
    if (!font.loadFromFile("DejaVuSans.ttf")&&first)
    {
        first=false;
    }
    sf::Text sample;
    sample.setFont(font);
    sample.setColor(sf::Color::Black);
    sample.setString("Saper");
    sample.setCharacterSize(50); // in pixels, not points!
    sample.setPosition(330.f, 30.f);
    sample.setStyle(sf::Text::Bold);
    win.draw(sample);
    sample.setStyle(sf::Text::Regular);
    sample.setString("Pawel Woleniuk");
    sample.setCharacterSize(15);
    sample.setPosition(530.f, 200.f);
    win.draw(sample);
    sample.setString("nr 249290");
    sample.setCharacterSize(15);
    sample.setPosition(530.f, 220.f);
    win.draw(sample);
    sample.setString("grupa pon-13");
    sample.setCharacterSize(15);
    sample.setPosition(530.f, 240.f);
    win.draw(sample);
    vector<sf::Text> buttons;
    sf::Text button1;
    button1.setFont(font);
    button1.setCharacterSize(15);
    for(float line=415.f;line<=490.f;line=line+75)
    {
        for(float col=72.f;col<=372;col=col+150)
        {
            button1.setPosition(col, line);
            buttons.push_back(button1);
        }
    }
    buttons[3].setPosition(80.f,490.f);
    buttons[4].setPosition(215.f,490.f);
    buttons[5].setPosition(377.f,490.f);
    buttons[0].setString("10x10");
    buttons[1].setString("20x15");
    buttons[2].setString("30x20");
    buttons[3].setString("EASY");
    buttons[4].setString("NORMAL");
    buttons[5].setString("HARD");
    buttons.push_back(button1);
    buttons[6].setPosition(585.f,455.f);
    buttons[6].setString("Start");
    if(view.getBoardWidth()==10&&view.getBoardHeight()==10)
    {
        buttons[0].setColor(sf::Color::Red);
    }
    else if(view.getBoardWidth()==20&&view.getBoardHeight()==15)
    {
        buttons[1].setColor(sf::Color::Red);
    }
    else if(view.getBoardWidth()==30&&view.getBoardHeight()==20)
    {
        buttons[2].setColor(sf::Color::Red);
    }
    if(view.getGameMode()==1)
    {
        buttons[3].setColor(sf::Color::Red);
    }
    else if(view.getGameMode()==2)
    {
        buttons[4].setColor(sf::Color::Red);
    }
    else if(view.getGameMode()==3)
    {
        buttons[5].setColor(sf::Color::Red);
    }
  for(int i=0;i<=6;++i)
    {
        win.draw(buttons[i]);
    }
}
void MSSFMLView::run(sf::RenderWindow &win)
{
    vector<sf::Text> board_field;
        sf::Text sample;
        if(view.getBoardWidth()==10)
        {
                position.x= 215.f;
                sample.setCharacterSize(15);
        }
        else if(view.getBoardWidth()==20)
        {
              position.x= 150.f;
              sample.setCharacterSize(12);
        }
        else
        {
              position.x= 100.f;
              sample.setCharacterSize(10);
        }

    position.y=100.f;
    sizeField=(win.getSize().y-position.y*2)/view.getBoardHeight();
    int width=view.getBoardWidth();
    int height=view.getBoardHeight();
    sf::VertexArray board_grind(sf::Lines);
    for(int line=0; line<=height; ++line)
    {
        board_grind.append(sf::Vector2f(position.x,position.y+line*sizeField));
        board_grind.append(sf::Vector2f(position.x+width*sizeField,position.y+line*sizeField));
    }
    for(int col=0; col<=width; ++col)
    {
        board_grind.append(sf::Vector2f(position.x+col*sizeField,position.y));
        board_grind.append(sf::Vector2f(position.x+col*sizeField,height*sizeField+position.y));
    }
    sf::Font font;
    bool first=true;
    if (!font.loadFromFile("DejaVuSans.ttf")&&first)
    {
        first=false;
    }

    for(int line=0; line<height; ++line)
    {
        for(int col=0; col<width; ++col)
        {
            sample.setFont(font);
            sample.setString(view.getFieldInfo(col,line));// in pixels, not points!
            sample.setPosition(position.x+10+(sizeField*col),position.y+5+(sizeField*line));
            board_field.push_back(sample);
        }
    }
    win.clear();
    for(int i=0; i<width*height; ++i)
    {
        win.draw(board_field[i]);
    }
    win.draw(board_grind);
}


void MSSFMLView::outro(sf::RenderWindow &win)
{
             sf::Font font;
    bool first=true;
    if (!font.loadFromFile("DejaVuSans.ttf")&&first)
    {
        first=false;
    }
    sf::Text sample;
    sample.setFont(font);
    sample.setColor(sf::Color::Black);
    if(view.getGameState()==1)
    {
            sample.setString("You Win");
            sample.setPosition(330.f, 30.f);
    }
    else
    {
            sample.setString("You Lose");
            sample.setPosition(330.f, 30.f);
    }
    sample.setCharacterSize(50); // in pixels, not points!
    sample.setStyle(sf::Text::Bold);
    win.draw(sample);

}
