#include "../inc/libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    char *res_str = NULL;
    int len = 0;
    int count = 0;
    int res_count = 0;
    if(!s1 && !s2) {
        return NULL;
    }
    if(s1 && !s2) {
        res_str = mx_strnew(mx_strlen(s1));
        res_str = mx_strcpy(res_str, s1);
        return res_str;
    }
    else if(!s1 && s2) {
        res_str = mx_strnew(mx_strlen(s2));
        res_str = mx_strcpy(res_str, s2);
        return res_str;
    }
    len = mx_strlen(s1) + mx_strlen(s2);
    res_str = mx_strnew(len);
    while(s1[count]) {
        res_str[res_count] = s1[count];
        count++;
        res_count++;
    }
    count = 0;
    while(s2[count]) {
        res_str[res_count] = s2[count];
        count++;
        res_count++;
    }
    return res_str;
}
