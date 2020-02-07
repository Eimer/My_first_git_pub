#include "../inc/uls.h"

int mx_dirorfile(const char *obj) {
    // DIR *dir;
    // int file;
    // errno = 0;

    // dir = opendir(obj);
    // if (dir) {
    //     closedir(dir);
    //     return 0;
    // }
    // else if (errno == 13)
    //     return 0;
    // else {
    //     file = open(obj, O_RDONLY);
    //     if (file != -1) {
    //         close(file);
    //         return 1;
    //     }
    // }
    // return -1;
    struct stat obj_stat;
    errno = 0;
    lstat(obj, &obj_stat);

    if (S_ISDIR(obj_stat.st_mode))
        return 0;
    else if (errno == 13)
        return 0;
    if (S_ISFIFO(obj_stat.st_mode))
        return 1;
    return -1;
}
