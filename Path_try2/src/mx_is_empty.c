#include "../inc/pathfinder.h"

void mx_is_empty(char *str) {
    char *is_empty = NULL;
    char *res_is_empty = NULL;
    char first_half[] = "error: file ";
    char secont_half[] = " is empty\n";
    is_empty = mx_strjoin(first_half, str);
    res_is_empty = mx_strjoin(is_empty, secont_half);
    mx_printerr(res_is_empty);
    free(is_empty);
    free(res_is_empty);
}
