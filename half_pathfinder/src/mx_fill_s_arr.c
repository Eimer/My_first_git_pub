#include "../inc/pathfinder.h"

static int count_len(t_arrays *main_arrays) {
    int len = 0;

    while (main_arrays->no_repeat[len]) {
        len++;
    }
    return len;
}


t_arrays *mx_fill_s_arr(char *str_from_file, char *argv[]) {
    t_arrays *main_arrays = (t_arrays *)malloc(sizeof(t_arrays));
    int len = 0;

    main_arrays->arr_dist = mx_arr_dist(str_from_file);
    main_arrays->arr_from = mx_arr_from(str_from_file);
    main_arrays->arr_to = mx_arr_to(str_from_file);
    main_arrays->arr_path = mx_arr_path(argv);
    main_arrays->shortest_path = mx_arr_path(argv);
    main_arrays->no_repeat = mx_get_no_repeat(argv);
    len = count_len(main_arrays);
    
    return main_arrays;
}
