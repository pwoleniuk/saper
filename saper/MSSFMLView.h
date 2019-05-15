#ifndef MSSFMLVIEW_H
#define MSSFMLVIEW_H
#include "MSBoardTextView.h"

class MSSFMLView
{
    MSBoardTextView &view;
    public:
        MSSFMLView(MSBoardTextView &display);
        void draw(sf::RenderWindow &win)const;
};

#endif // MSSFMLVIEW_H
