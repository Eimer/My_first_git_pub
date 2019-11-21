#include "../inc/pathfinder.h"

t_island *mx_islands_arr(char *str) {
    int count = mx_count_islands(str);
    
    t_island **islands_arr = (t_island **)malloc(sizeof(t_island*) * count + 1);
    for (int i = 0; i < count; i++) {
        islands_arr[i] = (t_island *)malloc(sizeof(t_island));
    }
    islands_arr[count] = NULL;
    for (int i = 0; i < count; i++) {
        free(islands_arr[i]);
    }
    free(islands_arr);
    system("leaks -q a.out");
    
    return NULL;
}
