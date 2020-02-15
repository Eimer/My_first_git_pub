#include "../inc/uls.h"

void mx_d_flag(char **arr_files, char **arr_dirs, t_add_in_func *audit) {
    int count_f = 0;
    int count_d = 0;
    char **all;

    for (count_f = 0; arr_files != NULL && arr_files[count_f] != NULL;
            count_f++);
    for (count_d = 0; arr_dirs != NULL && arr_dirs[count_d] != NULL;
            count_d++);
    all = (char **)malloc(sizeof(char *) * (count_f + count_d + 1));
    for (int count = 0; count < count_f + count_d + 1; count++)
        all[count] = NULL;
    for (count_f = 0; arr_files != NULL
            && arr_files[count_f] != NULL; count_f++)
        all[count_f] = mx_strdup(arr_files[count_f]);
    for (count_d = 0; arr_dirs != NULL && arr_dirs[count_d] != NULL; count_d++)
        all[count_f++] = mx_strdup(arr_dirs[count_d]);
    mx_print_result(all, audit, NULL);
    mx_del_strarr(&all);
}

static void *memrchr(const void *s, int c, size_t n) {
    char new;
    char *str = NULL;

    if (c > 0 && c < 10)
        new = c + 48;
    else
        new = c;
    str = (char *) s;
    for (size_t i = n; i > 0; i--) {
        if (str[i] == new)
            return &str[i + 1];
    }
    return str;
}

static void error(char *arr_dirs_u, t_add_in_func *audit) {
    DIR *dir;

    errno = 0;
    dir = opendir(arr_dirs_u);
    mx_printerr("uls: ");
    mx_printerr(memrchr(arr_dirs_u, '/', mx_strlen(arr_dirs_u)));
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
    audit->main_return = 1;
}

static void ifelse(char *arr_dirs_u) {
    if (arr_dirs_u[0] == '/' && arr_dirs_u[1] == '/' && arr_dirs_u[2] != '/')
        mx_printstr(mx_chr(arr_dirs_u, '/', mx_strlen(arr_dirs_u)));
    else 
        mx_printstr(arr_dirs_u);
}

int mx_check_denied(char *arr_dirs_u, t_add_in_func *audit) {
    DIR *dir;
    errno = 0;

    dir = opendir(arr_dirs_u);
    if (dir) {
        closedir(dir);
        return 0;
    }
    if (audit->flags[1] == 1 || (mx_searchstr(arr_dirs_u, "/.") != 1))
    if (errno != 0) {
        if (audit->check_n == 1)
            mx_printstr("\n");
        ifelse(arr_dirs_u);
        mx_printstr(":\n");
        error(arr_dirs_u, audit);
    }
    return 1;
}
