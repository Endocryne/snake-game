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
        ~SnakeGame() { apple = nullptr; }

        void processInput() 
        { 
                chtype input = board.getInput(); 
                switch (input) 
                {
                        case KEY_UP:
                        case 'w':
                                snake.setDirection(up);
                                break;
                        case KEY_DOWN:
                        case 's':
                                snake.setDirection(down);
                                break;
                        case KEY_RIGHT:
                        case 'd':
                                snake.setDirection(right);
                                break;
                        case KEY_LEFT:
                        case 'a':
                                snake.setDirection(left);
                                break;
                        case 'p':
                                board.setTimeout(-1);
                                while (board.getInput() != 'p')
                                ;
                                board.setTimeout(250);
                                break;
                        default:
                                break;
                }
        }
        void redraw() { board.refresh(); }      
        bool isOver() { return game_over; }

        
        void initialize()
        {
                apple = nullptr;
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
        void updateState()
        {
                if (apple == nullptr    ) {
                        int y, x;
                        apple = new Apple(y, x); 
                        board.getEmptyCoordinates(y, x);
                        board.add(*apple);
                }

                SnakePiece next = snake.nextHead();
                if (next.getX() != apple->getX() && next.getY() != apple->getY())
                {       
                        int emptyRow = snake.tail().getY();
                        int emptyCol = snake.tail().getX();
                        board.add(Empty(emptyRow, emptyCol));
                        snake.removePiece();
                }
                board.add(next);
                snake.addPiece(next);
        }
};
