#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **s = *arr;

    for (int i = 0; s[i]; i++)
        mx_strdel(&s[i]);
    free(*arr);
    *arr = NULL;
}
