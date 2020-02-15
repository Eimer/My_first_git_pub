#include "libmx.h"

char *mx_file_to_str(const char *file) {
    char s;
    char *dst = NULL;
    int fd;
    int rd = 0;
    int i = 0;

    if ((fd = open(file, O_RDONLY)) == -1)
        return NULL;
    rd = read(fd, &s, 1);
    while (rd) { 
        rd = read(fd, &s, 1);
        i++;
    }
    close(fd);
    dst = mx_strnew(i);
    fd = open(file, O_RDONLY);
    for (rd = 0; rd <= i; rd++)
        read(fd, &dst[rd], 1);
    return dst;
}
