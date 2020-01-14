#include "../inc/pathfinder.h"

char **mx_arr_dist(char *str_from_file) {
    char *buff_str = mx_strnew(mx_strlen(str_from_file));
    int count = 0;
    char **arr_dist = NULL;
    buff_str = mx_strcpy(buff_str, str_from_file);
    while (buff_str[count]) {
        if (buff_str[count] == ',') {
            while (buff_str[count] != '\n') {
                count++;
            }
        }
        buff_str[count] = ',';
        count++;
    }
    arr_dist = mx_strsplit(buff_str, ',');
    free(buff_str);
    return arr_dist;
}
