#include "../inc/pathfinder.h"
static char **eque(char** res) {
    int count = 0;
    int len = 0;
    while(res[count]) {
        len = mx_strlen(res[count]);
        for(int i = len -1; i >= 0; i--) {
            if(res[count][i] == '+') {
                res[count][i] = '=';
                break;
            }
        }
        count++;
    }
    return res;
}

char **mx_count_dist(char **path_no_repeat, char *first_line, char *str) {
    int len = mx_atoi(first_line);
    int **dist = mx_fill_matrix(first_line, str);
    int count = 0;
    char **buff = NULL;
    int count_buff = 0;
    int main_count = 0;
    char *main_str = "ABCDE\n";
    char **res = NULL;
    t_island **islands = mx_islands_arr(str);
    if (path_no_repeat)
    {
    while (path_no_repeat[count]){
        for(int i = 0; i < mx_strlen(path_no_repeat[count]); i++) {
            if(path_no_repeat[count][i] == '-' || path_no_repeat[count][i] == '>') {
                path_no_repeat[count][i] = ' ';
            }
        }
        path_no_repeat[count] = mx_strjoin("ABC ", path_no_repeat[count]);
        count++;
    }
    count = 0;
    while (path_no_repeat[count]){
        buff = mx_strsplit(path_no_repeat[count], ' ');
        count_buff = 0;
        main_count = 0;
        while(buff[count_buff + 1]) {
            for(int i = 0; i < len; i++) {
                for(int j = 0; j < len; j++) {
                    if(mx_strcmp(buff[count_buff], islands[i]->name) == 0 && mx_strcmp(buff[count_buff + 1], islands[j]->name) == 0) {
                        main_str = mx_strjoin(main_str, mx_itoa(dist[i][j]));
                        main_str = mx_strjoin(main_str, " + ");
                        main_count += dist[i][j];
                    }
                }
                
            }
            count_buff++;
        }
        main_str = mx_strjoin(main_str, mx_itoa(main_count));
        main_str = mx_strjoin(main_str, "\n");
        count++;
    }
    res = mx_strsplit(main_str, '\n');
    res = eque(res);
    }
    return res;
}
