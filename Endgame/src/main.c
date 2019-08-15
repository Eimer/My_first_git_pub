#include "../inc/header.h"

int main() {
	initscr();
	g_test();
	curs_set(0);
	srand(time(NULL));
	//static int x = 35;
	//static int y = 120;
	static int m_x = 30;
	static int m_y = 60;
	int g_hero_hp = 15;
	bool f = true;
	char **g_map = (char **)malloc(m_x * sizeof(char *));
	for(int i = 0; i < m_x; i++) {
		g_map[i] = (char *)malloc(m_y * sizeof(char));
	}
	g_startscreen();
	char username[100];
	g_second_screen(username, m_x, m_y);
	mx_third_screen(username);
	int score = 0;
	while(f) {
	g_rendmap(g_map, m_x, m_y);
	g_print_map(g_map, m_x, m_y);
	g_move_hero(g_map, m_x, m_y, g_hero_hp);
	score++;
	g_level_success(score);
	endwin();
	continue;
	}
	return 0;
}

