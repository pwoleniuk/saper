//
// Created by Paweł Woleniuk on 2019-03-21.
//

#include "MSTextController.h"
#include <iostream>
using namespace std;
MSTextController::MSTextController(MinesweeperBoard &plansza, MSBoardTextView &display)
:board(plansza),view(display)
{
}
void MSTextController::play() {
    view.display();
    while(board.getGameState()==RUNNING)
    {
        char choice;
        cin>>choice;
        switch (choice)
        {
            case 'F':
                {
                    int x,y;
                    cin>>x>>y;
                    board.toggleFlag(x,y);
                    break;
                }
            case 'R':
                {
                    int x,y;
                    cin>>x>>y;
                    board.revealField(x,y);
                    break;
                }
        }
        view.display();
    }
    switch (board.getGameState())
    {
        case 1:
            cout<<"GAME WIN";
            break;
        case 2:
            cout<<"GAME LOSS";
            break;
    }

}
