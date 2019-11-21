#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    int i = 0;
    int j = 0;
    int result_len = 0;
    char *res_str = NULL;
        if(!str) {
        return NULL;
    }
    j = mx_strlen(str) - 1;
    while(str[i]) {
        if((str[i] < 9 || str[i] > 13) && str[i] != 32) {
            break;
        }
        i++;
    }
    while(str[j]) {
        if((str[j] < 9 || str[j] > 13) && str[j] != 32) {
            break;
        }
        j--;
    }
    result_len = j - i + 1;
    res_str = mx_strnew(result_len);
    result_len = 0;
    for(int q = i; q <= j; q++, result_len++) {
        res_str[result_len] = str[q];
    }
    return (char *)res_str;
}
