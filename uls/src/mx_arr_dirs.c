#include "../inc/uls.h"

char **mx_arr_dirs(int argc, char **argv) {
    char **arr_dirs = NULL;
    int count_dirs = 0;

    for (int i = 1; i < argc; i++)
        if (mx_dirorfile(argv[i]) == 0)
            count_dirs++;
    if (count_dirs != 0) {
        arr_dirs = (char **)malloc(sizeof(char *) * (count_dirs + 1));
        arr_dirs[count_dirs] = NULL;
        count_dirs = 0;
        for (int i = 1; i < argc; i++)
            if (mx_dirorfile(argv[i]) == 0)
                arr_dirs[count_dirs++] = mx_strdup(argv[i]);
    }
    else if (argc == 1) {
        arr_dirs = (char **)malloc(sizeof(char *) * 2);
        arr_dirs[0] = mx_strdup(".");
        arr_dirs[1] = NULL;
    }
    return arr_dirs;
}

char **mx_arr_dirs_1(int argc, char **argv, t_add_in_func *audit,
                        char **arr_files) {
    char **arr_dirs = NULL;
    int count_dirs = 0;

    for (int i = 1; i < argc; i++)
        if (mx_dirorfile(argv[i]) == 0)
            count_dirs++;
    if (count_dirs != 0) {
        arr_dirs = (char **)malloc(sizeof(char *) * (count_dirs + 1));
        arr_dirs[count_dirs] = NULL;
        count_dirs = 0;
        for (int i = 1; i < argc; i++)
            if (mx_dirorfile(argv[i]) == 0)
                arr_dirs[count_dirs++] = mx_strdup(argv[i]);
    }
    else if (audit->check_n == 0 && arr_files == NULL) {
        arr_dirs = (char **)malloc(sizeof(char *) * 2);
        arr_dirs[1] = NULL;
        arr_dirs[0] = mx_strdup(".");
    }
    return arr_dirs;
}

static bool check(char * argv) {
    struct stat buf;

    lstat(argv, &buf);
    if (S_ISDIR(buf.st_mode) && mx_strcmp(argv, "/dev/fd") != 0
        && (mx_searchstr(argv, "./") || argv[0] != '.'))
            return 1;
    return 0;
}

char **mx_arr_dirs_2(int argc, char **argv) {
    char **arr_dirs = NULL;
    int count_dirs = 0;

    for (int i = 0; i < argc; i++) {
        if (check(argv[i]) == 1)
            count_dirs++;
    }
    if (count_dirs != 0) {
        arr_dirs = (char **)malloc(sizeof(char *) * (count_dirs + 1));
        arr_dirs[count_dirs] = NULL;
        count_dirs = 0;
        for (int i = 0; i < argc; i++) {
            if (check(argv[i]) == 1)
                arr_dirs[count_dirs++] = mx_strdup(argv[i]);
        }
    }
    return arr_dirs;
}

char *mx_chr(char *s, char c, int n) {
    for (int i = 0; i < n; i++) {
        if (s[i] == c)
            return &s[i + 1];
    }
    return NULL;
}
