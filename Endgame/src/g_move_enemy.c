#include "../inc/header.h"

void g_move_enemy(char **g_map, int m_x, int m_y) {

char g_enemy = 'e';
char g_enemy2 = 'a';
int g_move_h = 0;
int g_move_v = 0;
char g_buff = ' ';
int g_rnd_move = 0;
for(int i = 0; i < m_x; i++) {
	for(int j = 0; j < m_y; j++) {
		if(g_map[i][j] == g_enemy2) {
		   g_map[i][j] = g_enemy;
		}
	}
}

for(int i = 0; i < m_x; i++) {
	for(int j = 0; j < m_y; j++) {
		if(g_map[i][j] == g_enemy || g_map[i][j] == g_enemy2) {
			g_move_v = i;
			g_move_h = j;
			for(int i = 0; i < m_x; i++) {
				for(int j = 0; j < m_y; j++) {
					if(g_map[i][j] == '!') {
						if(g_move_v == i) {
							if(g_move_h < j) {
								g_rnd_move = 3;
								break;
							}
							else if (g_move_h > j) {
								g_rnd_move = 4;
								break;
							}
						}
						if(g_move_h == j) {
							if(g_move_v < i) {
								g_rnd_move = 2;
								break;
							}
							if(g_move_v > i) {
								g_rnd_move = 1;
								break;
							}
						}
					}
					else {
						g_rnd_move = rand() % 5;
						break;
					}
				}
			}
			switch(g_rnd_move) {
				case 1: {
					if(g_map[g_move_v - 1][g_move_h] != '#' && g_map[g_move_v - 1][g_move_h] != 'a'
						&& g_map[g_move_v - 1][g_move_h] != '!' && g_map[g_move_v - 1][g_move_h] != 'e'
						&& g_map[g_move_v - 1][g_move_h] != 'x' && g_map[g_move_v - 1][g_move_h] != 'o'
						&& g_map[g_move_v - 1][g_move_h] != 'w') {
						g_map[g_move_v][g_move_h] = g_buff;
						g_move_v--;
						g_buff = g_map[g_move_v][g_move_h];
						g_map[g_move_v][g_move_h] = g_enemy2;
						break;
					}
					else {
						break;
					}
				}
				case 2: {
				    if(g_map[g_move_v + 1][g_move_h] != '#' && g_map[g_move_v + 1][g_move_h] != 'a'
						&& g_map[g_move_v + 1][g_move_h] != '!' && g_map[g_move_v + 1][g_move_h] != 'e'
						&& g_map[g_move_v + 1][g_move_h] != 'x' && g_map[g_move_v + 1][g_move_h] != 'o'
						&& g_map[g_move_v + 1][g_move_h] != 'w') {
                        g_map[g_move_v][g_move_h] = g_buff;
                        g_move_v++;
                        g_buff = g_map[g_move_v][g_move_h];
                        g_map[g_move_v][g_move_h] = g_enemy2;
                        break;
                    }
                    else {
                         break;
                    }
				}
				case 3: {
					if(g_map[g_move_v][g_move_h + 1] != '#' && g_map[g_move_v][g_move_h + 1] != 'a'
						&& g_map[g_move_v][g_move_h + 1] != '!' && g_map[g_move_v][g_move_h + 1] != 'e'
						&& g_map[g_move_v][g_move_h + 1] != 'x' && g_map[g_move_v][g_move_h + 1] != 'o'
						&& g_map[g_move_v][g_move_h + 1] != 'w') {
						g_map[g_move_v][g_move_h] = g_buff;
						g_move_h++;
						g_buff = g_map[g_move_v][g_move_h];
						g_map[g_move_v][g_move_h] = g_enemy2;
						break;
					}
					else {
						break;
					}
				}
				case 4: {
					if(g_map[g_move_v][g_move_h - 1] != '#' && g_map[g_move_v][g_move_h - 1] != 'a'
						&& g_map[g_move_v][g_move_h - 1] != '!' && g_map[g_move_v][g_move_h - 1] != 'e'
						&& g_map[g_move_v][g_move_h - 1] != 'x' && g_map[g_move_v][g_move_h - 1] != 'o'
						&& g_map[g_move_v][g_move_h - 1] != 'w') {
						g_map[g_move_v][g_move_h] = g_buff;
						g_move_h--;
						g_buff = g_map[g_move_v][g_move_h];
						g_map[g_move_v][g_move_h] = g_enemy2;
						break;
					}
					else {
						break;
					}
				}
				}
			}
		}
	}
}


