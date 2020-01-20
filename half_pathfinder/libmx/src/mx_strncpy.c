#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;
    while(i != mx_strlen(src)){
        if(i == len) {
            break;
        }
        dst[i] = src[i];
        i++;
    }
    return dst;
}
