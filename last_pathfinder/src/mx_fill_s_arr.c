#include "../inc/pathfinder.h"

static int count_len(t_arrays *main_arrays) {
    int len = 0;

    while (main_arrays->no_repeat[len]) {
        len++;
    }
    return len;
}

static int ***fill_all_path_dist (t_arrays *main_arrays) {
    int len = count_len(main_arrays);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            for (int q = 0; q < len; q++) {
                main_arrays->all_path_dist[i][j][q] = main_arrays->arr_path[j][q];
            }
        }
    }
    return main_arrays->all_path_dist;
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
    main_arrays->all_path_dist = (int ***)malloc(sizeof(int **) * len);
    for (int i = 0; i < len; i++) {
        main_arrays->all_path_dist[i] = (int **)malloc(sizeof(int *) * len);
        for (int j = 0; j < len; j++) {
            main_arrays->all_path_dist[i][j] = (int *)malloc(sizeof(int) * len);
            for (int q = 0; q < len; q++) {
                main_arrays->all_path_dist[i][j][q] = -1;
            }
        }
    }
    main_arrays->all_path = (char***)malloc(sizeof(char **) * len);
    for (int i = 0; i < len; i++){
        main_arrays->all_path[i] = (char **)malloc(sizeof(char *) * len);
        for (int j = 0; j < len; j++) {
            main_arrays->all_path[i][j] = mx_strnew(110);
            mx_strcpy(main_arrays->all_path[i][j], "1111111111");
        }
    }
    main_arrays->all_path_dist = fill_all_path_dist(main_arrays);
    return main_arrays;
}
