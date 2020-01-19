#include "../inc/libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    if(!str || !sub) { 
        return -1;
    }
    for (int i = 0; i < mx_strlen(str); i++) {
        for (int j = 0; j < mx_strlen(sub); j++) {
            if(mx_strcmp(&str[i], &sub[j]) != 0) {
                break;
            }
            else {
                count++;
            }
        }
    }
    if(count == 0) {
        return -1;
    }
    return count;
}
