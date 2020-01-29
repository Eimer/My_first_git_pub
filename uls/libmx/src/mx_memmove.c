#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *s2 = (char *) dst;
    char *s3 = (char *) src;
    size_t j = 0;
    char *s1 = mx_strdup(s3);

    for (j = 0; j < len; j++)
        s2[j] = s1[j];
    free(s1);
    return dst;
}
