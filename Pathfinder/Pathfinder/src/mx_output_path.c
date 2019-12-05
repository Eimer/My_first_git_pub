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

static char **reverse_path(char *str) {
    char **res = NULL;
    char *kostyl = "kostyl_123\n";
    char *buff = mx_strjoin(kostyl, str); 
    res = mx_strsplit(buff, '\n');
    return res;
} 

static char *correct_path(char **reverse_path) {
    char *res = NULL;
    int count = 0;
    char **buff = NULL;
    char *kostyl = "123 ";
    int buff_count = 0;
    while(reverse_path[count]) {
        reverse_path[count] = mx_strjoin(kostyl, reverse_path[count]);
        buff = mx_strsplit(reverse_path[count], ' ');
        buff_count = 0;
        while (buff[buff_count])
            buff_count++;
        for (int i = buff_count - 1; i >= 0; i--) {
            res = mx_strjoin(res, buff[i]);
            if(i != 0)
                res = mx_strjoin(res, " -> ");
        }
        res = mx_strjoin(res, "\n");
        count++;
    }
    return res;
}

void mx_output_path(char *str, char *first_line) {
    int len = count(str);
    int count = mx_atoi(first_line);   
    int **path = mx_path(str, first_line);
    int **dist = mx_path_dist(str, first_line);
    char **from = mx_arr_from(str);
    char **to = mx_arr_to(str);
    int x = 0;
    int y = 0;
    t_island **islands = mx_islands_arr(str);
    for (int i = 0; i < count; i++){
        printf("%s ", islands[i]->name);
    }
     printf("%c", '\n');
    for (int i = 0; i < count; i++){
        printf("%s ", islands[i]->name);
        for (int j = 0; j < count; j++) {
            printf("%d ", dist[i][j]);
        }
        printf("%c", '\n');
        
    }
    char *test_str = NULL;
     printf("%s", "\n");
     for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++){
                    if(path[i][j] != 0) {
                        x = i;
                        y = j;
                        mx_print_delim();
                        mx_output(islands, i, j);
                        mx_printstr("Route: ");
                        mx_printstr(islands[i]->name);
                        test_str = mx_strjoin(test_str, islands[j]->name);
                        //mx_printstr(mx_itoa(dist[i][j]));
                        mx_printstr(" <- ");
                        test_str = mx_strjoin(test_str, " ");
                        while(path[x][y] != 0) {
                            y = path[x][y];
                            mx_printstr(islands[y]->name);
                            test_str = mx_strjoin(test_str, islands[y]->name);
                            //mx_printstr(mx_itoa(dist[x][y]));
                            mx_printstr(" <- ");
                            test_str = mx_strjoin(test_str, " ");
                            
                        }
                        mx_printstr(islands[j]->name);
                        test_str = mx_strjoin(test_str, islands[i]->name);
                        mx_printstr("\nDistance: ");
                        mx_printstr("\n");
                        test_str = mx_strjoin(test_str, "\n");
                        mx_print_delim();
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
        
        char **ttt = reverse_path(test_str);
        int co = 0;
        while(ttt[co]) {
            printf("%s\n", ttt[co]);
            co++;
        }
        printf("%s", "\n");
        char *rev_path = correct_path(ttt);
        printf("%s", rev_path);
        printf("%s" , "\n\n");
        //printf("%s\n\n", test_str);
}
