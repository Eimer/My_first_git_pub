#include "../inc/header.h"
void g_rendmap(char **g_map, int m_x, int m_y) {
                int i = 0;
				int j = 0;
				int g_rnd_st_x1 = rand() % 12;
                int g_rnd_st_y1 = 25 + rand() % 30;
                int g_rnd_st_x2 = 18 + rand() % 4;
                int g_rnd_st_y2 = rand() % 10;
                int g_rnd_sizex = 4 + rand() % 7;
                int g_rnd_sizey = 8 + rand() % 15;
				int g_rnd1 = 6 + rand() % 10;
				int g_rnd2_x = 4 + rand() % 6;
				int g_rnd2_y = 7 + rand() % 10;
        for(i = 0; i < m_x; i++) {
            for(j = 0; j < m_y; j++){
                    if(i == 0 || j == 0 || i == m_x - 1 || j == m_y - 1){
                        g_map[i][j] = '#';
                    }
                    else {
                        g_map[i][j] = ' ';
                    }
					if(g_map[i][j] != '#') {
						g_rend_room1(g_map, i, j, g_rnd1);
						g_rend_room2(g_map, i, j, g_rnd_st_x1, g_rnd_st_y1, g_rnd_sizex, g_rnd_sizey);
						g_rend_room3(g_map, i, j, g_rnd_st_x2, g_rnd_st_y2, g_rnd_sizex, g_rnd_sizey);
						g_rend_room4(g_map, i, j, m_x, m_y, g_rnd2_x, g_rnd2_y);
						g_rend_spawn(g_map, i, j);
						g_chest(g_map, i, j);
					}
					if(i == 1 && j == 1) {
						g_map[i][j] = 'x';
					}
					if(i == m_x - 2 && j == m_y - 2) {
						g_map[i][j] = 'o';
					}
                }
        }
        refresh();
}

void g_rend_room1(char **g_map, int i, int j, int g_rnd1) {
		if ((i == 0 && j <= g_rnd1) || (j == 0 && i < g_rnd1)
            || (i == g_rnd1 && j <= g_rnd1) || (j == g_rnd1 && i < g_rnd1 - 1)) {
            g_map[i][j] = '#';
        }
		if ((i > 0 && i < g_rnd1) && (j > 0 && j < g_rnd1)) {
			g_map[i][j] = '.';
        }
}

void g_rend_room2 (char **g_map, int i, int j, int g_rnd_st_x1, int g_rnd_st_y1, int g_rnd_sizex, int g_rnd_sizey) {
	if(( ((i >= g_rnd_st_x1 && i <= g_rnd_st_x1 + g_rnd_sizex ) && (j == g_rnd_st_y1
        || j == g_rnd_st_y1 + g_rnd_sizey))
        || ((i == g_rnd_st_x1 || i == g_rnd_st_x1 + g_rnd_sizex)
        && (j >= g_rnd_st_y1  && j < g_rnd_st_y1 + g_rnd_sizey)))) {
                g_map[i][j] = '#';
                g_map[g_rnd_st_x1 + g_rnd_sizex][g_rnd_st_y1 + 2] = ' ';
        }
		if((i >= g_rnd_st_x1 + 1 && i<= g_rnd_st_x1 + g_rnd_sizex - 1) 
			&& (j >= g_rnd_st_y1 + 1 && j < g_rnd_st_y1 + g_rnd_sizey - 1) ) {
			g_map[i][j] = '.';
		}
}

void g_rend_room3 (char **g_map, int i, int j, int g_rnd_st_x2, int g_rnd_st_y2, int g_rnd_sizex, int g_rnd_sizey) {
	if((((i >= g_rnd_st_x2 && i <= g_rnd_st_x2 + g_rnd_sizex) && (j == g_rnd_st_y2
		|| j == g_rnd_st_y2 + g_rnd_sizey))
		|| ((i == g_rnd_st_x2 || i == g_rnd_st_x2 + g_rnd_sizex)
		&& (j >= g_rnd_st_y2 && j < g_rnd_st_y2 + g_rnd_sizey)))) {
		g_map[i][j] = '#';
		g_map[g_rnd_st_x2][g_rnd_st_y2 + 2] = ' ';
	}
	if ((i >= g_rnd_st_x2 + 1 && i <= g_rnd_st_x2 + g_rnd_sizex - 1) 
		&&(j >= g_rnd_st_y2 + 1 && j < g_rnd_st_y2 + g_rnd_sizey - 1)) {
		g_map[i][j] = '.';
	}
}

void g_rend_room4(char **g_map, int i, int j, int m_x, int m_y, int g_rnd2_x, int g_rnd2_y) {
	if((i >= m_x - g_rnd2_x && j == m_y - g_rnd2_y) || (i == m_x - g_rnd2_x && j >= m_y - g_rnd2_y)) {
		g_map[i][j] = '#';
		g_map[m_x - g_rnd2_x + 2][m_y - g_rnd2_y] = ' ';
	}
	if ((i >= m_x - g_rnd2_x + 1 && i < m_x - 1) && (j >= m_y - g_rnd2_y + 1 && i < m_y - 1)) {
		g_map[i][j] = ':';
	}
}

void g_rend_spawn(char **g_map, int i, int j) {
	int g_rnd_spawn = 0;
		if(g_map[i][j] == ' ') {
			g_rnd_spawn = 1 + rand() % 200;
			if(g_rnd_spawn <= 2) {
				g_map[i][j] = 'e';
			}
		}
		if(g_map[i][j] == '.') {
			g_rnd_spawn = rand() % 100;
			if(g_rnd_spawn <= 2) {
				g_map[i][j] = 'e';
				}
			}
}
void g_chest(char **g_map, int i, int j) {

int g_rnd = 0;
	if(g_map[i][j] == '.') {
		g_rnd = rand() % 300;
        if(g_rnd <= 1) {
            g_map[i][j] = 'w';
        }
    }	
}

