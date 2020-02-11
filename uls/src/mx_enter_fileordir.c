#include "../inc/uls.h"

int mx_count_obj_d(const char *str) {
    int res = 0;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(str);

    while ((entry = readdir(dir)) != NULL)
        res++;
    closedir(dir);
    return res;
}

static void namecpy(char **overall_arr, int count_el, char *arr_dirs, t_add_in_func *audit) {
    int u = 0;
    char *new1;
    char *new2;
    char **arr_dirs_new;

    for (u = 0; overall_arr[u] != NULL; u++)
        if (mx_strcmp(overall_arr[u], ".") != 0
            && mx_strcmp(overall_arr[u], "..") != 0) {
                new1 = mx_strjoin(arr_dirs, "/");
                new2 = mx_strjoin(new1, overall_arr[u]);
                free(overall_arr[u]);
                overall_arr[u] = new2;
            free(new1);
        }
    arr_dirs_new = mx_arr_dirs_2(count_el, overall_arr);
    if (arr_dirs_new != NULL) {
        mx_open_dir(arr_dirs_new, audit);
        mx_del_strarr(&arr_dirs_new);
    }
}

static char **read_dir_2(char **arr_dirs, int u, int *count_el, DIR *dir) {
    struct dirent *entry;
    char **overall_arr;
    int numb = mx_count_obj_d(arr_dirs[u]);

    overall_arr = (char **)malloc(sizeof(char *) * (numb + 1));
    overall_arr[numb] = NULL;
    while ((entry = readdir(dir)) != NULL)
        overall_arr[(*count_el)++] = mx_strdup(entry->d_name);
    closedir(dir);
    return overall_arr;
}

void mx_open_dir(char **arr_dirs, t_add_in_func *audit) {
    DIR *dir;
    int count_el = 0;
    char **overall_arr;
    int u = 0;

    mx_sort(arr_dirs, audit);
    for (u = 0; arr_dirs[u] != NULL; u++) {
        count_el = 0;
        dir = opendir(arr_dirs[u]);
        if (mx_check_denied(arr_dirs[u], audit) == 1)
            continue;
        overall_arr = read_dir_2(arr_dirs, u, &count_el, dir);
        if (overall_arr[0] != NULL)
            mx_print_result(overall_arr, audit, arr_dirs[u]);
        if (audit->flags[3] == 1)
            namecpy(overall_arr, count_el, arr_dirs[u], audit);
        mx_del_strarr(&overall_arr);
    }
}

void mx_enter_fileordir(int argc, char **argv, t_add_in_func *audit) {
    char **arr_files = mx_arr_files(argc, argv);
    char **arr_dirs = mx_arr_dirs_1(argc, argv, audit);

    if (audit->flags[9] == 1) {
        mx_d_flag(arr_files, arr_dirs, audit);
        if (arr_files != NULL)
            mx_del_strarr(&arr_files);
        if (arr_dirs != NULL)
            mx_del_strarr(&arr_dirs);
        return;
    }
    if (arr_files != NULL) {
        mx_print_result(arr_files, audit, NULL);
        mx_del_strarr(&arr_files);
    }
    if (arr_dirs != NULL) {
        mx_open_dir(arr_dirs, audit);
        mx_del_strarr(&arr_dirs);
    }
}
