#include "../inc/uls.h"

void mx_printerr(const char *s) {
    int k = mx_strlen(s);

    write(2, s, k);
}
