#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>

int mx_strlen(const char *s);
void mx_printerr(const char *s);
char *mx_file_to_str(const char *file);
bool mx_isdigit(char *str);
int mx_mystrcmp(const char *s1, const char *s2);
char *mx_itoa(int number);
int mx_count_islands(char *str);
char *mx_strnew(const int size);
void mx_nofile(char *str);
char *mx_strjoin(const char *s1, const char *s2);
void mx_is_empty(char *str);
char **mx_strsplit(const char *s, char c);
int mx_invalid_line(char* str);
int mx_count_words(const char *str, char c);
int mx_no_repeat(char **splitet_islands);
void mx_print_invalid_line(char *str);
char ** mx_filling_islands(char **splited_islands, char**buff);
char *mx_strcpy(char *dst, const char *src);
int mx_strcmp(const char *s1, const char *s2);
bool mx_is_number(char *str);
void mx_true_argumensts(int argv);
void mx_true_content(char **argc);
void mx_openfile(char **argc);
char *mx_fill_first_line(char *first_line, char *str_from_file);

#endif
