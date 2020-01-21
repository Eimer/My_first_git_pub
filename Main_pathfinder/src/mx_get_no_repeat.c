#include "../inc/pathfinder.h"

static int get_count_islands(char **splited_islands) {
    int count = 0;

    while (splited_islands[count]) {
        count++;
    }
    return count;
}

static char **get_islands(char *argv[]) {
    char *str_from_file = mx_file_to_str(argv[1]);
    char **splited_islands = NULL;
    int count = 0;

    while (str_from_file[count] != '\n') {
        str_from_file[count] = '-';
        count++;
    }
    str_from_file[count] = '-';
    count = 0;
    for (int i = 0; i < mx_strlen(str_from_file); i++)
        if (str_from_file[i] == '\n')
            str_from_file[i] = '-';
    splited_islands = mx_strsplit(str_from_file, '-');
    while (splited_islands[count]) {
        for (int i = 0; i < mx_strlen(splited_islands[count]); i++)
            if (splited_islands[count][i] == ',')
                splited_islands[count][i] = '\0';
        count++;
    }
    free(str_from_file);
    return splited_islands;
}

static char **no_repeat(char *argv[]) {
    char **splited_islands = get_islands(argv);
    int count = get_count_islands(splited_islands);

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (i != j)
                if (mx_strcmp(splited_islands[i], splited_islands[j]) == 0 
                    && mx_strlen(splited_islands[i]) == mx_strlen(splited_islands[j])) {
                    for (int q = 0; q < mx_strlen(splited_islands[j]); q++)
                        splited_islands[j][q] = '0';
            }
        }
    }
    return splited_islands;
}

char **mx_get_no_repeat(char *argv[]) {
    char **splited_islands = no_repeat(argv);
    char **splited_no_repeat = NULL;
    int count = 0;
    int count_no_repeat = 0;

    while (splited_islands[count]) {
        if (mx_strcmp(splited_islands[count], "0") != 0)
            count_no_repeat++;
        count++;
    }
    splited_no_repeat = (char **)malloc(sizeof(char *) * (count_no_repeat + 1));
    count_no_repeat = 0;
    for (int i = 0; i < count; i++) {
        if (mx_strcmp(splited_islands[i], "0") != 0) {
            splited_no_repeat[count_no_repeat] = mx_strnew(mx_strlen(splited_islands[i]));
            splited_no_repeat[count_no_repeat] = mx_strcpy(splited_no_repeat[count_no_repeat], splited_islands[i]);
            count_no_repeat++;
        }
        free(splited_islands[i]);
    }
    free(splited_islands);
    splited_no_repeat[count_no_repeat] = NULL;
    return splited_no_repeat;
}
