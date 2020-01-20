#include "../inc/pathfinder.h"

char **mx_arr_to(char *str_from_file) {
    char **to = NULL;
    char *buff = mx_strnew(mx_strlen(str_from_file));
    int count_symb = 0;

    buff = mx_strcpy(buff, str_from_file);
    while(buff[count_symb] != '\0') {
        if(buff[count_symb] == '-') {
            while (buff[count_symb] != '\0') {
                if (buff[count_symb] == ',') {
                    buff[count_symb] = '-';
                    break;
                }
                count_symb++;
            }
        }
        buff[count_symb] = '-';
        count_symb++;
    }
    to = mx_strsplit(buff, '-');
    free(buff);
    return to;
}
