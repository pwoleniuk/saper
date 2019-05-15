//
// Created by c on 3/19/19.
//

#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H
#include "MinesweeperBoard.h"

class MSBoardTextView
{
    MinesweeperBoard &board;
public:
    MSBoardTextView(MinesweeperBoard &plansza);
    void display();
};


#endif //SAPER_MSBOARDTEXTVIEW_H
