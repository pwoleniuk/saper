//
// Created by c on 3/19/19.
//

#include "MSBoardTextView.h"
#include <iostream>
using namespace std;
MSBoardTextView::MSBoardTextView(MinesweeperBoard &plansza)
    :board(plansza)
{
}
void MSBoardTextView::display()
{
    for(int line=0; line<board.getBoardHeight(); ++line)
    {
        for(int col=0; col<board.getBoardWidth(); ++col)
            cout<<board.getFieldInfo(col,line)<<" ";
        cout<<endl;
    }

}
