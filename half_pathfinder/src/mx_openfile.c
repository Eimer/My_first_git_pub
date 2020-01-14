#include "../inc/pathfinder.h"

void mx_openfile(char **argc) {
    int openf = 0;

    openf = open(argc[1], O_RDONLY);
    if(openf <= 0) {
        mx_nofile(argc[1]);
        close(openf);
        exit(0);
    }
}
