#include "../inc/pathfinder.h"

static int count(char *str) {
    int count = 0;
    int len = 0;
    while(str[count]) {
        if(str[count] == '\n') {
            len++;
        }
        count++;
    }
    return len - 1;
}

int **mx_fill_matrix(char *first_line, char *str) {
    int len = count(str);
    int **matrix = mx_matrix(first_line);
    int res_len = mx_atoi(first_line);
    char **from = mx_arr_from(str);
    char **to = mx_arr_to(str);
    int *distance = mx_arr_dist(str);;
    t_island **islands = mx_islands_arr(str);
    for (int i = 0; i < res_len; i++) {
        for (int j = 0; j < res_len; j++) {
            matrix[i][j] = 900000000;
        }
    }
    for (int i = 0; i < res_len; i++){
        for (int j = 0; j < res_len; j++){
            for (int q = 0; q < len; q++){
                if((mx_strcmp(islands[i]->name, from[q]) == 0) && (mx_strcmp(islands[j]->name, to[q]) == 0)) {
                    matrix[i][j] = distance[q];
                    matrix[j][i] = distance[q];
                }
            }
        }
    }
    return matrix;
}
