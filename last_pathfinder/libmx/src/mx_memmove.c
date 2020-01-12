#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *res = dst;
    const char *buff = src;
    char *test = mx_strnew(len);

    for (size_t i = 0; i < len; i++) {
        test[i] = buff[i];
    }
    for (size_t i = 0; i < len; i++) {
        res[i] = test[i];
    }
    
    return dst;
}
