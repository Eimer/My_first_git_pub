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
                if (mx_strcmp(splited_islands[i], splited_islands[j]) == 0) {
                    for (int q = 0; q < mx_strlen(splited_islands[j]); q++)
                        splited_islands[j][q] = '0';
            }
        }
    }
    return splited_islands;
}

static bool compare_amount(char **splited_islands, char *str_from_file, char *to_str_count) {
    int count = 0;
    char *first_line = NULL;
    int count_no_repeat = 0;

    while (str_from_file[count] != '\n')
        count++;
    first_line = mx_strnew(count + 1);
    for (int i = 0; i < count; i++)
        first_line[i] = str_from_file[i];
    count = 0;
    while(splited_islands[count]) {
        if(splited_islands[count][0] != '0')
            count_no_repeat++;
        free(splited_islands[count]);
        count++;
    }
    to_str_count = mx_itoa(count_no_repeat);
    if (mx_strcmp(first_line, to_str_count) != 0)
        return false;
    free(first_line);
    return true;
}

bool mx_islands_no_repeat (char *argv[]) {
    char **splited_islands = no_repeat(argv);
    char *str_from_file = mx_file_to_str(argv[1]);
    char *to_str_count = NULL;
    bool res;

    res = compare_amount(splited_islands, str_from_file, to_str_count);
    free(splited_islands);
    free(str_from_file);
    free(to_str_count);
    return res;
}
