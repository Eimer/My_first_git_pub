 #include "../inc/libmx.h"
 #include <stdio.h>
char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *res_str = NULL;
    int first_index;
    int last_index = 0;
    int res_len = 0;

    if(!str || !sub || !replace) {
        return NULL;
    }

    first_index = mx_get_substr_index(str, sub);
    last_index = first_index + mx_strlen(sub) - 1;
    res_len = mx_strlen(str) - mx_strlen(sub) + mx_strlen(replace);
    res_str = mx_strnew(res_len);
    for(int i = 0; i < res_len) {
        
    }
    return res_str;
    
}
