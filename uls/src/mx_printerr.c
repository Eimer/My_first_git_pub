#include "../inc/uls.h"

void mx_printerr(const char *s) {
    int k = mx_strlen(s);

    write(2, s, k);
}

void mx_printcharerr(char s) {

    write(2, &s, 1);
}

