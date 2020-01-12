#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include "../libmx/inc/libmx.h"
#include "stdio.h"

typedef struct s_island {
    char *name;
    int distalnce;
    bool visited;
} t_island;

typedef struct s_arrays {
    char **arr_from;
    char **arr_to;
    char **arr_dist;
    int **arr_path;
    char **no_repeat;
    int **count_path;
    int **shortest_path;
    int ***all_path_dist;
    char ***all_path;
} t_arrays;

char *mx_strjoin(const char *s1, const char *s2);
int mx_strlen(const char *s);
void mx_true_argumensts(int argc);
void mx_errors(int argc, char *argv[]);
void mx_printerr(const char *s);
void mx_true_content(char **argv);
void mx_is_empty(char *str);
void mx_openfile(char **argv);
void mx_nofile(char *str);
void mx_first_line(char **argv);
char *mx_file_to_str(const char *file);
bool mx_isdigit(char *str);
void mx_print_first_line();
char *mx_strnew(const int size);
bool mx_isdigit(char *str);
char **mx_strsplit(const char *s, char c);
int mx_invalid_line(char *argv[]);
int mx_count_words(const char *str, char c);
void mx_print_invalid_line(char *argv[], char *str);
char *mx_itoa(int number);
int mx_get_min(int a, int b);
bool mx_islands_no_repeat(char *argv[]);
int mx_strcmp(const char *s1, const char *s2);
char **mx_arr_from(char *str_from_file);
char **mx_arr_to(char *str_from_file);
char *mx_strcpy(char *dst, const char *src);
char **mx_arr_dist(char *str_from_file);
t_arrays *mx_fill_s_arr(char *str_from_file, char *argv[]);
int **mx_arr_path(char *argv[]);
char **mx_get_no_repeat(char *argv[]);
int mx_atoi(char *str);
t_arrays *mx_path_dist(t_arrays *main_arr);
void mx_all_path(t_arrays *main_arr);

#endif
