#ifndef DASHUTA_H
#define DASHUTA_H
#include <stdio.h>


typedef struct s_add_in_func {
    int count;
    int numb;
} t_add_in_func;

void mx_enter_fileordir(int argc, char **argv, int i);
void mx_flag_r(int argc, char **argv);
int check_denied(char *arr_dirs_u, char **arr_dirs, int u, char **argv);
int mx_count_obj_dash(const char *str);
char **mx_arr_dirs_1(int argc, char **argv);
#endif
