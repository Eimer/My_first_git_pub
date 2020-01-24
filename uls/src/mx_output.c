#include "../inc/uls.h"

static int which_element(int argc, char **argv, char **sorted_overall_arr) {
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

static void write_tabs(int argc, char **argv, int word_len) {
    int longest = mx_count_longest(argc, argv);
    int number_of_tabs = 0;
    int result_number_of_tabs = 0;

    if (longest % 8 == 0)
        longest++;
    while (longest % 8 != 0)
        longest++;
    number_of_tabs = longest - word_len;
    if (number_of_tabs % 8  == 0) {
        result_number_of_tabs = number_of_tabs / 8;
    }
    else
        result_number_of_tabs = number_of_tabs / 8 + 1;

    for (int i = 0; i < result_number_of_tabs; i++) {
        mx_printchar('\t');
    }
}

void mx_output(int argc, char **argv, char **overall_arr) {
    char **sorted_overall_arr = mx_sort_overallarr(overall_arr);
    int main_row = which_element(argc, argv, sorted_overall_arr);
    int amount_obj = mx_count_obj(sorted_overall_arr);
    int buffer_count = 0;
    int count_out = 0;

    for (int i = 0; i < amount_obj; i++) {
        if (count_out >= amount_obj) {
            mx_printchar('\n');
            buffer_count++;
            count_out = buffer_count;
        }
        mx_printstr(sorted_overall_arr[count_out]);
        if (count_out + main_row < amount_obj)
            write_tabs(argc, argv, mx_strlen(sorted_overall_arr[count_out]));
        count_out += main_row;
    }
    mx_printchar('\n');
}

