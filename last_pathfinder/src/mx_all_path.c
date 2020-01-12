#include "../inc/pathfinder.h"

static int count_len(t_arrays *main_arrays) {
    int len = 0;

    while (main_arrays->no_repeat[len]) {
        len++;
    }
    return len;
}

static int count_array(t_arrays *main_arrays) {
    int res = 0;
    int len = count_len(main_arrays);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (main_arrays->arr_path[i][j] != 90) {
                res++;
            }
        }
    }
    return res;
}

void mx_all_path(t_arrays *main_arr) {
    int len = count_len(main_arr);
    int all_count = count_array(main_arr);
    int test_count = 0;
    int copy_count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
                for (int q = 0; q < len; q++) {
                    printf("%d ", main_arr->all_path_dist[i][j][q]);
                }
            printf("%c ", '\n');
        }
        printf("%c ", '\n');
    }
    ///////////
    for (int count = 0; count < len; count++) {
        test_count = 0;
        printf("%s", "FROM: ");
        printf ("%s", main_arr->no_repeat[count]);
        printf("%c", '\n');
        while (test_count < all_count) {
            for (int i = count; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    if (i != j) {
                        if (main_arr->all_path_dist[count][i][j] != 90) {
                                main_arr->all_path_dist[count][i][j] = 90;
                            printf("%s", main_arr->no_repeat[j]);
                            printf("%d", test_count);
                            //main_arr->all_path[count][i] = mx_strcpy(&main_arr->all_path[count][i][copy_count], main_arr->no_repeat[j]);
                            main_arr->all_path[count][test_count][copy_count] = main_arr->no_repeat[j][0];
                            main_arr->all_path[count][test_count][copy_count + 1] = ' ';
                            copy_count += 2;
                            //printf("%s", main_arr->all_path[count][j]);
                            //copy_count += mx_strlen(main_arr->no_repeat[j]);
                            //main_arr->all_path[count][i] = mx_strcpy(&main_arr->all_path[count][i][copy_count], " ");
                            //main_arr->all_path[count][i][copy_count] = '1';
                            printf("%s", " ");
                            i = j;
                        }
                    }
                }
            }
            printf("%c", '\n');
            test_count++;
        }
    printf("%c", '\n');
    }
        printf("%s", "\n");
    //    for (int i = 0; i < len; i++) {
    //     printf("%s  ", main_arr->no_repeat[i]);
    //     for (int j = 0; j < len; j++) {
    //         printf("%d  ", main_arr->all_path_dist[0][i][j]);
    //     }
    //     printf("%s", "\n");
    // }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            printf("%s ", main_arr->all_path[i][j]);
            printf("%c", '\n');
        }
        printf("%c", '\n');
    }
}
