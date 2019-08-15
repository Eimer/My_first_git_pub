#include "../inc/header.h"

void mx_third_screen(char *username) {

start_color();
init_pair(1, COLOR_CYAN, COLOR_BLACK);
char buff;
int fd;
int d;
int x = 1;
attron(COLOR_PAIR(1));
char k[] = "Hello ";
    printw("%s", k);
    usleep(50); 
if (mx_strlen(username) == 0) {
	username = "Stranger";
}
	printw("%s", username);
	attroff(COLOR_PAIR(1));
	fd = (open("story.txt", O_RDONLY)); 
	d = read(fd, &buff, 1);
	while(d > 0) {
		usleep(30000);
		attron(COLOR_PAIR(1));
        printw("%c", buff);
        d = read(fd, &buff, 1);
		attroff(COLOR_PAIR(1));
		refresh();
	}
while(x) {
    x = getch();
        if(x == 32) {
                break;
        }
}
refresh();
close(fd);
clear();
}

