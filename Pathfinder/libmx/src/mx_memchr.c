#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const char *res = s;
    if(!res || !c) {
        return NULL;
    }
    for (size_t i = 0; i < n; i++) {
        if(res[i] == c) {
            return (char *)&res[i];
        }
    }
    return NULL;
}
