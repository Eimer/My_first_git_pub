#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    for (int i = 0; i < mx_strlen(haystack); i++) {
        for (int j = 0; j < mx_strlen(needle); j++) {
            if(mx_strcmp(&haystack[i], &needle[j]) != 0) {
                break;
            }
            else {
                return (char *)&haystack[i];
            }
        }
    }
    return NULL;
}
