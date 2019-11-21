#include "../inc/pathfinder.h"

int mx_invalid_line(char* str) {
    int i = 0;
    int j = 0;
    int q = 0;
    char **lines_arr = NULL;
    lines_arr = mx_strsplit(str, '\n');
    while(lines_arr[i]) {
        if(mx_count_words(lines_arr[i], '-') != 2 || mx_count_words(lines_arr[i], ',') != 2) {
            return i + 2;
        }
        i++;
    }
    while(lines_arr[j]) {
        for(int i = 0; i < mx_strlen(lines_arr[j]) - 1; i++) {
            if(lines_arr[j][i] == '-') {
                if(lines_arr[j][i + 1] == '-') {
                    return j + 2;
                }
            }
            if(lines_arr[j][i] == ',') {
                if(lines_arr[j][i + 1] == ',') {
                    return j + 2;
                }
            }
        }
        j++;
    }
    while(lines_arr[q]) {
        if(mx_is_number(lines_arr[q]) == false) {
            return q + 2;
        }
        q++;
    }
    return 0;
}
