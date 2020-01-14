#include "../inc/pathfinder.h"


static int count_len(t_arrays *main_arrays) {
    int len = 0;

    while (main_arrays->no_repeat[len]) {
        len++;
    }
    return len;
}

t_arrays *mx_path_dist(t_arrays *main_arrays) {
    int len = count_len(main_arrays);
    
    for (int k = 0; k < len; k++) {
        for (int j = 0; j < len; j++){
            for (int i = 0; i < len; i++) {
                if(i != j)
                    if (main_arrays->shortest_path[i][j] >= main_arrays->shortest_path[i][k] + main_arrays->shortest_path[k][j])
                        main_arrays->shortest_path[i][j] = main_arrays->shortest_path[i][k] + main_arrays->shortest_path[k][j];
                }
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i < j) {
                mx_output(main_arrays, i, j);
            }
        }
    }
    
    return main_arrays;
}
