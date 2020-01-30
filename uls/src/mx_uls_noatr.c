#include "../inc/uls.h"

static int count_obj() {
    int res = 0;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");

    while ((entry = readdir(dir)) != NULL)
        //if (entry->d_name[0] != '.')
            res++;
    closedir(dir);
    return res;
}

char **mx_uls_noatr(int argc, char **argv) {
    DIR *dir;
    struct dirent *entry;
    int count_el = 0;
    char **overall_arr = (char **)malloc(sizeof(char *) * (count_obj() + 1));

    overall_arr[count_obj()] = NULL;
    dir = opendir(".");
    while ((entry = readdir(dir)) != NULL) {
        // if (entry->d_name[0] != '.') {
            overall_arr[count_el] = mx_strnew(mx_strlen(entry->d_name));
            overall_arr[count_el] = mx_strcpy(overall_arr[count_el], entry->d_name);
            count_el++;
        // }
    }
    closedir(dir);
    mx_output(argc, argv, overall_arr);
    return overall_arr;
}
