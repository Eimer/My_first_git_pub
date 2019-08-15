#include "../inc/header.h"

void g_game_over2() {
	noecho();
	clear();
	int x = 1;
	char s;
	int file = open("you_died.txt", O_RDONLY);
	int rd;
	rd = read(file, &s, 1);
	while(rd > 0) {
		printw("%c", s);
		rd = read(file, &s, 1);
	}
	while(x) {
		x = getch();
		if(x == 32) {
			endwin();
			exit(0);
			break;
		}
	}
	clear();
	refresh();
}
