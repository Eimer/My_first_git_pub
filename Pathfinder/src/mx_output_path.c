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
    //int **dist = mx_path_dist(str, first_line);
    char **from = mx_arr_from(str);
    char **to = mx_arr_to(str);
    int x = 0;
    int y = 0;
    t_island **islands = mx_islands_arr(str);

    printf("%s", "  ");

    for (int i = 0; i < count; i++){
        printf("%s ", islands[i]->name);
    }
     printf("%c", '\n');
    for (int i = 0; i < count; i++){
        printf("%s ", islands[i]->name);
        for (int j = 0; j < count; j++) {
            printf("%d ", path[i][j]);
        }
        printf("%c", '\n');
        
    }
     printf("%s", "\n");
     for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++){
                    if(path[i][j] != 0) {
                        x = i;
                        y = j;
                        //mx_print_delim();
                        mx_output(islands, i, j);
                        printf("%s ", islands[j]->name);
                        printf("%s ", "<-");
                        while(path[x][y] != 0) {
                            y = path[x][y];
                            printf("%s ", islands[y]->name);
                            printf("%s ", "<-");
                        }
                        printf("%s ", islands[i]->name);
                        //mx_print_delim();
                    }
                    else {
                        for (int q = 0; q < len; q++){
                        if((mx_strcmp(islands[i]->name, from[q]) == 0) && (mx_strcmp(islands[j]->name, to[q]) == 0)) {
                            //mx_print_delim();
                            mx_output(islands, i ,j);
                            printf("%s ", islands[j]->name);
                            printf("%s ", "<-");
                            printf("%s ", islands[i]->name);
                            //mx_print_delim();
                        }
                        }
                    }
            }
                
        }
}
