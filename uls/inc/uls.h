#ifndef ULS_H
#define ULS_H

#include "../libmx/inc/libmx.h"
#include "ypratsovit.h"
#include "dashuta.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

typedef struct  s_size {
    unsigned short col;
    unsigned short row;
} t_size;

void mx_printerr(const char *s);
t_size mx_get_screencoord();
void mx_errors(int argc,  char **argv);
int mx_dirorfile(const char *obj);
int mx_dirorfile(const char *obj);
char **mx_arr_files(int argc, char **argv);
char **mx_arr_dirs(int argc, char **argv);
int mx_count_longest(int argc, char **argv);
int mx_count_col(int argc, char **argv);
char **mx_arr_dirs(int argc, char **argv);
char **mx_uls_noatr(int argc, char **argv);
char **mx_sort_overallarr(char **);
void mx_output(int argc, char **argv, char **overall_arr);
int mx_count_obj(char **overall_arr);

#endif
