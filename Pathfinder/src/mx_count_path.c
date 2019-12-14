#include "../inc/pathfinder.h"

static char **reverse_path(char *str) {
    
    char **res = NULL;
    char *kostyl = "kostyl_123\n";
    char *buff = mx_strjoin(kostyl, str); 
    if(str) {
        res = mx_strsplit(buff, '\n');
    }
    return res;
} 

static char *correct_path(char **reverse_path) {
    char *res = NULL;
    int count = 0;
    char **buff = NULL;
    char *kostyl = "123 ";
    int buff_count = 0;
    if(reverse_path) {
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
    }
    return res;
}

char *mx_count_path(char *str, char *first_line) {
    int count = mx_atoi(first_line);   
    int **path = mx_path(str, first_line);
    int x = 0;
    int y = 0;
    t_island **islands = mx_islands_arr(str);
    char *test_str = NULL;
    char **ttt = NULL;
    char *rev_path = NULL;
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++){
            if(path[i][j] != 0) {
                x = i;
                y = j;
                test_str = mx_strjoin(test_str, islands[j]->name);
                test_str = mx_strjoin(test_str, " ");
                while(path[x][y] != 0) {
                    y = path[x][y];
                        test_str = mx_strjoin(test_str, islands[y]->name);
                        test_str = mx_strjoin(test_str, " ");            
                    }
                test_str = mx_strjoin(test_str, islands[i]->name);
                test_str = mx_strjoin(test_str, "\n");
            }
        }
    }

        ttt = reverse_path(test_str);
        rev_path = correct_path(ttt);
        return rev_path;
}
