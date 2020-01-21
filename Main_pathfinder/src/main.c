#include "../inc/pathfinder.h"

static int count_len(t_arrays *main_arrays) {
    int len = 0;

    while (main_arrays->no_repeat[len]) {
        len++;
    }
    return len;
}

static void free_st(t_arrays *main_arr) {
    int count = 0;

    while (main_arr->arr_to[count]) {
        free(main_arr->arr_from[count]);
        free(main_arr->arr_to[count]);
        free(main_arr->arr_dist[count]);
        count++;
    }
}

int main(int argc, char *argv[]) {
    char *str_from_file = NULL;
    int len = 0;

    mx_errors(argc, argv);
    str_from_file = mx_file_to_str(argv[1]);
    t_arrays *main_arr = mx_fill_s_arr(str_from_file, argv);

    len = count_len(main_arr);
    mx_path_dist(main_arr);
    free_st(main_arr);
    return 0;
}
