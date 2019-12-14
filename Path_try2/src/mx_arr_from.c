#include "../inc/pathfinder.h"

char **mx_arr_from(char *str) {
    char **from= NULL;
    int count = 0;
    int count_symb = 0;
    from = mx_strsplit(str, '\n');
    while (from[count]) {
        count_symb = mx_strlen(from[count]);
        while(count_symb != 0) {
            if (from[count][count_symb] == '-'){
                from[count][count_symb] = '\0';
                break;
            }
            from[count][count_symb] = '\0';
            count_symb--;
        }
        count++;
    }
    return from;
}
