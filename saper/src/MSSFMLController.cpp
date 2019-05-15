#include "MSSFMLController.h"
#include<iostream>
using namespace std;
MSSFMLController::MSSFMLController(MSSFMLView& display,MinesweeperBoard& plansza)
:view(display),board(plansza)
{
}
void MSSFMLController::play(sf::RenderWindow &win)
{
    if(view.getState()==0)
    {
        intro(win);
    }
    else if(view.getState()==1)
    {
        run(win);
    }
    else if(view.getState()==2)
    {

    }

}
void MSSFMLController::intro(sf::RenderWindow &win)
{
    sf::Event event;
        while(win.pollEvent(event))
        {
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button==sf::Mouse::Left)
                {
                        if(event.mouseButton.x>=55&&event.mouseButton.x<=141&&event.mouseButton.y>=415&&event.mouseButton.y<=443)
                        {
                            board.setBoardWidth(10);
                            board.setBoardHeight(10);
                        }
                        else if(event.mouseButton.x>=205&&event.mouseButton.x<=291&&event.mouseButton.y>=415&&event.mouseButton.y<=443)
                        {
                            board.setBoardWidth(20);
                            board.setBoardHeight(15);
                        }
                        else if(event.mouseButton.x>=355&&event.mouseButton.x<=441&&event.mouseButton.y>=415&&event.mouseButton.y<=443)
                        {
                            board.setBoardWidth(30);
                            board.setBoardHeight(20);
                        }
                        else if(event.mouseButton.x>=55&&event.mouseButton.x<=141&&event.mouseButton.y>=490&&event.mouseButton.y<=518)
                        {
                            board.setGameMode(EASY);
                        }
                        else if(event.mouseButton.x>=205&&event.mouseButton.x<=291&&event.mouseButton.y>=490&&event.mouseButton.y<=518)
                        {
                            board.setGameMode(NORMAL);
                        }
                        else if(event.mouseButton.x>=355&&event.mouseButton.x<=441&&event.mouseButton.y>=490&&event.mouseButton.y<=518)
                        {
                            board.setGameMode(HARD);
                        }
                        else if(event.mouseButton.x>=561&&event.mouseButton.x<=637&&event.mouseButton.y>=431&&event.mouseButton.y<=507&&board.getBoardHeight()>9&&board.getGameMode()>0)
                        {
                            board.resetBoard();
                            view.setState(Run);
                        }

                }
            }
        }
}
void MSSFMLController::run(sf::RenderWindow &win)
{
    sf::Event event;
        while(win.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                int wiersz = (event.mouseButton.y-view.getPosition().y)/view.getSizeField();
                int kolumna =(event.mouseButton.x-view.getPosition().x)/view.getSizeField();
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    board.revealField(kolumna, wiersz); // albo na odwrót - zależnie jak to sobie zdefiniowaliście
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                {
                    board.toggleFlag(kolumna, wiersz); // albo na odwrót - zależnie jak to sobie zdefiniowaliście
                }
                if(!board.getGameState()==0)
        {
            view.setState(Outro);
        }
            }

        }
}
