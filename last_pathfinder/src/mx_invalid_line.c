#include "../inc/pathfinder.h"

static int without_empty(char *str_from_file) {
    char **splited_str = mx_strsplit(str_from_file, '\n');
    int count = 1;
    int free_count = 0;

    while (splited_str[count]) {
        if (mx_count_words(splited_str[count], '-') != 2 || mx_count_words(splited_str[count], ',') != 2) {
            while (splited_str[free_count]) {
                free(splited_str[free_count]);
                free_count++;
            }
            free(splited_str);
            return count + 1;
        }
        count++;
    }
    while (splited_str[free_count]) {
                free(splited_str[free_count]);
                free_count++;
            }
            free(splited_str);
    return 0;
}

static int with_empty(char *str_from_file) {
    int line = 0;
    
    for (int i = 0; i < mx_strlen(str_from_file) - 1; i++) {
        if (str_from_file[i] == '\n' && str_from_file[i + 1] != '\n')
            line++;
        if (str_from_file[i] == '\n' && str_from_file[i + 1] == '\n')
            return line + 2;
        if (str_from_file[i] == '-' && str_from_file[i + 1] == '-')
            return line + 2;
        if (str_from_file[i] == ',' && str_from_file[i + 1] == ',')
            return line + 2;
    }
    return 0;
}

static int val_dist(char *str_from_file) {
    int count = 0;
    int line = 0;

    for (int i = 0; i < mx_strlen(str_from_file); i++) {
        if (str_from_file[i] == ',') {
            line++;
            count = i + 1;
            while (str_from_file[count] != '\n') {
                if (str_from_file[count] < 48 || str_from_file[count] > 58) {
                return line + 1;
            }
                count++;
            }
        }
    }
    return 0;
}

static int min_line(int error_no_empty, int empty, int er_dist) {
    if(error_no_empty != 0 || empty != 0 || er_dist != 0) {
        if (empty == 0 && er_dist == 0)
            return error_no_empty;
        if (error_no_empty == 0 && er_dist == 0)
            return empty;
        if (error_no_empty == 0 && empty == 0)
            return er_dist;
        if (error_no_empty == 0)
            return mx_get_min(empty, er_dist);
        if (empty == 0)
            return mx_get_min(error_no_empty, er_dist);
        if (er_dist == 0)
            return mx_get_min(error_no_empty, empty);
        if (error_no_empty == empty && error_no_empty == er_dist)
            return error_no_empty;
    }
    if (error_no_empty != 0 && empty != 0 && er_dist != 0) {
        if (mx_get_min(error_no_empty, empty) < mx_get_min(er_dist, empty))
            return mx_get_min(error_no_empty, empty);
        else
            return mx_get_min(er_dist, empty);
    }
    return 0;
}

int mx_invalid_line(char *argv[]) {
    char *str_from_file = mx_file_to_str(argv[1]);
    int error_no_empty = without_empty(str_from_file);
    int empty = with_empty(str_from_file);
    int er_dist = val_dist(str_from_file);

    free(str_from_file);
    return min_line(error_no_empty, empty, er_dist);
}
