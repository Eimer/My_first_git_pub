#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *str1 = (char*) s1;
    char *str2 = (char*) s2;
    int diff = 0;
    size_t i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i] && i < n)
        i++;
    if (str1[i] != str2[i])
        return diff = str1[i] - str2[i];
    else
        return 0;
}
