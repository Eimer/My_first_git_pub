#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    int f;
    int bts = 0;
    int i = 0;
    char buff;
    char *res_str = NULL;
    if(((f = open(file, O_RDONLY)) == -1)) {
        return NULL;
    }
    bts = read(f, &buff, 1);
    if(!bts) {
        return NULL;
    }
    while(bts) {
        bts = read(f, &buff, 1);
        i++;
    }
    close(f);
    res_str = mx_strnew(i);
    f = open(file, O_RDONLY);

    for(int j = 0; j < i; j++) {
        read(f, &res_str[j], 1);
    }
    return res_str;
}
