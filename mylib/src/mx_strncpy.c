#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;
    while(dst[i] && src[i] && i < len) {
        dst[i] = src[i];
        i++;
    }
    while (dst[i]) {
        dst[i] = '\0';
        i++;
    }
    
    return dst;
}
