#include "../inc/pathfinder.h"

int mx_count_islands(char *str) {
    int res = 0;
    char **splited_islands = NULL;
    char **buff = NULL;
    splited_islands = mx_memory_for_islands(str);
    buff = mx_memory_for_each_island(str, splited_islands);
    splited_islands = mx_filling_islands(splited_islands, buff);
    res = mx_no_repeat(splited_islands);
    free(splited_islands);
    return res;
}
