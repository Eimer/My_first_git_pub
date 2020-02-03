#include "../inc/uls.h"

int mx_searchstr(const char *haystack, const char *needle) {
    int i = 0;
    int try = 0;
    int strlen = mx_strlen(needle);

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

static void mx_print_n(char **arr) {
    for (int u = 0; arr[u] != NULL; u++) {
        mx_printstr(arr[u]);
        mx_printstr("\n");
    }
}

void mx_print_result(char **arr, t_add_in_func *audit, char *check_a) {
    char **new_arr;
    int count = 0;
    int numb = 0;

    if (audit->flags[2] == 1 || audit->flags[1] == 1)
    if (arr[0] != NULL && audit->flags[0] == 1) {
        mx_printstr(check_a);
        mx_printstr(":\n");
    }
    if (audit->flags[1] == 1) { // flag -a 
        mx_output_with_atr(arr);
        return;
    }
    if (audit->flags[2] == 1) { // flag -A
        for (count = 0; arr[count] != NULL; count++)
            if (arr[count][0] != '.')
                numb++;
        new_arr = (char **)malloc(sizeof(char *) * numb + 1);
        new_arr[numb] = NULL;
        for (count = 0, numb = 0; arr[count] != NULL; count++)
            if (arr[count][0] != '.')
                new_arr[numb++] = mx_strdup(arr[count]);
    }
    if (audit->flags[1] == 0 && audit->flags[2] == 0) {
        if (mx_searchstr(check_a, "/.") != 1) {
            if (arr != NULL && audit->flags[0] == 1) {
                mx_printstr(check_a);
                mx_printstr(":\n");
            }
            for (count = 0; arr[count] != NULL; count++)
                if (arr[count][0] != '.')
                    numb++;
            new_arr = (char **)malloc(sizeof(char *) * numb + 1);
            new_arr[numb] = NULL;
            for (count = 0, numb = 0; arr[count] != NULL; count++)
                if (arr[count][0] != '.')
                    new_arr[numb++] = mx_strdup(arr[count]);
        }
    }
        if (new_arr != NULL) {
            if (new_arr[0] != NULL)
                mx_output_with_atr(new_arr);
            mx_del_strarr(&new_arr);
        }
        if (audit->flags[5] == 1)
            mx_print_n(arr);
        audit->flags[0] = 1;
}
