#include "../inc/uls.h"

char **mx_sort(char **overall_arr, t_add_in_func *audit) {
    int count = 0;
    char *buff = NULL;

    while (overall_arr[count])
        count++;
    if (audit->flags[6] == 1) {
        for (int i = count; i > -1; i--)
            for (int j = count - 1; j > 0; j--)
                if (mx_strcmp(overall_arr[j], overall_arr[i]) > 0) {
                    buff = overall_arr[j];
                    overall_arr[j] = overall_arr[i];
                    overall_arr[i] = buff;
                }
    }
    else
        mx_bubble_sort(overall_arr, count);
    return overall_arr;
}

char **mx_sort_overallarr(char **overall_arr) {
    int count = 0;
    char *buff = NULL;

    while (overall_arr[count])
        count++;
    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - 1 - i; j++)
            if (mx_strcmp(overall_arr[j], overall_arr[j + 1]) > 0) {
                buff = overall_arr[j];
                overall_arr[j] = overall_arr[j + 1];
                overall_arr[j + 1] = buff;
            }
    return overall_arr;
}
