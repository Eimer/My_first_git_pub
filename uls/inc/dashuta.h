#ifndef DASHUTA_H
#define DASHUTA_H
#include <stdio.h>


typedef struct s_add_in_func {
    int count;
    int numb;
} t_add_in_func;

void mx_print_result(char **arr, int flags, char *check_a, char **argv);
void mx_flag_aR(int argc, char **argv);
void mx_enter_fileordir(int argc, char **argv, int i);
void mx_flag_r(int argc, char **argv);
int check_denied(char *arr_dirs_u, char **arr_dirs, int u, char **argv);
int mx_count_obj_dash(const char *str);
char **mx_arr_dirs_2(int argc, char **argv);
char **mx_arr_dirs_1(int argc, char **argv);
int mx_searchstr(const char *haystack, const char *needle);
#endif
