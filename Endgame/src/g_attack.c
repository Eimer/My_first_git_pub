#include "../inc/header.h"

void g_attack(char **g_map, int g_move_v, int g_move_h, int m_x, int m_y) {
	for(int i = g_move_v - 2; i <= g_move_v + 2; i++) {
		for(int j = g_move_h - 2; j <= g_move_h + 2; j++) {
			if(i <= 0) {
				i = i + 1;
				j = g_move_h - 2;
			}
			if(i >= m_x) {
				continue;
				m_y = 2;
			}
			if(g_map[i][j] == '#') {
				j++;
			}
			if(g_map[i][j] == 'a' || g_map[i][j] == 'e') {
				g_map[i][j] = '*';
			}
			else {
				if((g_map[i][j] == ' ' || g_map[i][j] == ':') && g_map[i][j] != '!' && g_map[i][j] != '*')
					mvprintw(i, j, "/");
					refresh();
					usleep(6000);
					mvprintw(i, j, " ");
					refresh();
			}
		}
	}
}
