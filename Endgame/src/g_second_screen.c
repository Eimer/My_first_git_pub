#include "../inc/header.h"

void g_second_screen(char *username, int m_x, int m_y) {
	echo();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	char s;
	int file = open("hero.txt", O_RDONLY);
	while(read(file, &s, 1) > 0) {
		printw("%c", s);
	}
	attroff(COLOR_PAIR(1));
	move(m_x - 20, m_y);
	printw("Enter your name: ");
	getstr(username);
	refresh();
	clear();
}

