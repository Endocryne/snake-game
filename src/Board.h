#pragma once
#include "Drawable.h"


class Board {
public:
        Board() 
        {
                construct(0, 0);
        }
        Board(int height, int width) 
        {
                construct(height, width);
        }
        
         void initialize() { clear(); refresh(); }
         void addBorder() { box(board_win, 0, 0); }
         void clear() { wclear(board_win); addBorder(); }
         void refresh() { wrefresh(board_win); }
         void getEmptyCoordinates(int& x, int& y) {
                 while ((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' ');}
         void addAt(int y, int x, chtype c) { mvwaddch(board_win, y, x, c); }
         chtype getInput() { return wgetch(board_win); }
         void add(Drawable drawable) { addAt(drawable.getY(), drawable.getX(), drawable.getIcon()); }
private:
        WINDOW *board_win;
        int height; int width;
        void construct(int height, int width) {
                int xMax, yMax;
                getmaxyx(stdscr, yMax, xMax);
                this->height = height;
                this->width = width;
                
                board_win = newwin(height, width, (yMax - height) / 2, (xMax - width) / 2);
                wtimeout(board_win, 1000);
        }
};
