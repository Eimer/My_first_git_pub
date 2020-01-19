#include "../inc/pathfinder.h"

static int count_len(t_arrays *main_arrays) {
    int len = 0;

    while (main_arrays->no_repeat[len]) {
        len++;
    }
    return len;
}

int main(int argc, char *argv[]) {
    char *str_from_file = NULL;
    int len = 0;

    mx_errors(argc, argv);
    str_from_file = mx_file_to_str(argv[1]);
    t_arrays *main_arr = mx_fill_s_arr(str_from_file, argv);
    len = count_len(main_arr);
    main_arr = mx_path_dist(main_arr);

    printf("%s", "    ");
    for (int i = 0; i < len; i++) {
        printf("%s  ", main_arr->no_repeat[i]);
    }
    printf("%c", '\n');
    
    for (int i = 0; i < len; i++) {
        printf("%s  ", main_arr->no_repeat[i]);
        for (int j = 0; j < len; j++) {
            printf("%d  ", main_arr->arr_path[i][j]);
        }
        printf("%s", "\n");
    }
printf("%s", "\n");
    for (int i = 0; i < len; i++) {
        printf("%s  ", main_arr->no_repeat[i]);
        for (int j = 0; j < len; j++) {
            printf("%d  ", main_arr->shortest_path[i][j]);
        }
        printf("%s", "\n");
    }
mx_all_path(main_arr);
    ///////////////////
    ///////////////////
    ///////////////////
    // for (int i = 0; i < 7; i++) {
    //     free(main_arr->arr_from[i]);
    //     free(main_arr->arr_to[i]);
    //     free(main_arr->arr_dist[i]);
    //     free(main_arr->arr_path[i]);
    // }
    //system("leaks -q a.out");
    return 0;
}
