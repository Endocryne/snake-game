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
                this->y = y;
                this->x = x;
                this->icon = ch;
        }

        int getY() 
        { 
                return y; 
        }
        int getX() 
        {
                return x; 
        }
        chtype getIcon() { return icon; }
        
protected:
        int y, x;
        chtype icon;
};
