#include "../inc/uls.h"

static int multiple(int longest) {
    int multiple = longest;
    
    if(multiple % 8 == 0)
        multiple++;

    while (multiple % 8 != 0) {
        multiple++;
    }
    
    return multiple;
}

int mx_count_col(int argc, char const *argv[]) {
    int col = 0;
    int longest = mx_count_longest(argc, argv);
    int each_obj = multiple(longest);
    t_size screen_res = mx_get_screencoord();
    
    col = screen_res.col/each_obj;

    return col;
}
