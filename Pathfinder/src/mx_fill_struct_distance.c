#include "../inc/pathfinder.h"

t_island **mx_struct_distance(t_island **islands_arr) {
int count_island_arr = 0;
    while (islands_arr[count_island_arr]){
        islands_arr[count_island_arr]->distalnce = 2147483647;
        islands_arr[count_island_arr]->visited = false;
        count_island_arr++;
    }
    return islands_arr;
}
