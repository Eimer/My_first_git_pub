#include "../inc/uls.h"

char **mx_arr_dirs(int argc, char const *argv[]) {
    char **arr_dirs = NULL;
    int count_dirs = 0;
    
    for (int i = 1; i < argc; i++) {
        if (mx_dirorfile(argv[i]) == 0) {
            count_dirs++;
        }
    }
    if (count_dirs != 0) {
        arr_dirs = (char **)malloc(sizeof(char *) * (count_dirs + 1));
        arr_dirs[count_dirs] = NULL;
        count_dirs = 0;
        for (int i = 1; i < argc; i++) {
            if (mx_dirorfile(argv[i]) == 0) {
                arr_dirs[count_dirs] = mx_strnew(mx_strlen(argv[i]));
                mx_strcpy(arr_dirs[count_dirs], argv[i]);
                count_dirs++;
            }
        }
    }
    return arr_dirs;
}
