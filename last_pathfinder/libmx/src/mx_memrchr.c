#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const char *res = s;
    if(!res || c == 0 || n <= 0) {
        return NULL;
    }
    for (size_t i = n; i > 0; i--) {
        if(res[i] == c) {
            return (char *)&res[i];
        }
    }
    return NULL;
}
