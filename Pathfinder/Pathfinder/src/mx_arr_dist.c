#include "../inc/pathfinder.h"

int *mx_arr_dist(char *str) {
    int len = 0;
    int count = 0;
    int *res = NULL;
    char **numbers = NULL;
    char *kostyl = "-ajkagdvf ";
    char *buff = mx_strnew(mx_strlen(str));
    int count_symb = 0;
    while(str[len]) {
        if(str[len] == '\n') {
            count++;
        }
        len++;
    }
    count--;
    buff = mx_strcpy(buff, str);
    while(buff[count_symb] != '\0') {
        if(buff[count_symb] == ',') {
            buff[count_symb] = ' ';
            while (buff[count_symb] != '\0') {
                if (buff[count_symb] == '\n') {
                    buff[count_symb] = ' ';
                    break;
                }
                count_symb++;
            }
        }
        buff[count_symb] = ' ';
        count_symb++;
    }
    char *test = mx_del_extra_spaces(buff);
    test = mx_strjoin(kostyl, test);
    numbers = mx_strsplit(test, ' ');
    res = (int *)malloc(sizeof(int) * count);
    for(int i = 0; i < count; i++) {
        res[i] = mx_atoi(numbers[i]);
    }
    return res;
}
