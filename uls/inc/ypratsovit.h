#ifndef YPRATSOVIT_H
#define YPRATSOVIT_H

#include <stdio.h>
#include <sys/acl.h>

// typedef struct s_obj_info {

// } t_obj_info;

int mx_count_longest_with_atr(char **overall_arr);
int mx_count_col_with_atr(char **overall_arr);
void mx_output_with_atr(char **overall_arr);
void mx_get_obj_info(char *obj_name);

#endif
