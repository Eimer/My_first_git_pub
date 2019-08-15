#include "../inc/header.h"

void g_startscreen() {
	noecho();
	int x = 1;
	char s;
	int file = open("start_screen.txt", O_RDONLY);
	int rd;
	rd = read(file, &s, 1);
	while(rd > 0) {
		printw("%c", s);
		rd = read(file, &s, 1);
	}
	while(x) {
        x = getch();
        if(x == 32) {
			break;
		}
		if(x == 113){
			endwin();
			exit(0);
		}
	}
	refresh();
	clear();
}

