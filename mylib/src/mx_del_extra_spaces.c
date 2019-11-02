#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    int buff_len = 0;
    char *res_str = NULL;
    int q = 0;
    if(!str) {
        return NULL;
    }
    for(int i = 0; i < mx_strlen(str); i++){
        if(str[i] >=9 && str[i] <= 13) {
            continue;
        }
        if(str[i] == 32) {
            if(str[i + 1] == 32) {
                continue;
            }
        }
        buff_len++;
    }

    res_str = mx_strnew(buff_len);
    for(int i = 0; i < mx_strlen(str); i++){
        if(str[i] >=9 && str[i] <= 13) {
            continue;
        }
        if(str[i] == 32) {
            if(str[i + 1] == 32) {
                continue;
            }
        }
        res_str[q] = str[i];
        q++;
    }
    return mx_strtrim(res_str);
}
