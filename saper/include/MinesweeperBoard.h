//
// Created by c on 3/5/19.
//

#ifndef SAPER_MINESWEEPERBOARD_H
#define SAPER_MINESWEEPERBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine=false;
    bool isRevealed=false;
    bool hasFlag=false;
};
class MinesweeperBoard
{
    Field board[100][100];
    int width;
    int height;
    GameMode mode;
    int mine;
    GameState state=RUNNING;
    int pureField;
    bool firstStep=true;
    bool isRightField(int x, int y) const;
public:
    void debug_display()  const;
    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode );
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int x, int y) const;
    bool hasFlag(int x, int y) const;
    bool isRevealed(int x, int y) const;
    GameState getGameState() const;
    char getFieldInfo(int x, int y) const;
    void toggleFlag(int x, int y);
    void revealField(int x, int y);
    bool fieldOnBoard(int x,int y) const;
    void setBoardWidth(int x);
    void setBoardHeight(int y);
    GameMode getGameMode()const;
    void setGameMode(GameMode mode);
    void resetBoard();
};
#endif //SAPER_MINESWEEPERBOARD_H
