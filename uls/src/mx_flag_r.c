#include "../inc/uls.h"

static char **read_dir(char **arr_dirs, int u, int *count_el, DIR *dir) {
    struct dirent *entry;
    char **overall_arr;
    int numb = mx_count_obj_dash(arr_dirs[u]);

    overall_arr = (char **)malloc(sizeof(char *) * (numb + 3));
    overall_arr[numb] = NULL;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            overall_arr[(*count_el)] = mx_strdup(entry->d_name);
            (*count_el)++;
        }
    }
    closedir(dir);
    return overall_arr;
}

static void open_dir(char **arr_dirs, char **argv);

static void namecpy(char **overall_arr, int count_el, char *arr_dirs, char **argv) {
    int u = 0;

    for (u = 0; overall_arr[u] != NULL; u++) {
        char *new1 = mx_strjoin(arr_dirs, "/");
        char *new2 = mx_strjoin(new1, overall_arr[u]);
        free(overall_arr[u]);
        overall_arr[u] = mx_strdup(new2);
        free(new1);
        free(new2);
    }
    char **arr_dirs_new = mx_arr_dirs_1(count_el, overall_arr);
    if (arr_dirs_new != NULL) {
        mx_printstr("\n");
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
        overall_arr = read_dir(arr_dirs, u, &count_el, dir);
        if (overall_arr[0] != NULL)
            mx_output_with_atr(overall_arr);
        namecpy(overall_arr, count_el, arr_dirs[u], argv);
        if (arr_dirs[u + 1] != NULL)
            mx_printchar(10);
        mx_del_strarr(&overall_arr);
    }
}

void mx_flag_r(int argc, char **argv) {
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
