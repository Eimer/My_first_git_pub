#include "../inc/uls.h"

int mx_count_col(int argc, char const *argv[]) {
    int col = 0;
    int longest = mx_count_longest(argc, argv);
    t_size screen_res = mx_get_screencoord();

    col = screen_res.col/longest;
    //printf("%d", col);
    return col;
}
