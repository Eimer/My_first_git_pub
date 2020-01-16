#include "../inc/pathfinder.h"

bool mx_isdigit(char *str) {
    int len = mx_strlen(str);

    for (int i = 0; i < len; i++) {
        if(str[i] < 48 || str[i] > 57) {
            return false;
        }
    }
    return true;
}
