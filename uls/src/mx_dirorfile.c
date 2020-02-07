#include "../inc/uls.h"

int mx_dirorfile(const char *obj) {
    struct stat obj_stat;
    errno = 0;
    lstat(obj, &obj_stat);

    if (S_ISDIR(obj_stat.st_mode)) {
        return 0;
    }
    else if (errno == 13)
        return 0;
    else 
        return 1;
    return -1;
}
