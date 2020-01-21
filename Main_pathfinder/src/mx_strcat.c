#include "../inc/pathfinder.h"

void mx_my_strcat(char *restrict s1, const char *restrict s2) {
    int i = 0;
    int j = 0;

    while(s2[j] != '\0') {
        s1[i] = s2[j];
        i++;
        j++;
    }
}
