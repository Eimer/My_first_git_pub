#include "../inc/uls.h"

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