#include "libmx.h" 

char *mx_strdup(const char *str) {
    char *dst = mx_strnew(mx_strlen(str));

    mx_strcpy(dst, str);
    return dst;
}

