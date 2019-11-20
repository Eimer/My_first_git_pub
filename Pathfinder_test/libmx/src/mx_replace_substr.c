#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    char *res_str = NULL;
    int first_index;
    int last_index = 0;
    int res_len = 0;
    int main_count = 0;
    int repl_count = 0;
    int buffer_len = 0;
    if(!str || !sub || !replace) {
        return NULL;
    }
    first_index = mx_get_substr_index(str, sub);
    last_index = first_index + mx_strlen(sub) - 1;
    res_len = mx_strlen(str) - mx_strlen(sub) + mx_strlen(replace);
    res_str = mx_strnew(res_len);
    while(main_count != first_index) {
        res_str[main_count] = str[main_count];
        main_count++;
    }
    buffer_len = main_count + mx_strlen(replace);
    while(main_count != buffer_len) {
        res_str[main_count] = replace[repl_count];
        repl_count++;
        main_count++;
    }
    while(main_count < mx_strlen(str) && str[main_count + 1]) {
        res_str[main_count] = str[main_count + 1];
        main_count++;
    }

    return res_str;
}
