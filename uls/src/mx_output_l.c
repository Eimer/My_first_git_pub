#include "../inc/uls.h"

static int count_el_before_sorted(char *obj) {
    int res = 0;
    DIR *dir = NULL;
    struct dirent *entry;

    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL)
            res++;
    closedir(dir);
    }
    return res;
}

void mx_output_l(char *obj) {
    DIR *dir = NULL;
    struct dirent *entry;
    char **sorted_arr_l = NULL;
    char *tmp = NULL;
    t_spaces_l *spaces = (t_spaces_l*)malloc(sizeof(t_spaces_l));
    system("leaks -q a.out");
    spaces->count = count_el_before_sorted(obj);
    if (spaces->count != 0) {
        sorted_arr_l = (char**)malloc(sizeof(char*) * spaces->count + 1);
        sorted_arr_l[spaces->count] = NULL;
    }
    if (mx_dirorfile(obj) == 0) {
        spaces->count = 0;
        tmp = mx_strjoin(obj, "/");
        dir = opendir(tmp);
        spaces->first_col = mx_longest_numbers_links(tmp);
        while ((entry = readdir(dir)) != NULL) {
                sorted_arr_l[spaces->count] = mx_strnew(mx_strlen(tmp) + mx_strlen(entry->d_name));
                sorted_arr_l[spaces->count] = mx_strjoin(tmp, entry->d_name);
                spaces->count++;
        }

        sorted_arr_l = mx_sort_overallarr(sorted_arr_l);
        spaces->count = 0;
        while (sorted_arr_l[spaces->count]) {
            mx_get_obj_info(sorted_arr_l[spaces->count], obj, spaces);
            spaces->count++;
        }
    }
    else {
        mx_get_obj_info(obj, obj, spaces);
    }
    if (mx_dirorfile(obj) == 0) {
        spaces->count = 0;
        while (sorted_arr_l[spaces->count]) {
            free(sorted_arr_l[spaces->count]);
            spaces->count++;
        }
        free(sorted_arr_l);
        free(tmp);
        closedir(dir);
    }
}
