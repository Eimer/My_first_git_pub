#include "../inc/pathfinder.h"

int **mx_matrix(char *first_line) {
    int res_len = mx_atoi(first_line);
    int **res = NULL;
    
    res = (int **)malloc(sizeof(int *) * res_len);
    for (int i = 0; i < res_len; i++){
        res[i] = (int*)malloc(res_len * sizeof(int));
    }
    return res;
}
