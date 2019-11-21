#include "../inc/pathfinder.h"

bool mx_is_number(char *str) {
    int i = 0;
    int j = 0;
    int x = 0;
    while(str[i]) {
        if(str[i] == ',') {
            j = i + 1;
            while(str[j] !='\0') {
                if(str[j] > 57) {
                    return false;
                }
                j++;
            }
        }
        i++;
    }
    x = 0;
    return true;
}
