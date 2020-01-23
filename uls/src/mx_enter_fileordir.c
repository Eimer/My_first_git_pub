#include "../inc/uls.h"

static int count_obj(const char *str) {
    int res = 0;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(str);
mx_printstr(" lol ");
    while ((entry = readdir(dir)) != NULL)
        if (entry->d_name[0] != '.')
            res++;
    closedir(dir);
    return res;
}


static void open_dir(char **arr_dirs) {
    DIR *dir;
    struct dirent *entry;
    int count_el;
    char **overall_arr;
mx_printstr(" lol ");
    for (int u = 0; arr_dirs[u] != NULL; u++) {
        count_el = 0;
        dir = opendir(arr_dirs[u]);
        if (arr_dirs[1] != NULL) {
            mx_printstr(arr_dirs[u]);
            mx_printstr(":\n");
        }
        mx_printstr(" lol1 ");
        overall_arr = (char **)malloc(sizeof(char *) * (count_obj(arr_dirs[u]) + 1));
        while ((entry = readdir(dir)) != NULL)
            if (entry->d_name[0] != '.') {
                overall_arr[count_el] = mx_strdup(entry->d_name);
                count_el++;
            }
        closedir(dir);
        mx_output_with_atr(overall_arr);
        if (arr_dirs[u + 1] != NULL)
            mx_printchar(10);
        // if (entry->d_name[0] != '.')
        //     mx_del_strarr(&overall_arr);
    }
}

void mx_enter_fileordir(int argc, char const *argv[]) {
    // if (argc == 1)
    //     mx_uls_noatr(argc, argv);
    // else {
        mx_errors(argc, argv);
        char **arr_files = mx_arr_files(argc, argv);
        char **arr_dirs = mx_arr_dirs(argc, argv);
mx_printstr(" lol1 ");
        if (arr_files != NULL)
            mx_output_with_atr(arr_files);
            mx_printstr(" lol2 ");
        if (arr_dirs != NULL) {
            // mx_sort_overallarr(arr_dirs);
            if (arr_files != NULL)
                mx_printstr("\n");
            open_dir(arr_dirs);
        }
        mx_printstr(" lol2 ");
        if (arr_files != NULL)
            mx_del_strarr(&arr_files);
        if (arr_dirs != NULL)
            mx_del_strarr(&arr_dirs);
    // }
}
