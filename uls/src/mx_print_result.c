#include "../inc/uls.h"

static void print_check_a(char **arr, t_add_in_func *audit, char *check_a) {
    if (arr != NULL && check_a != NULL) {
        if (audit->check_n > 1) {
            if (audit->check == 1)
                mx_printchar(10);
            if (check_a[0] == '/' && check_a[1] == '/' && check_a[2] != '/')
                mx_printstr(mx_chr(check_a, '/', mx_strlen(check_a)));
            else
                mx_printstr(check_a);
            mx_printstr(":\n");
        }
    }
    audit->check = 1;
    audit->check_n = 2;
}

// flag -A
static char **return_a_A(char **arr, t_add_in_func *audit, char *check_a) {
    char **new_arr = NULL;
    int count = 0;
    int numb = 0;

    if (audit->flags[2] == 1 && audit->flags[9] == 0 && audit->flags[1] == 0) {
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
    print_check_a(arr, audit, check_a);
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

static void printit(char **new_arr, t_add_in_func *audit, char *check_a,
                    char **arr) {
    if (audit->flags[1] == 0 && audit->flags[2] == 0)
        new_arr = return_without_flags(arr, check_a);
    if (new_arr != NULL && (audit->flags[5] == 1 || isatty(1) == 0)) {
        mx_sort(new_arr, audit);
        mx_print_n(new_arr, audit->flags);
        mx_del_strarr(&new_arr);
    }
    if (new_arr != NULL && audit->flags[5] == 0) {
        mx_sort(new_arr, audit);
        if (new_arr[0] != NULL && isatty(1) == 1)
            mx_output_with_atr(new_arr);
        mx_del_strarr(&new_arr);
    }
    audit->check = 1;
}

void mx_print_result(char **arr, t_add_in_func *audit, char *check_a) {
    if (mx_searchstr(check_a, "/.") == 1 && audit->flags[1] == 0
        && audit->flags[2] == 0)
            return;
    char **new_arr = return_a_A(arr, audit, check_a);

    if (audit->flags[4] == 1) {
        if (check_a != NULL)
            mx_output_l(check_a, audit);
        else
            for (int u = 0; arr[u] != NULL; u++)
                mx_output_l(arr[u], audit);
        return;
    }
    if (audit->flags[1] == 1 || audit->flags[9] == 1) {// flag -a
        mx_sort(arr, audit);
        (audit->flags[5] == 0 && isatty(1) == 1) ?
            mx_output_with_atr(arr) : mx_print_n(arr, audit->flags);
        return;
    }
    printit(new_arr, audit, check_a, arr);
}
