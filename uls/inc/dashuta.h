#ifndef DASHUTA_H
#define DASHUTA_H
#include <stdio.h>


typedef struct s_add_in_func {
    // int count;
    // int numb;
    int argc;
    int *flags;
} t_add_in_func;

int mx_count_obj_d(const char *str);
void mx_print_result(char **arr, t_add_in_func *audit, char *check_a);
void mx_flag_aR(int argc, char **argv, t_add_in_func *audit);
void mx_enter_fileordir(int argc, char **argv, t_add_in_func *audit);
void mx_flag_r(int argc, char **argv);
int check_denied(char *arr_dirs_u, char **arr_dirs, int u);
int mx_count_obj_dash(const char *str);
char **mx_arr_dirs_2(int argc, char **argv);
char **mx_arr_dirs_1(int argc, char **argv);
int mx_searchstr(const char *haystack, const char *needle);
#endif
