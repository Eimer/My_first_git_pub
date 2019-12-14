#include "../inc/pathfinder.h"

char *mx_fill_first_line(char *first_line, char *str_from_file) {
    int count = 0;
    int len = 0;
    char *tmp = mx_strnew(mx_strlen(str_from_file));
    first_line = mx_strcpy(tmp, str_from_file);
    len  = mx_strlen(first_line);
    while (first_line[count] != '\n') {
        count++;
    }
    for (int i = count; i < len; i++) {
        first_line[i] = '\0';
    }
    return first_line;
}
