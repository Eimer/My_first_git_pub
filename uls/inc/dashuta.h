#ifndef DASHUTA_H
#define DASHUTA_H
#include <stdio.h>

// Struct
typedef struct s_add_in_func {
    int main_return;
    int check;
    int check_n;
    int argc;
    int *flags;
    char error;
    char *buff;
} t_add_in_func;

// Return int
int mx_count_obj_d(const char *str);
int mx_count_obj_dash(const char *str);
int mx_searchstr(const char *haystack, const char *needle);
int mx_check_denied(char *arr_dirs_u, t_add_in_func *audit);

// Return nothing
void mx_printcharerr(char s);
void mx_flag_r(int argc, char **argv);
void mx_print_n(char **arr, int *flags);
void mx_write_flags(char flag, t_add_in_func *audit);
void mx_open_dir(char **arr_dirs, t_add_in_func *audit);
void mx_quick(char **overall_arr, int count, t_add_in_func *audit);
void mx_enter_fileordir(int argc, char **argv, t_add_in_func *audit);
void mx_print_result(char **arr, t_add_in_func *audit, char *check_a);
void mx_d_flag(char **arr_files, char **arr_dirs, t_add_in_func *audit);

// Return str or char
char *mx_chr(char *s, char c, int n);
char **mx_arr_dirs_2(int argc, char **argv);
char **mx_sort(char **overall_arr, t_add_in_func *audit);
char **mx_arr_dirs_1(int argc, char **argv, t_add_in_func *audit,
                     char **arr_files);

#endif
