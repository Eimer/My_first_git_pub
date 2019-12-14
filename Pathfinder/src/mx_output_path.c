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
    int **path = mx_path(str, first_line);
    int **dist = mx_path_dist(str, first_line);
    char **from = mx_arr_from(str);
    char **to = mx_arr_to(str);    
    t_island **islands = mx_islands_arr(str);
    char *path_no_repeat_str = mx_count_path(str, first_line);
    char **path_no_repeat = NULL;
    char **path_no_repeat2 = NULL;
    char **dist_no_repeat = NULL;
    int count_no_repeat = 0;
    if(path_no_repeat_str) {
        path_no_repeat_str = mx_strjoin("ABC\n" , path_no_repeat_str);
        path_no_repeat = mx_strsplit(path_no_repeat_str, '\n');
        path_no_repeat2 = mx_strsplit(path_no_repeat_str, '\n');
        dist_no_repeat = mx_count_dist(path_no_repeat, first_line, str);
    }
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++){
                    if(path[i][j] != 0  && dist_no_repeat) {
                        mx_print_delim();
                        mx_output(islands, i, j);
                        mx_printstr("Route: ");
                        mx_printstr(path_no_repeat2[count_no_repeat]);
                        mx_printstr("\nDistance: ");
                        mx_printstr(dist_no_repeat[count_no_repeat]);
                        mx_printstr("\n");
                        mx_print_delim();
                        count_no_repeat++;
                    }
                    else {
                        for (int q = 0; q < len; q++){
                        if((mx_strcmp(islands[i]->name, from[q]) == 0) && (mx_strcmp(islands[j]->name, to[q]) == 0)) {
                            mx_print_delim();
                            mx_output(islands, i ,j);
                            mx_printstr("Route: ");
                            mx_printstr(islands[i]->name);
                            mx_printstr(" -> ");
                            mx_printstr(islands[j]->name);
                            mx_printstr("\nDistance: ");
                            mx_printstr(mx_itoa(dist[i][j]));
                            mx_printstr("\n");
                            mx_print_delim();
                        }
                        }
                    }
            }
                
        }
}
