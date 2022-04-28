#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "src/Board.h"
#include "src/SnakeGame.h"
#include "src/Drawable.h"

#define BOARD_DIM 17
#define BOARD_ROWS BOARD_DIM * 2.5
#define BOARD_COLS BOARD_DIM
int main(int argc, char **argv) {
        initscr();
        refresh();
        noecho();
        curs_set(0);
        SnakeGame game = SnakeGame(BOARD_ROWS, BOARD_COLS);
        while (!game.isOver()) {
                game.processInput();
                game.updateState();
                game.redraw();
        }
        getch();
        endwin();
        return 0;

}
