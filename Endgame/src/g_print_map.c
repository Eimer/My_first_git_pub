#include "../inc/header.h"

void g_print_map(char **g_map, int m_x, int m_y) {

start_color();
init_pair(1,  COLOR_RED,     COLOR_BLACK);
init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
init_pair(4,  COLOR_MAGENTA, COLOR_BLACK);
init_pair(7,  COLOR_MAGENTA, COLOR_CYAN);
	clear();
	for(int i = 0; i < m_x; i++) {
		for(int j = 0; j < m_y; j++) {
			if(g_map[i][j] != '.' || g_map[i][j] != ':') {
				if(g_map[i][j] == '#'){
					attron(COLOR_PAIR(3));
					printw("%c", g_map[i][j]);
					attroff(COLOR_PAIR(3));
				}
				else if(g_map[i][j] == 'x') {
					attron(COLOR_PAIR(2));
					printw("%c", g_map[i][j]);
					attroff(COLOR_PAIR(2));
					}
				else if(g_map[i][j] == 'e' || g_map[i][j] == 'a') {
					attron(COLOR_PAIR(1));
					printw("%c", g_map[i][j]);
					attroff(COLOR_PAIR(1));
					}
				else if(g_map[i][j] == '!') {
					attron(COLOR_PAIR(7));
					printw("%c", g_map[i][j]);
					attroff(COLOR_PAIR(7));
					}
				else if(g_map[i][j] == '/' || g_map[i][j] == '*' || g_map[i][j] == 'w') {
						printw("%c", g_map[i][j]);
					}
				else {
					printw("%c", ' ');
				}
			}
		}
			printw("%c", '\n');
	}
	g_print_stats();
refresh();
}
