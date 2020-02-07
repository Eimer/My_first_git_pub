#include "../inc/uls.h"

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
    return NULL;
}

int mx_check_denied(char *arr_dirs_u, t_add_in_func *audit) {
    DIR *dir;
    errno = 0;

    dir = opendir(arr_dirs_u);
    if (dir) {
        closedir(dir);
        return 0;
    }
    if (audit->flags[1] == 0 && audit->flags[2] == 0 && mx_searchstr(arr_dirs_u, "/.") != 1)
    if (errno != 0) {
        if (audit->check == 1)
            mx_printstr("\n");
        mx_printstr(arr_dirs_u);
        mx_printstr(":\n");
        mx_printerr("uls: ");
        mx_printerr(memrchr(arr_dirs_u, '/', mx_strlen(arr_dirs_u)));
        mx_printerr(": ");
        mx_printerr(strerror(errno));
        mx_printerr("\n");
        return 1;
    }
    return 1;
}
