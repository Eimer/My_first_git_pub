#include "../inc/libmx.h"

int mx_get_char_index(const char *str, char c) {
    int i = 0;
    while(str[i]) {
        i++;
    }
    if(!i) {
        return -2;
    }
    i = 0;
    while (str[i]) {
        if(str[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}
