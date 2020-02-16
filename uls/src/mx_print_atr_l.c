#include "../inc/uls.h"

void mx_print_atr_l(struct stat obj_stat, char *obj_name) {
    struct stat buf;

    lstat(obj_name, &buf);
    mx_printstr( (obj_stat.st_mode & MX_S_IRUSR) ? "r" : "-");
    mx_printstr( (obj_stat.st_mode & MX_S_IWUSR) ? "w" : "-");
    mx_printstr( (obj_stat.st_mode & MX_S_IXUSR) ? "x" : "-");
    mx_printstr( (obj_stat.st_mode & MX_S_IRGRP) ? "r" : "-");
    mx_printstr( (obj_stat.st_mode & MX_S_IWGRP) ? "w" : "-");
    mx_printstr( (obj_stat.st_mode & MX_S_IXGRP) ? "x" : "-");
    mx_printstr( (obj_stat.st_mode & MX_S_IROTH) ? "r" : "-");
    mx_printstr( (obj_stat.st_mode & MX_S_IWOTH) ? "w" : "-");
}
