#include "../inc/uls.h"

int mx_dirorfile(const char *obj) {
    DIR *dir;
    int file;

    dir = opendir(obj);
    if (dir) {
        closedir(dir);
        return 0;
    }
    else {
        file = open(obj, O_RDONLY);
        if (file != -1) {
            close(file);
            return 1;
        }
    }
    return -1;
}
