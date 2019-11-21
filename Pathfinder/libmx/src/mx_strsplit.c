#include "../inc/libmx.h"

static char *my_del_extra_spaces(const char *str , char c) {
    int buff_len = 0;
    char *res_str = NULL;
    char *s = NULL;
    int q = 0;
    if(!str) {
        return NULL;
    }
    for(int i = 0; i < mx_strlen(str); i++){
        if(str[i] == c) {
            if(str[i + 1] == c) {
                continue;
            }
        }
        buff_len++;
    }
    res_str = mx_strnew(buff_len);
    for(int i = 0; i < mx_strlen(str); i++){
        if(str[i] == c) {
            if(str[i + 1] == c) {
                continue;
            }
        }
        res_str[q] = str[i];
        q++;
    }
    s = mx_strtrim(res_str);
    free(res_str);
    return s;
}

char **mx_strsplit(const char *s, char c) {
    if(!s || !c) {
        return NULL;
    }
    char *buff_str = mx_strnew(mx_strlen(s));
    buff_str = mx_strcpy(buff_str, s);
    buff_str = my_del_extra_spaces(buff_str, c);
    char **res_arr = (char **)malloc(sizeof(char *) * mx_count_words(s, c));
    int count_symb = 0;
    int count = 0;
    int q = -1;
    int test = 0;
    for(int i = 0; i < mx_strlen(s); i++) {
        if(buff_str[i] == c) {
            count = i + 1;
            count_symb = 0;
            while(buff_str[count] != c && buff_str[count]) {
                count_symb++;
                count++;
            }
            if(count_symb != 0) {
                q++;
                res_arr[q] = mx_strnew(count_symb);
                test = i + 1;
                for(int j = 0; j < count_symb; j++) {
                    res_arr[q][j] = buff_str[test];
                    test++;
                }
                res_arr[q + 1] = NULL;
            }
        }
    }
    free(buff_str);
    return res_arr;
}
