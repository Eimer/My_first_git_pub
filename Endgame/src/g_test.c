#include "../inc/header.h"
#include <curses.h>
void g_test() {
#define MYLINE (int) ((LINES-22)/2)
#define MYCOL ((COLS-70)/2)
#define MYLINES 22
#define MYCOLS 70

WINDOW *win;

if(!(initscr())){
   fprintf(stderr, "type: iniscr() failed\n\n");
   exit(1);
}
if ((LINES<40)||(COLS<130)){
   fprintf(stderr, "screen is too small\n\n");
   endwin(); exit (1);
}
win=newwin(MYLINES,MYCOLS,MYLINE,MYCOL);
}

