#include "../inc/uls.h"

static int mx_count_obj_d(const char *str) {
    int res = 0;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(str);

    while ((entry = readdir(dir)) != NULL)
        res++;
    closedir(dir);
    return res;
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

static void open_dir(char **arr_dirs, char **argv);

static void namecpy(char **overall_arr, int count_el, char *arr_dirs, char **argv) {
    int u = 0;
    char *new1;
    char *new2;
    char **arr_dirs_new;

    for (u = 0; overall_arr[u] != NULL; u++) {
        if (mx_strcmp(overall_arr[u], ".") != 0
            && mx_strcmp(overall_arr[u], "..") != 0) {
            new1 = mx_strjoin(arr_dirs, "/");
            new2 = mx_strjoin(new1, overall_arr[u]);
            free(overall_arr[u]);
            overall_arr[u] = mx_strdup(new2);
            free(new1);
            free(new2);
        }
    }
    arr_dirs_new = mx_arr_dirs_2(count_el, overall_arr);
    if (arr_dirs_new != NULL) {
        mx_sort_overallarr(arr_dirs_new);
        open_dir(arr_dirs_new, argv);
        mx_del_strarr(&arr_dirs_new);
    }
}

static void open_dir(char **arr_dirs, char **argv) {
    DIR *dir;
    int count_el = 0;
    char **overall_arr;
    int u = 0;

    for (u = 0; arr_dirs[u] != NULL; u++) {
        count_el = 0;
        dir = opendir(arr_dirs[u]);
        if (check_denied(arr_dirs[u], arr_dirs, u, argv) == 1)
            continue;
        overall_arr = read_dir_2(arr_dirs, u, &count_el, dir);
        if (overall_arr[0] != NULL)
            mx_print_result(overall_arr, 1, arr_dirs[u], argv);
        namecpy(overall_arr, count_el, arr_dirs[u], argv);
        mx_del_strarr(&overall_arr);
    }
}

void mx_flag_aR(int argc, char **argv) {
    char **arr_files = mx_arr_files(argc, argv);
    char **arr_dirs = mx_arr_dirs(argc, argv);

    if (arr_files != NULL)
        mx_output_with_atr(arr_files);
    if (arr_dirs != NULL) {
        mx_sort_overallarr(arr_dirs);
        if (arr_files != NULL)
            mx_printstr("\n");
        open_dir(arr_dirs, argv);
    }
    if (arr_files != NULL)
        mx_del_strarr(&arr_files);
    if (arr_dirs != NULL)
        mx_del_strarr(&arr_dirs);
}
