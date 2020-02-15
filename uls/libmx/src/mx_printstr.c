#include "libmx.h"

void mx_printstr(const char *s) {
    int f = mx_strlen(s);
    if (f == 0)
        write(1, "(null)", 6);
    write(1, s, f);
}
