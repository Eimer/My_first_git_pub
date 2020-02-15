#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *strnew = mx_strdup(s1);
    char *copy = mx_strnew(n + 1);

    for (unsigned long i = 0; i < n; i++) {
        copy[i] = s1[i];
    }
    free(strnew);
    return copy;
}
