#include "../inc/uls.h"

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

void mx_print_n(char **arr, int *flags) {
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
