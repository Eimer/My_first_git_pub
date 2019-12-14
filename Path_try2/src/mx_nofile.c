#include "../inc/pathfinder.h"

void mx_nofile(char *str) {
    char *no_file = NULL;
    char *res_nofile = NULL;
    char first_half[] = "error: file ";
    char secont_half[] = " does not exist\n";
    no_file = mx_strjoin(first_half, str);
    res_nofile = mx_strjoin(no_file, secont_half);
    mx_printerr(res_nofile);
    free(no_file);
    free(res_nofile);
}
