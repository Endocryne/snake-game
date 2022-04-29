#pragma once

#include <ncurses.h>
#include "Drawable.h"

class Empty : public Drawable {
public:
        Empty(int y, int x)
        {
                this->x = x;
                this->y = y;
                this->icon= ' ';
        }

};
