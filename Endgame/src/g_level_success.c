#include "../inc/header.h"

void g_level_success(int score) {
	noecho();
	int x = 1;
	printw("Hoorray! %d caves behind - you're coming closer to the surface!\n", score);
	printw("Press <SPACE> to continue or <q> to quit.\n");
	refresh();
	while(true) {
		x = getch();
		if(x == 32) {
			break;
		}
		else if (x == 113) {
			clear();
			g_game_over(score);
			break;
		}
		else {
			continue;
		}
	}
//	printw("%d", getch);
//	usleep(10000);
	clear();
}

