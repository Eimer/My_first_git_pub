#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2){
    int a = 0;
    int i;

    for (i = mx_strlen(s1); i < (mx_strlen(s2) + mx_strlen(s1)); i++) {
        s1[i] = s2[a];
        a++;
    }
    s1[a + i] = '\0';
    return s1;
}
