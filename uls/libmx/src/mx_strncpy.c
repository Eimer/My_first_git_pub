#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i;

    for (i = 0; i < mx_strlen(src); i++) {
        if (i == len) {
            break;
        }
        dst[i] = src[i];
    }
    return dst;
}
