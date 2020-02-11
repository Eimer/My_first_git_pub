#ifndef DASHUTA_H
#define DASHUTA_H
#include <stdio.h>


typedef struct s_add_in_func {
    int main_return;
    int check;
    int check_n;
    int argc;
    int *flags;
} t_add_in_func;

char **mx_quick(char **arr, int left, int right);
void mx_d_flag(char **arr_files, char **arr_dirs, t_add_in_func *audit);
char **mx_sort(char **overall_arr, t_add_in_func *audit);
void mx_open_dir(char **arr_dirs, t_add_in_func *audit);
int mx_count_obj_d(const char *str);
void mx_print_result(char **arr, t_add_in_func *audit, char *check_a);
void mx_flag_aR(int argc, char **argv, t_add_in_func *audit);
void mx_enter_fileordir(int argc, char **argv, t_add_in_func *audit);
void mx_flag_r(int argc, char **argv);
int mx_check_denied(char *arr_dirs_u, t_add_in_func *audit);
int mx_count_obj_dash(const char *str);
char **mx_arr_dirs_2(int argc, char **argv);
char **mx_arr_dirs_1(int argc, char **argv, t_add_in_func *audit);
int mx_searchstr(const char *haystack, const char *needle);
#endif
