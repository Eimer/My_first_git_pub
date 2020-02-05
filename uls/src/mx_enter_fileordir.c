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

int check_denied(char *arr_dirs_u) {
    DIR *dir;
    errno = 0;

    dir = opendir(arr_dirs_u);
    if (dir) {
        closedir(dir);
        return 0;
    }
    if (errno != 0) {
        // mx_printstr("\n");
        mx_printstr(arr_dirs_u);
        mx_printstr(":\n");
        mx_printerr("uls: ");
        mx_printerr(mx_memrchr(arr_dirs_u, '/', mx_strlen(arr_dirs_u)));
        mx_printerr(strerror(errno));
        mx_printerr("\n");
        return 1;
    }
    return 0;
}

static char **read_dir_2(char **arr_dirs, int u, int count_el, DIR *dir) {
    struct dirent *entry;
    char **overall_arr;
    int numb = mx_count_obj_d(arr_dirs[u]);

    overall_arr = (char **)malloc(sizeof(char *) * (numb + 1));
    for (int k = 0; k <= numb; k++)
        overall_arr[k] = NULL;
    while ((entry = readdir(dir)) != NULL)
        overall_arr[count_el++] = mx_strdup(entry->d_name);
    closedir(dir);
    return overall_arr;
}

static void open_dir_efd(char **arr_dirs, t_add_in_func *audit) {
    DIR *dir;
    int count_el;
    char **overall_arr;

    for (int u = 0; arr_dirs[u] != NULL; u++) {
        count_el = 0;
        dir = opendir(arr_dirs[u]);
        if (check_denied(arr_dirs[u]) == 1)
            continue;
            overall_arr = read_dir_2(arr_dirs, u, count_el, dir);
        if (overall_arr[0] != NULL)
            mx_print_result(overall_arr, audit, arr_dirs[u]);
        mx_del_strarr(&overall_arr);
    }
}

void mx_enter_fileordir(int argc, char **argv, t_add_in_func *audit) {
    char **arr_files = mx_arr_files(argc, argv);
    char **arr_dirs = mx_arr_dirs_1(argc, argv, audit);

    if (arr_files != NULL) {
        mx_output_with_atr(arr_files);
        mx_del_strarr(&arr_files);
    }
    if (arr_dirs != NULL) {
        mx_sort_overallarr(arr_dirs);
        open_dir_efd(arr_dirs, audit);
        mx_del_strarr(&arr_dirs);
    }
}
