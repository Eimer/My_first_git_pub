#include "../inc/pathfinder.h"

static char *no_firt_line(char *str_from_file) {
    int count = 0;

    while (str_from_file[count] != '\n') {
        str_from_file[count] = '\n';
    }
    return str_from_file;
}

char **mx_arr_from(char *str_from_file) {
    char **from= NULL;
    int count = 0;
    int count_symb = 0;

    str_from_file = no_firt_line(str_from_file);
    from = mx_strsplit(str_from_file, '\n');
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
