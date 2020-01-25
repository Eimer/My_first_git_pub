#include "../inc/uls.h"

static int count_obj(const char *str) {
    int res = 0;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(str);

    while ((entry = readdir(dir)) != NULL)
        if (entry->d_name[0] != '.')
            res++;
    closedir(dir);
    return res;
}

static int check_denied(char *arr_dirs_u, char **arr_dirs, int u) {
    DIR *dir;

    if (arr_dirs[1] != NULL) {
        mx_printstr(arr_dirs[u]);
        mx_printstr(":\n");
    }
    dir = opendir(arr_dirs_u);
    if (dir) {
        closedir(dir);
        return 0;
    }
    else if (errno == 13) {
        mx_printerr("./uls: ");
        mx_printerr(arr_dirs_u);
        mx_printerr(": Permission denied\n");
        if (arr_dirs[1] != NULL && arr_dirs[u + 1] != NULL)
            mx_printstr("\n");
        return 1;
    }
    return 0;
}

static char **read_dir(char **arr_dirs, int u, int *count_el, DIR *dir) {
    struct dirent *entry;
    char **overall_arr;
    int numb = count_obj(arr_dirs[u]);

    overall_arr = (char **)malloc(sizeof(char *) * (numb + 1));
    overall_arr[numb] = NULL;
    while ((entry = readdir(dir)) != NULL)
        if (entry->d_name[0] != '.') {
            overall_arr[(*count_el)] = mx_strdup(entry->d_name);
            (*count_el)++;
        }
    closedir(dir);
    return overall_arr;
}

static void open_dir(char **arr_dirs) {
    DIR *dir;
    int count_el;
    char **overall_arr;
    int u = 0;
    char **arr_dirs_new;

    for (u = 0; arr_dirs[u] != NULL; u++) {
        count_el = 0;
        dir = opendir(arr_dirs[u]);
        if (check_denied(arr_dirs[u], arr_dirs, u) == 1)
            continue;
        overall_arr = read_dir(arr_dirs, u, &count_el, dir);
        if (overall_arr[0] != NULL)
            mx_output_with_atr(overall_arr);
        arr_dirs_new = mx_arr_dirs(count_el, overall_arr);
        if (arr_dirs_new != NULL)
        open_dir(arr_dirs_new);
        // mx_del_strarr(&arr_dirs_new);
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
        open_dir(arr_dirs);
    }
    if (arr_files != NULL)
        mx_del_strarr(&arr_files);
    if (arr_dirs != NULL)
        mx_del_strarr(&arr_dirs);
}
