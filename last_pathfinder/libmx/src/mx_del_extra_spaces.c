#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    
    char *buff_str = NULL;
    char *res_str = NULL;
    int res_len = 0;
    char *s;
    if(!str) {
        return NULL;
    }
    buff_str = mx_strnew(mx_strlen(str));
    buff_str = mx_strcpy(buff_str, str);
    
    for(int i = 0; i < mx_strlen(buff_str); i++) {
        if(buff_str[i] >=9 && buff_str[i] <= 13) {
            buff_str[i] = 32;
        }
    }
    s = mx_strtrim(buff_str);
    for(int i = 0; i < mx_strlen(s); i++) {
        if(s[i] == 32) {
            if(s[i + 1] == 32) {
                s[i] = '\n';
                continue;
            }
        }
        res_len++;
    }
    res_str = mx_strnew(res_len);
    res_len = 0;
    for(int i = 0; i < mx_strlen(s); i++) {
        if(s[i] == '\n') {
            continue;
        }
        else {
            res_str[res_len] = s[i];
            res_len++;
        }
    }
    free(buff_str);
    free(s);
    return res_str;
}
