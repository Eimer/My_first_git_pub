
#include "../inc/uls.h"

static void mx_print_n(char **arr, int *flags) {
    int u = 0;

    for (u = 0; arr[u] != NULL && (flags[1] == 1 || flags[9] == 1); u++) {
        mx_printstr(arr[u]);
        mx_printstr("\n");
    }
    for (u = 0; arr[u] != NULL && flags[2] == 1; u++) {
        if (mx_strcmp(arr[u], ".") != 0 && mx_strcmp(arr[u], "..") != 0) {
            mx_printstr(arr[u]);
            mx_printstr("\n");
        }
    }
        for (u = 0; arr[u] != NULL && flags[1] != 1 && flags[2] != 1; u++) {
            if (arr[u][0] != '.') {
                mx_printstr(arr[u]);
                mx_printstr("\n");
            }
    }
}

static void print_check_a(char **arr, t_add_in_func *audit, char *check_a) {
    if (arr != NULL && audit->flags[0] == 1 && check_a != NULL) {
        if (audit->check == 1)
            mx_printchar(10);
        mx_printstr(check_a);
        mx_printstr(":\n");
    }
    mx_sort(arr, audit);
    audit->check = 1;
    audit->flags[0] = 1;
}

static char **return_a_A(char **arr, t_add_in_func *audit) {
    char **new_arr = NULL;
    int count = 0;
    int numb = 0;

    if (audit->flags[2] == 1 && audit->flags[9] == 0) { // flag -A
        for (count = 0; arr[count] != NULL; count++)
            if (mx_strcmp(arr[count], ".") != 0
                && mx_strcmp(arr[count], "..") != 0)
                numb++;
        new_arr = (char **)malloc(sizeof(char *) * numb + 1);
        new_arr[numb] = NULL;
        for (count = 0, numb = 0; arr[count] != NULL; count++)
            if (mx_strcmp(arr[count], ".") != 0
                && mx_strcmp(arr[count], "..") != 0)
                new_arr[numb++] = mx_strdup(arr[count]);
        mx_sort(new_arr, audit);
    }
    return new_arr;
}

static char **return_without_flags(char **arr, char *check_a) {
    char **new_arr = NULL;
    int count = 0;
    int numb = 0;

    if (mx_searchstr(check_a, "/.") != 1) {
        for (count = 0; arr[count] != NULL; count++)
            if (arr[count][0] != '.')
                numb++;
        new_arr = (char **)malloc(sizeof(char *) * numb + 1);
        for (int u = 0; u < numb; u++)
            new_arr[u] = NULL;
        new_arr[numb] = NULL;
        for (count = 0, numb = 0; arr[count] != NULL; count++)
            if (arr[count][0] != '.')
                new_arr[numb++] = mx_strdup(arr[count]);
    }
    return new_arr;
}

void mx_print_result(char **arr, t_add_in_func *audit, char *check_a) {
    char **new_arr = return_a_A(arr, audit);

    if (mx_searchstr(check_a, "/.") == 1 && audit->flags[1] == 0
        && audit->flags[2] == 0)
        return;
    print_check_a(arr, audit, check_a);
    if (audit->flags[4] == 1) {
        if (check_a != NULL)
            mx_output_l(check_a);
        return;
    }
    if (audit->flags[1] == 1 || audit->flags[9] == 1) { // flag -a
        mx_sort(arr, audit);
        (audit->flags[5] == 0 && isatty(1) == 1) ?
            mx_output_with_atr(arr) : mx_print_n(arr, audit->flags);
        return;
    }
    if (audit->flags[1] == 0 && audit->flags[2] == 0)
        new_arr = return_without_flags(arr, check_a);
    if (new_arr != NULL && (audit->flags[5] == 1 || isatty(1) == 0)) {
        mx_print_n(new_arr, audit->flags);
        mx_del_strarr(&new_arr);
    }
    if (new_arr != NULL && audit->flags[5] == 0) {
        if (new_arr[0] != NULL && isatty(1) == 1)
            mx_output_with_atr(new_arr);
        mx_del_strarr(&new_arr);
    }
    audit->flags[0] = 1;
    audit->check = 1;
}
