#include "../inc/header.h"

void g_move_hero(char **g_map, int m_x, int m_y, int g_hero_hp) {
	keypad(stdscr, true);
	halfdelay(2);
	start_color();
	init_pair(1,  COLOR_RED,     COLOR_BLACK);
	char g_hero = '!';
	char g_buff = g_map[m_x - 2][m_y - 2];
	g_map[m_x - 2][m_y - 2] = g_hero;
	int g_move_h = 0;
	int g_move_v = 0;
	int g_mv = 0;
	int g_p = 0;
	noecho();
	for (int i = 0; i < m_x; i++) {
		for(int j = 0; j < m_y; j++) {
			if(g_map[i][j] == g_hero) {
				g_move_v = i;
				g_move_h = j;
			}
		}
	}
	while(true) {
		g_p = 71;
		for(int i = g_move_v - 1; i <= g_move_v + 1; i++) {
                for(int j = g_move_h - 1; j <= g_move_h + 1; j++) {
					if((g_map[i][j] == 'e' || g_map[i][j] == 'a') && g_hero_hp != 0) {
						g_hero_hp--;
					}
					if(g_map[i][j] == 'w'){
						g_hero_hp = 15;
						g_map[i][j] = ' ';
					}
					if(g_hero_hp == 0) {
						g_game_over2();
					}
				}
		}
		for(int j = 0; j < g_hero_hp; j++) {
			mvprintw(3, 67, "HP:");
			attron(COLOR_PAIR(1));
			mvprintw(3, g_p, "+");
			attroff(COLOR_PAIR(1));
			g_p++;
		}
		mvprintw(7, 67, "Use arrows to move.");
		mvprintw(8, 67, "Use <1> to attak.");
		mvprintw(9, 67, "Pick up <W> to heal");
		mvprintw(10, 67, "Exit is in <X>");		

		refresh();
		if(g_move_v == 1 && g_move_h == 1) {
			clear();
			endwin();
			break;
		}
		g_mv = getch();
		switch (g_mv) {
			case ERR: {
				g_move_enemy(g_map, m_x, m_y);
				g_print_map(g_map, m_x, m_y);
				break;
			}
			case 259:{
				if(g_map[g_move_v - 1][g_move_h] != '#' && g_map[g_move_v - 1][g_move_h] != 'a'
					&& g_map[g_move_v - 1][g_move_h] != 'e') {
					g_map[g_move_v][g_move_h] = g_buff;
					g_move_v--;
					g_buff = g_map[g_move_v][g_move_h];
					g_map[g_move_v][g_move_h] = g_hero;
					g_move_enemy(g_map, m_x, m_y);
					g_print_map(g_map, m_x, m_y);
					break;
				}
				else {
					break;
				}
			}
			case 258:{
				if(g_map[g_move_v + 1][g_move_h] != '#' && g_map[g_move_v + 1][g_move_h] != 'a'
					&& g_map[g_move_v - 1][g_move_h] != 'e') {
					clear();
					g_map[g_move_v][g_move_h] = g_buff;
					g_move_v++;
					g_buff = g_map[g_move_v][g_move_h];
					g_map[g_move_v][g_move_h] = g_hero;
					g_move_enemy(g_map, m_x, m_y);
					g_print_map(g_map, m_x, m_y);
					break;
				}
				else {
					break;
				}
			}
			case 261: {
				if(g_map[g_move_v][g_move_h + 1] != '#' && g_map[g_move_v][g_move_h + 1] != 'a'
					&& g_map[g_move_v][g_move_h + 1] != 'e') {
					clear();
					g_map[g_move_v][g_move_h] = g_buff;
					g_move_h++;
					g_buff = g_map[g_move_v][g_move_h];
					g_map[g_move_v][g_move_h] = g_hero;
					g_move_enemy(g_map, m_x, m_y);
					g_print_map(g_map, m_x, m_y);
					break;
				}
				else {
                    break;
                }
			}
			case 260: {
				if(g_map[g_move_v][g_move_h - 1] != '#' && g_map[g_move_v][g_move_h - 1] != 'e'
					&& g_map[g_move_v][g_move_h - 1] != 'a') { 
					clear();
					g_map[g_move_v][g_move_h] = g_buff;
					g_move_h--;
					g_buff = g_map[g_move_v][g_move_h];
					g_map[g_move_v][g_move_h] = g_hero;
					g_move_enemy(g_map, m_x, m_y);
					g_print_map(g_map, m_x, m_y);
					break;
                }
                else {
                     break;
                }
			case 49: {
				g_attack(g_map, g_move_v, g_move_h, m_x, m_y);
				g_print_map(g_map, m_x, m_y);
				break;
			}
			}
	}
}
	refresh();
}
