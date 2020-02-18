#include "../inc/uls.h"

char **mx_sort(char **overall_arr, t_add_in_func *audit) {
    int count = 0;
    char *buff = NULL;
    int j = 0;

    while (overall_arr[count])
        count++;
    j = count - 1;
    if (audit->flags[10] == 1)
        return overall_arr;
    mx_bubble_sort(overall_arr, count);
    if (audit->flags[8] == 1 || audit->flags[7] == 1)
        mx_quick(overall_arr, count, audit);
    if (audit->flags[6] == 1) {
        for (int i = 0; i < count / 2; i++, j--) {
                buff = overall_arr[j];
                overall_arr[j] = overall_arr[i];
                overall_arr[i] = buff;
        }
    }
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
