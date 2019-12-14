#include "../inc/pathfinder.h"

int **mx_path_dist(char *str, char *first_line) {
    int **matrix_path = mx_matrix(first_line);
    int len = mx_atoi(first_line);
    int **floyd = mx_fill_matrix(first_line, str);
    for (int i = 0; i < mx_atoi(first_line); i++) {
        for (int j = 0; j < mx_atoi(first_line); j++) {
            matrix_path[i][j] = 0;
        }
    }
    for (int k = 0; k < len; k++) {
        for (int j = 0; j < len; j++){
            for (int i = 0; i < len; i++) {
                if(i != j) {
                    if (floyd[i][j] >= floyd[i][k] + floyd[k][j] && floyd[i][j] != 0
                        && floyd[i][k]!= 0 && floyd[k][j] != 0 ){
                        floyd[i][j] = floyd[i][k] + floyd[k][j];
                        matrix_path[i][j] = k;
                    }
                }
            }
        }
    }
    return floyd;
}
