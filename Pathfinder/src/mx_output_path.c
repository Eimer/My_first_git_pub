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

void mx_output_path(char *str, char *first_line) {
    int len = count(str);
    int count = mx_atoi(first_line);   
    //int **path = mx_path(str, first_line);
    int **dist = mx_path_dist(str, first_line);
    char **from = mx_arr_from(str);
    char **to = mx_arr_to(str);
    t_island **islands = mx_islands_arr(str);

    for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++) {
             for (int q = 0; q < len; q++){
                if((mx_strcmp(islands[i]->name, from[q]) == 0) && (mx_strcmp(islands[j]->name, to[q]) == 0)) {
                    printf("%s ", islands[i]->name);
                }
            }           
        }
    }
    printf("%s", "\n");
    printf("%s", "\n");
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("%s", "\n");
    }
}
