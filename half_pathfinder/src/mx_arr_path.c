#include "../inc/pathfinder.h"

static int count_all(char *str_from_file) {
    int count = 0;
    int len = 0;

    while(str_from_file[count]) {
        if(str_from_file[count] == '\n') {
            len++;
        }
        count++;
    }
    return len - 2;
}

static int count_dist(char **isl_no_repeat) {
    int count = 0;

    while (isl_no_repeat[count]) {
        count++;
    }
    return count;
}

static int **fill_arr_path(int **arr_path, char *str_from_file, int count, char **isl_no_repeat) {
    char **arr_dist = mx_arr_dist(str_from_file);
    char **arr_from = mx_arr_from(str_from_file);
    char **arr_to = mx_arr_to(str_from_file);
    int all_len = count_all(str_from_file);

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            for (int q = 0; q < all_len; q++) {
                if((mx_strcmp(isl_no_repeat[i], arr_from[q]) == 0) 
                    && (mx_strcmp(isl_no_repeat[j], arr_to[q]) == 0)) {
                    arr_path[i][j] = mx_atoi(arr_dist[q]);
                    arr_path[j][i] = mx_atoi(arr_dist[q]);
                }
            }
        }
    }
    return arr_path;
}

int **mx_arr_path(char *argv[]) {
    char *str_from_file = mx_file_to_str(argv[1]);
    char **isl_no_repeat = mx_get_no_repeat(argv);
    int **arr_path = NULL;
    int count = count_dist(isl_no_repeat);

    arr_path = (int **)malloc(sizeof(int*) * count);
    for (int i = 0; i < count; i++) {
        arr_path[i] = (int *)malloc(sizeof(int) * count);
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (i != j) {
                 arr_path[i][j] = 90;
            }
            else {
                arr_path[i][j] = 0;
            }
            
           
        }
    }
    arr_path = fill_arr_path(arr_path, str_from_file, count, isl_no_repeat);
    free(str_from_file);
    return arr_path;
}
