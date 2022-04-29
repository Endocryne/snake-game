#pragma once
#include <ncurses.h>
#include "Drawable.h"
#include <queue>
#include <iostream>

enum Direction
{
        up = -1,
        down = 1,
        left = -2,
        right = 2
};

class SnakePiece : public Drawable
{
public:
        SnakePiece(int y, int x)
        {
                this->x=x;
                this->y=y;
                this->icon='#';
        }
};

class Snake
{
        std::queue<SnakePiece> prev_pieces;
        Direction cur_direction;
public:
        Snake()
        {
                cur_direction = down;
        }
        void addPiece(SnakePiece piece) { prev_pieces.push(piece); }
        void removePiece() { prev_pieces.pop(); }
        SnakePiece tail() { return prev_pieces.front(); }
        SnakePiece head() { return prev_pieces.back(); }
        Direction getDirection() { return cur_direction; }
        void setDirection(Direction d) 
        { 
                if (cur_direction + d != 0)
                        cur_direction = d; 
        }
        SnakePiece nextHead() { 
                int row = prev_pieces.back().getY(); 
                int col = prev_pieces.back().getX(); 
                switch (cur_direction) {
                        case down:
                                row++;
                                break;
                        case up:
                                row--;
                                break;
                        case right:
                                col++;
                                break;
                        case left:
                                col--;
                                break;
                }
                return SnakePiece(row, col);
        }

};
