#include "../inc/pathfinder.h"

t_island **mx_islands_arr(char *str) {
    int count = mx_count_islands(str);
    char **splited_islands = mx_memory_for_islands(str);
    char **buff = NULL;
    t_island **islands_arr = (t_island **)malloc(sizeof(t_island*) * count + 1);
    for (int i = 0; i < count; i++) {
        islands_arr[i] = (t_island *)malloc(sizeof(t_island));
    }
    islands_arr[count] = NULL;
    buff = mx_memory_for_each_island(str, splited_islands);
    splited_islands = mx_filling_islands(splited_islands, buff);
    splited_islands = mx_filling_no_repeat(splited_islands);
    islands_arr = mx_struct_name(splited_islands, islands_arr);
    islands_arr = mx_struct_distance(islands_arr);
    return islands_arr;
}
