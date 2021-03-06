#include "../inc/pathfinder.h"

void mx_print_invalid_line(char *str) {
    int line_i = mx_invalid_line(str);
    char *line_ch = NULL;
    char *line = NULL;
    char first_half[]= "error: line ";
    char *second_half = " isn't valid";
    line_ch = mx_itoa(line_i);
    line = mx_strjoin(first_half, line_ch);
    line = mx_strjoin(line, second_half);
    mx_printerr(line);
    free(line);
    free(line_ch);
}
