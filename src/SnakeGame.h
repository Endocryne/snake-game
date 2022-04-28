#pragma once
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

#include "Board.h"
#include "Drawable.h"
#include "Apple.h"
#include "Empty.h"
#include "Snake.h"

class SnakeGame
{
        Board board;
        Apple *apple;
        bool game_over;
        Snake snake;

public:
        SnakeGame(int width, int height)
        {
                board = Board(height, width);
                initialize();
        }
        ~SnakeGame() { delete apple; }

        void processInput() { chtype input = board.getInput(); }
        void redraw() { board.refresh(); }      
        bool isOver() { return game_over; }

        void updateState()
        {
                int y, x;
                board.getEmptyCoordinates(y, x);
                if (apple != NULL) {
                        int y, x;
                        apple = new Apple(y, x); 
                        board.getEmptyCoordinates(y, x);
                        board.add(Empty(apple->getY(), apple->getX())); 
                        board.add(*apple);
                }

                SnakePiece next = snake.nextHead();
                if (next.getX() == apple->getX() && next.getY()!=apple->getY())
                {       
                        int emptyRow = snake.tail().getY();
                        int emptyCol = snake.tail().getX();
                        board.add(Empty(emptyRow, emptyCol));
                        snake.removePiece();
                }
                board.add(next);
                snake.addPiece(next);
        }
        void initialize()
        {
                apple = NULL;
                board.initialize();
                game_over = false;
                srand(time(NULL));
                snake.setDirection(down);
                
                SnakePiece next = SnakePiece(1, 1);
                board.add(next);
                snake.addPiece(next);

                next = snake.nextHead();
                board.add(next);
                snake.addPiece(next);

                next = snake.nextHead();
                board.add(next);
                snake.addPiece(next);

                snake.setDirection(right);

                next = snake.nextHead();
                board.add(next);
                snake.addPiece(next);
        }
};
