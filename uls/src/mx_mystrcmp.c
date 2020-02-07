#include "../inc/uls.h"

int mx_mystrcmp(const char *s1, const char *s2) {

    for (int i = 0; i < mx_strlen(s1); i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
    }
    return 0;
}
