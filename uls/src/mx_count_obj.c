#include "../inc/uls.h"

int mx_count_obj(char **overall_arr) {
    int count = 0;

    while (overall_arr[count])
        count++;
    return count;
}
