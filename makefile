all: main

main: main.cpp src/Board.h src/SnakeGame.h src/Drawable.h src/Apple.h src/Empty.h src/Snake.h
	g++ main.cpp -lncurses -o main
