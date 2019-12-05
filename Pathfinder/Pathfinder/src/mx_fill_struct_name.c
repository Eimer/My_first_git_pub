#include "../inc/pathfinder.h"

t_island **mx_struct_name(char **splited_islands, t_island **islands_arr) {
    int count_island_arr = 0;
    int count_splited_islands = 0;
    while(splited_islands[count_splited_islands]){
        if((mx_strcmp(splited_islands[count_splited_islands], "0"))!= 0) {
            islands_arr[count_island_arr]->name = mx_strnew(mx_strlen(splited_islands[count_splited_islands]));
            islands_arr[count_island_arr]->name = mx_strcpy(islands_arr[count_island_arr]->name, splited_islands[count_splited_islands]);
            count_island_arr++;
            
        }
        count_splited_islands++;
    }
    return islands_arr;

}
