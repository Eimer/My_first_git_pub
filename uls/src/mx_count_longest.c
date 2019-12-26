#include "../inc/uls.h"

int mx_count_longest(int argc, char const *argv[]) {
    int longest = 0;
    
    for (int i = 1; i < argc; i++) {
        if (mx_strlen(argv[i]) > longest) {
            longest = mx_strlen(argv[i]);
        }
    }
    return longest;
}
