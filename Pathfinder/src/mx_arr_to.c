#include "../inc/pathfinder.h"

char **mx_arr_to(char *str) {
    char **to = NULL;
    char *buff = mx_strnew(mx_strlen(str));
    buff = mx_strcpy(buff, str);
    int count_symb = 0;
    char *kostyl = "mhfgkjh";

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
    buff = mx_strjoin(kostyl, buff);
    to = mx_strsplit(buff, '-');
    return to;
}
