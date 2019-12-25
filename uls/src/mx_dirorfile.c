#include "../inc/uls.h"

<<<<<<< HEAD
static int (const char *argv[]) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(argv[1]);
    if (!dir) {
        perror("diropen");
        exit(1);
    };
    while ( (entry = readdir(dir)) != NULL) {
        mx_printstr(entry->d_name);
        mx_printstr("\t");
    }
    mx_printstr("\n");
    closedir(dir);
}
=======
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
        if(file != -1) {
            close(file);
            return 1;
        }
    }
    return -1;
}
>>>>>>> master
