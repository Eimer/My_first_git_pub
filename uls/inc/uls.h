#ifndef ULS_H
#define ULS_H

#include "../libmx/inc/libmx.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/ioctl.h>
#include <fcntl.h>

typedef struct  s_size {
    unsigned short col;
    unsigned short row;
} t_size;

void mx_printerr(const char *s);
t_size mx_get_screencoord();

#endif
