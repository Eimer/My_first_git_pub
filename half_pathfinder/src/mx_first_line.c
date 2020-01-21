#include "../inc/pathfinder.h"

static int len_first_line(char *str_from_file) {
    int len = 0;
    
    while (str_from_file[len] != '\0') {
        if (str_from_file[len] == '\n') {
            return len;
        }
        len++;
    }
    return len;
}

static char *copy_first_line(int len, char *str_from_file) {
    char *only_first_line = NULL;
    int count = 0;

    only_first_line = mx_strnew(len);
    for (count = 0; count < len; count++) {
        only_first_line[count] = str_from_file[count];
    }
    only_first_line[count] = '\0';
    return only_first_line;
}

static void no_first_line(int len) {
    if (len == 0) {
        mx_print_first_line();
        exit(0);
    }
}

static void valid_first_line(char *only_first_line, char *str_from_file) {
    if (!mx_isdigit(only_first_line)) {
        free(str_from_file);
        free(only_first_line);
        mx_print_first_line();
        exit(0);
    }
}

void mx_first_line(char *argv[]) {
    char *str_from_file = NULL;
    int len = 0;
    char *only_firts_line = NULL;
    
    str_from_file = mx_file_to_str(argv[1]);
    if(str_from_file[0] > 47 && str_from_file[0] < 58 
        && mx_strlen(str_from_file) == 1) {
        mx_print_first_line();
        exit(0);
    }
    len = len_first_line(str_from_file);
    no_first_line(len);
    only_firts_line = copy_first_line(len, str_from_file);
    if (!mx_isdigit(only_firts_line)) {
        free(str_from_file);
        free(only_firts_line);
        mx_print_first_line();
        exit(0);
    }
    valid_first_line(only_firts_line, str_from_file);
    free(str_from_file);
    free(only_firts_line);
}
