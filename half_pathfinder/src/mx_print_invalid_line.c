#include "../inc/pathfinder.h"

void mx_print_invalid_line(char *argv[], char *str) {
    int line_i = mx_invalid_line(argv);
    char *line_ch = NULL;
    char *line = NULL;
    char first_half[]= "error: line ";
    char *second_half = " is not valid\n";

    line_ch = mx_itoa(line_i);
    line = mx_strjoin(first_half, line_ch);
    line = mx_strjoin(line, second_half);
    mx_printerr(line);
    free(line);
    free(line_ch);
    str = NULL;
}
