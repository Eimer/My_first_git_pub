#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *res = dst;
    const char *buff = src;
    for (size_t i = 0; i < n; i++) {
        res[i] = buff[i];
    }
    return res;
}
