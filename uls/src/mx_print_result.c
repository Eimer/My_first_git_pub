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

void mx_print_result(char **arr, int flags, char *check_a, char **argv) {
    char **new_arr;
    int count = 0;
    int numb = 0;

    if (flags == 0 || flags == 1)
    if ((arr != NULL && mx_strcmp(argv[1], check_a) != 0)
        || (argv[2] != NULL && mx_strcmp(argv[1], ".") != 0)) {
        mx_printstr(check_a);
        mx_printstr(":\n");
    }
    if (flags == 0) { // flag -a 
        mx_output_with_atr(arr);
        return;
    }
    if (flags == 1) { // flag -A
        for (count = 0; arr[count] != NULL; count++)
            if (arr[count][0] != '.')
                numb++;
        new_arr = (char **)malloc(sizeof(char *) * numb + 1);
        new_arr[numb] = NULL;
        for (count = 0, numb = 0; arr[count] != NULL; count++)
            if (arr[count][0] != '.')
                new_arr[numb++] = mx_strdup(arr[count]);
        // if (new_arr[0] != NULL)
        //     mx_output_with_atr(new_arr);
        // mx_del_strarr(&new_arr);
    }
    if (flags == 2) {
        if (mx_searchstr(check_a, "/.") != 1) {
            if ((arr != NULL && mx_strcmp(argv[1], check_a) != 0)
            || (argv[2] != NULL && mx_strcmp(argv[1], ".") != 0)) {
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
            // if (new_arr[0] != NULL)
            //     mx_output_with_atr(new_arr);
            // mx_del_strarr(&new_arr);
        }
    }
        if (new_arr != NULL) {
            if (new_arr[0] != NULL)
                mx_output_with_atr(new_arr);
            mx_del_strarr(&new_arr);
        }
}
