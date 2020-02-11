#ifndef YPRATSOVIT_H
#define YPRATSOVIT_H

#include <stdio.h>
#include <sys/acl.h>
#include <time.h>
#include <sys/xattr.h>
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

typedef struct s_spaces_l {
    int first_col;
    int second_col;
    int third_col;
    int fourth_col;
    int count;
    blkcnt_t total;
} t_spaces_l;

typedef struct s_buffer_struct_l {
    DIR *dir;
    struct dirent *entry;
    char **sorted_arr_l;
    char *tmp;
    struct stat buf;
} t_buffer_struct_l;

int mx_count_longest_with_atr(char **overall_arr);
int mx_count_col_with_atr(char **overall_arr);
void mx_output_with_atr(char **overall_arr);
void mx_get_obj_info(char *obj_name, char *not_need, t_spaces_l *spaces);
void mx_get_xatr(char *obg);
int mx_spaces_first_col(char *obj);
int longest_numbers_links(char *obj);
int mx_count_numbers(int number);
int mx_longest_numbers_links(char *obj);
int mx_longest_numbers_pwuid(char *obj);
int mx_longest_numbers_pwgid(char *obj);
int mx_longest_numbers_st_size(char *obj);
int mx_mystrcmp(const char *s1, const char *s2);

#endif
