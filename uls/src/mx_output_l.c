#include "../inc/uls.h"

static int count_numbers(int number) {
    int res = 0;
    while (number != 0) {
        number = number / 10;
        res++;
    }
    printf("%d ", res);
    return res;
}

static int count_spaces_first_col(char *obj) {
    struct stat buf;
    lstat(obj, &buf);
    int len_amount_links = 0;
    return len_amount_links;
}

void mx_output_l(char *obj) {
    DIR *dir;
    struct dirent *entry;
    
    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            mx_get_obj_info(entry->d_name);
            count_spaces_first_col(obj);
        }
    }
    else {
        mx_get_obj_info(obj);
    }
}
