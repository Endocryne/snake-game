#pragma once

class Drawable {
public:
        Drawable()
        {
                y = x = 0;
                icon = ' ';
        }
        Drawable(int x, int y, char ch)
        {
                this->x = x;
                this->y = y;
                this->icon = ch;
        }
        int getX() { return x; }
        int getY() { return y; }
        char getIcon() { return icon; }
protected:
        int x, y;
        chtype icon;
};
