#include "../inc/header.h"

void g_game_over(int score) {

	noecho();
	int x = 1;

	printw("Your managed to get through %d caves alive!\n", score);
	printw("Press <SPACE> if you want to restart or <q> to quit.");
	refresh();
	while(true) {
		x = getch();
		if(x == 32) {
            score = 0;
			break;
		}
		else if (x == 113) {
			endwin();
			exit(0);
		}
		else {
			continue;
		}
	}
}

