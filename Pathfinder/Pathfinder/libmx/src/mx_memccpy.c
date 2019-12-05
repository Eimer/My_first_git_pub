#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *res = dst;
    const char *buff = src;
    if(!dst || !src) {
        return NULL;
    }
    for (size_t i = 0; i < n; i++) {
        res[i] = buff[i];
        if(res[i] == c) {
            return &(res[i + 1]);
        }
    }
    return NULL;
}
