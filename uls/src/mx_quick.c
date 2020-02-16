#include "../inc/uls.h"

static int mx_test(char *argv, t_add_in_func *audit) {
    struct stat buf;

    lstat(argv, &buf);
    if (audit->flags[7] == 1)
        return buf.st_atimespec.tv_nsec;
    else
        return buf.st_mtimespec.tv_nsec;
}

void mx_quick(char **overall_arr, int count, t_add_in_func *audit) {
    char *buff = NULL;

    for (int i = 0; i < count - 1; i++)
        for (int j = 0; j < count - 1 - i; j++) {
            if (mx_test(overall_arr[i], audit) > mx_test(overall_arr[j],
                audit)) {
                buff = overall_arr[j];
                overall_arr[j] = overall_arr[j + 1];
                overall_arr[j + 1] = buff;
            }
        }
}
