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
int mx_searchstr(const char *haystack, const char *needle) {
    int i = 0;
    int try = 0;
    int strlen = mx_strlen(needle);

    if (needle == NULL || haystack == NULL)
        return 0;
    while (haystack[i]) {
        try = i;
        for (int j = 0; haystack[i] == needle[j] && needle[j] != '\0'; j++) {
            if (j == strlen - 1)
                return 1;
            if (needle[j + 1] != haystack[i + 1]) {
                i = try;
                break;
            }
            i++;
        }
        i++;
    }
    return 0;
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
    mx_printerr(strerror(errno));
    if (audit->flags[1] == 1 || (mx_searchstr(arr_dirs_u, "/.") != 1))
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
