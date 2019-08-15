#include "../inc/header.h"

void g_print_stats() {
	for(int i = 0; i <= 15; i++) {
        for(int j = 65; j <= 90; j++){
            if(i == 0 || j == 65 || i == 15 || j == 90){
                mvprintw(i, j, "#");
            }
            else {
				mvprintw(i , j, " ");
            }
		}
	}
	refresh();
}
