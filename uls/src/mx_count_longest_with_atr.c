#include "../inc/uls.h"

int mx_count_longest_with_atr(char **overall_arr) {
    int longest = 0;
    int count = 0;

    while (overall_arr[count]) {
        if (mx_strlen(overall_arr[count]) > longest)
            longest = mx_strlen(overall_arr[count]);
        count++;
    }
    return longest;
}
