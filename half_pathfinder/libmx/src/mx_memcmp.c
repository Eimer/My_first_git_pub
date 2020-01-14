#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const char *str1 = s1;
    const char *str2 = s2;
    int i = 0;
    if(!s1 || !s2 || n == 0) {
        return 0;
    }
    while ((str1[i] && str2[i]) && i < (int)n) {
        if(str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return 0;
}
