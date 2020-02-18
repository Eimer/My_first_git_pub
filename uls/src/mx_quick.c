#include "../inc/uls.h"

static int mx_test(char *argv, t_add_in_func *audit) {
    struct stat buf;
    char *new_str = mx_strjoin(audit->check_a, "/");
    char *new = mx_strjoin(new_str, argv);
    stat(new, &buf);

    free(new_str);
    free(new);
    if (audit->flags[7] == 1)
        return buf.st_size;
    if (audit->flags[8] == 1)
        return buf.st_mtimespec.tv_sec;
    return buf.st_size;
}

void mx_quick(char **overall_arr, int count, t_add_in_func *audit) {
    char *buff = NULL;

    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++) {
            if (mx_test(overall_arr[i], audit) < mx_test(overall_arr[j],
                audit)) {
                    buff = overall_arr[j];
                    overall_arr[j] = overall_arr[i];
                    overall_arr[i] = buff;
            }
            if (mx_test(overall_arr[i], audit) == mx_test(overall_arr[j],
                audit) && mx_strcmp(overall_arr[j], overall_arr[i]) < 0) {
                    buff = overall_arr[j];
                    overall_arr[j] = overall_arr[i];
                    overall_arr[i] = buff;
                }
        }
}
