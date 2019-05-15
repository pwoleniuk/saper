//
// Created by Paweł Woleniuk on 2019-03-21.
//

#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H

#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

class MSTextController{
MinesweeperBoard &board;
MSBoardTextView &view;
public:
    MSTextController(MinesweeperBoard &plansza, MSBoardTextView &display);
    void play();
};


#endif //SAPER_MSTEXTCONTROLLER_H
