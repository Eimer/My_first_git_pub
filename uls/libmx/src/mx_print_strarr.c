#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    int a = 0;

    while (arr[a]) {
        a++;
    }
    for (int i = 0; i < a; i++) {
        mx_printstr(arr[i]);
        if (i < a - 1) {
            mx_printstr(delim);
        }
    }
    mx_printchar('\n');
}
