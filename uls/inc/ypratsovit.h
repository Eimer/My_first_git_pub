#ifndef YPRATSOVIT_H
#define YPRATSOVIT_H

#include <stdio.h>
#include <sys/acl.h>
#include <time.h>
#include <sys/xattr.h>

typedef struct s_spaces_l {
    int first_col;
    int second_col;
    int third_col;
    int fourth_col;
    int count;
} t_spaces_l;

int mx_count_longest_with_atr(char **overall_arr);
int mx_count_col_with_atr(char **overall_arr);
void mx_output_with_atr(char **overall_arr);
void mx_get_obj_info(char *obj_name, char *not_need, t_spaces_l *spaces);
void mx_get_xatr(char *obg);
void mx_output_l(char *obj);
int mx_spaces_first_col(char *obj);
int longest_numbers_links(char *obj);
int mx_count_numbers(int number);
int mx_longest_numbers_links(char *obj);
int mx_longest_numbers_pwuid(char *obj);

#endif
