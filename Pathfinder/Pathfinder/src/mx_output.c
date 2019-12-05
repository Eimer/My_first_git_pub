#include "../inc/pathfinder.h"

void mx_output(t_island **islands, int i, int j) {
    char *str = "Path: ";
    char *arrow = " -> ";
    str = mx_strjoin(str, islands[i]->name);
    str = mx_strjoin(str, arrow);
    str = mx_strjoin(str, islands[j]->name);
    str = mx_strjoin(str, "\n");
    mx_printstr(str);
}
