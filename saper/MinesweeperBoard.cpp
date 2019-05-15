//
// Created by c on 3/5/19.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MinesweeperBoard.h"
using namespace std;

MinesweeperBoard::MinesweeperBoard() {
    width=10;
    height=10;
    board[0][0].hasMine= true;
    board[1][1].isRevealed= true;
    board[0][2].hasFlag= true;
    board[0][2].hasMine= true;

}
MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode) {
    srand(time(NULL));
    this->height=height;
    this->width=width;
    this->mode=mode;
    if(mode!=0) mine=height*width*0.1*mode;
    else mine=18;
    pureField=width*height-mine;
    int mine=MinesweeperBoard::mine;
    if(mode==0)
    {
        for(int line=0;line<height;++line)
        {
            for(int col=0;col<width;++col)
            {
                if(line==col||line==0||(col==0&&line%2==0)) board[line][col].hasMine=1;
            }
        }
    }
    else
    {
        int line;
        int col;
        while(mine>0)
        {
            line=rand()%width;
            col=rand()%height;
            if(!board[line][col].hasMine)
            {
                board[line][col].hasMine=1;
                --mine;
            };
        }
    }
}
void MinesweeperBoard::debug_display() const {
    for(int line=0;line<height;++line)
    {
        for (int col=0; col<width ; ++col) {
            cout<<"[";
            if(board[line][col].hasMine) cout<<"M";
            else cout<<".";
            if(board[line][col].isRevealed) cout<<"o";
            else cout<<".";
            if(board[line][col].hasFlag) cout<<"f";
            else cout<<".";
            cout<<"]";
        }
        cout<<endl;
    }
}
int MinesweeperBoard::getBoardHeight() const {
    return height;
}
int MinesweeperBoard::getBoardWidth() const {
    return width;
}
int MinesweeperBoard::getMineCount() const {
    return mine;
}
bool MinesweeperBoard::isRightField(int x, int y) const {
    if (x < 0 || y < 0 || x > width || y > height)
        return false;
    return true;
}
int MinesweeperBoard::countMines(int x, int y) const {
    int mine=0;
    if(!board[y][x].isRevealed||!fieldOnBoard(x,y)) return -1;
    else
    {
       for(int line=(y-1);line<=(y+1);++line)
       {
           for (int col=(x-1);col<=(x+1);++col) {
               if(isRightField(col,line))
               if(board[line][col].hasMine) ++mine;
           }
       }
       if(board[y][x].hasMine) --mine;
    }
    return mine;
}
bool MinesweeperBoard::hasFlag(int x, int y) const {
	if(board[y][x].hasFlag&&x<width&&x>=0&&y<height&&y>=0) return true;
	return false;
}
bool MinesweeperBoard::isRevealed(int x, int y) const {
	if(board[y][x].isRevealed&&x<width&&x>=0&&y<height&&y>=0) return true;
	return false;
}

GameState MinesweeperBoard::getGameState() const {
    return state;
}

char MinesweeperBoard::getFieldInfo(int x, int y) const {
    if(x>=width||x<0||y>=width||y<0) return '#';
    else if(!board[y][x].isRevealed&&board[y][x].hasFlag) return 'F';
    else if(!board[y][x].isRevealed&&!board[y][x].hasFlag) return '_';
    else if(board[y][x].isRevealed&&board[y][x].hasMine) return 'x';
    else if(board[y][x].isRevealed)
    {
        char mine;
        mine=countMines(x,y)+48;
        if(mine=='0') return ' ';
        return mine;
    }
}
void MinesweeperBoard::toggleFlag(int x, int y) {
    if(!board[y][x].isRevealed&&x<width||x>=0||y<width||y>=0&&state==RUNNING)
    {
        board[y][x].hasFlag=!board[y][x].hasFlag;
    }
}
bool MinesweeperBoard::fieldOnBoard(int x, int y) const {
    if(x>=width||x<0) return false;
    if(y>=height||y<0) return false;
    return true;
}
void MinesweeperBoard::revealField(int x, int y) {
    if(board[y][x].isRevealed)
        return;
    if(fieldOnBoard(x,y)&&state==RUNNING&&!board[y][x].hasFlag)
    {
        if(firstStep&&mode!=DEBUG)
        {
            firstStep= false;
            int line;
            int col;
            int thismine=1;
            while(thismine>0)
            {
                line=rand()%width;
                col=rand()%height;
                if(!board[line][col].hasMine)
                {
                    board[line][col].hasMine=1;
                    --thismine;
                }

            }
            board[y][x].hasMine=0;
            board[y][x].isRevealed=1;
            --pureField;
        }
        else
        {
            if(board[y][x].hasMine)
            {
                board[y][x].isRevealed=1;
                state=FINISHED_LOSS;
            }

            else
            {
                board[y][x].isRevealed=1;
                --pureField;
                if(pureField==0) state=FINISHED_WIN;
                for(int line=y-1;line<=y+1;++line)
                {
                    for (int col=x-1;col<=x+1;++col) {
                        if(!board[line][col].hasMine&&fieldOnBoard(col,line)) revealField(col,line);
                    }

                }


            }

        }
    }
}
