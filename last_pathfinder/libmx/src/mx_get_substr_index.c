#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if(!str || !sub) {
        return -2;
    }
   for (int i = 0; i < mx_strlen(str); i++) {
        for (int j = 0; j < mx_strlen(sub); j++) {
            if(mx_strcmp(&str[i], &sub[j]) != 0) {
                break;
            }
            else {
                return i;
            }
        }
    }
    return -1;
}
