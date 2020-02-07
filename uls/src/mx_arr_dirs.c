#include "../inc/uls.h"

char **mx_arr_dirs(int argc, char **argv) {
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
    else if (argc == 1) {
        arr_dirs = (char **)malloc(sizeof(char *) * 2);
        arr_dirs[0] = mx_strdup(".");
        arr_dirs[1] = NULL;
    }
    return arr_dirs;
}

char **mx_arr_dirs_1(int argc, char **argv, t_add_in_func *audit) {
    char **arr_dirs = NULL;
    int count_dirs = 0;
    struct stat buf;

    for (int i = 1; i < argc; i++) {
        lstat(argv[i], &buf);
        if (mx_dirorfile(argv[i]) == 0 && !(S_ISLNK(buf.st_mode)))
            count_dirs++;
    }
    if (count_dirs != 0) {
        arr_dirs = (char **)malloc(sizeof(char *) * (count_dirs + 1));
        arr_dirs[count_dirs] = NULL;
        count_dirs = 0;
        for (int i = 1; i < argc; i++) {
            lstat(argv[i], &buf);
            if (mx_dirorfile(argv[i]) == 0 && !(S_ISLNK(buf.st_mode))) {
                arr_dirs[count_dirs] = mx_strnew(mx_strlen(argv[i]));
                mx_strcpy(arr_dirs[count_dirs], argv[i]);
                count_dirs++;
            }
        }
    }
    else if (audit->check_n == 0) {
        arr_dirs = (char **)malloc(sizeof(char *) * 2);
        arr_dirs[1] = NULL;
        arr_dirs[0] = mx_strdup(".");
    }
    return arr_dirs;
}

char **mx_arr_dirs_2(int argc, char **argv) {
    char **arr_dirs = NULL;
    int count_dirs = 0;
    struct stat buf;

    for (int i = 0; i < argc; i++) {
        lstat(argv[i], &buf);
        if (mx_dirorfile(argv[i]) == 0  && !(S_ISLNK(buf.st_mode))
            && (mx_searchstr(argv[i], "./") || argv[i][0] != '.'))
            count_dirs++;
    }
    if (count_dirs != 0) {
        arr_dirs = (char **)malloc(sizeof(char *) * (count_dirs + 1));
        arr_dirs[count_dirs] = NULL;
        count_dirs = 0;
        for (int i = 0; i < argc; i++) {
            lstat(argv[i], &buf);
            if (mx_dirorfile(argv[i]) == 0  && !(S_ISLNK(buf.st_mode))
                && (mx_searchstr(argv[i], "./") 
                    || argv[i][0] != '.'))
                arr_dirs[count_dirs++] = mx_strdup(argv[i]);
        }
    }
    return arr_dirs;
}
