#include "../inc/uls.h"

char **mx_arr_files(int argc, char **argv) {
    char **arr_files = NULL;
    int count_files = 0;

    for (int i = 1; i < argc; i++)
        if (mx_dirorfile(argv[i]) == 1)
            count_files++;
    if (count_files != 0) {
        arr_files = (char **)malloc(sizeof(char *) * (count_files + 1));
        arr_files[count_files] = NULL;
        count_files = 0;
        for (int i = 1; i < argc; i++)
            if (mx_dirorfile(argv[i]) == 1) {
                arr_files[count_files] = mx_strnew(mx_strlen(argv[i]));
                mx_strcpy(arr_files[count_files], argv[i]);
                count_files++;
            }
    }
    return arr_files;
}
