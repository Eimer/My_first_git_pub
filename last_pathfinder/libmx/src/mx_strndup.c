#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *res = NULL;
    if((int)n >= mx_strlen(s1)) {
        res = mx_strnew(mx_strlen(s1));
        res = mx_strcpy(res, s1);
    }
    else {
        res = (char *)malloc(n + 1);
        for (int i = 0; i < (int)n; i++) {
            res[i] = s1[i];
        }
        res[n] = '\0';
    }
    return res;
}
