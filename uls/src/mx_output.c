#include "../inc/uls.h"

static int amount_col(int argc, char const *argv[], char **sorted_overall_arr) {
    int col = mx_count_col(argc, argv);
    int amount_obj = mx_count_obj(sorted_overall_arr);
    int res = 0;

    if (amount_obj % col != 0) {
        res = amount_obj / col + 1;
    } 
    else {
        res = amount_obj / col;
    }
    if (amount_obj % res != 0) {
        return amount_obj / res + 1;
    }
    else {
        return amount_obj / res;
    }
    return 0;

}

static int which_element(int argc, char const *argv[], char **sorted_overall_arr) {
    int col = mx_count_col(argc, argv);
    int amount_obj = mx_count_obj(sorted_overall_arr);
    int res = 0;

    if (amount_obj % col != 0) {
        res = amount_obj / col + 1;
    }
    else {
        res = amount_obj / col;
    }
    return res;
}

void mx_output(int argc, char const *argv[], char **overall_arr) {
    char **sorted_overall_arr = mx_sort_overallarr(overall_arr);
    int main_col = amount_col(argc, argv, sorted_overall_arr);
    int main_row = which_element(argc, argv, sorted_overall_arr);
    int amount_obj = mx_count_obj(sorted_overall_arr);
    int buffer_count = 0;
    int test = 0;


    for (int i = 0; i < amount_obj; i++) {
        if(i == main_col - 1) {
            printf("%c",'\n');
        }
        printf("%s", sorted_overall_arr[i]);
        buffer_count = mx_strlen(sorted_overall_arr[i]);
        while (buffer_count % 8 != 0) {
            printf("%c", '\t');
            buffer_count += 1;
        }
    }
    main_col = 0;
    main_row = 0;
    sorted_overall_arr = NULL;
}
