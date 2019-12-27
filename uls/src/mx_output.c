#include "../inc/uls.h"


void mx_output(int argc, char const *argv[], char **overall_arr) {
    int col = mx_count_col(argc, argv);
    
    printf("%d", col);

    overall_arr = NULL;
}
