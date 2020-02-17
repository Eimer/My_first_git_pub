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

#define MX_S_IRWXU 0000700
#define MX_S_IRUSR 0000400
#define MX_S_IWUSR 0000200
#define MX_S_IXUSR 0000100
#define MX_S_IRWXG 0000070
#define MX_S_IRGRP 0000040
#define MX_S_IWGRP 0000020
#define MX_S_IXGRP 0000010
#define MX_S_IRWXO 0000007
#define MX_S_IROTH 0000004
#define MX_S_IWOTH 0000002 
#define MX_S_IXOTH 0000001
#define MX_S_ISUID 0004000
#define MX_S_ISGID 0002000
#define MX_S_ISVTX 0001000
#define MX_S_IFMT 0170000
#define MX_S_IFIFO 0010000
#define MX_S_IFCHR 0020000
#define MX_S_IFDIR 0040000
#define MX_S_IFBLK 0060000
#define MX_S_IFREG 0100000
#define MX_S_IFLNK 0120000
#define MX_S_IFSOCK 0140000

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
int mx_longest_numbers_links(char *obj, t_add_in_func *audit);
int mx_longest_numbers_pwuid(char *obj, t_add_in_func *audit);
int mx_longest_numbers_pwgid(char *obj, t_add_in_func *audit);
int mx_longest_numbers_st_size(char *obj, t_add_in_func *audit);
int mx_mystrcmp(const char *s1, const char *s2);
void mx_main_loop_l (t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit);
void mx_print_total_l(char *obj, t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit);
void mx_print_with_flags (char *obj, t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit);
void mx_print_total (t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit);
void mx_first_atr_if_dir(char *obj_name, t_spaces_l *spaces);
void mx_print_acl(struct stat obj_stat, char *obj_name, t_spaces_l *spaces);
void mx_first_atr_if_file(char *obj_name, t_spaces_l *spaces);
void mx_first_atr_if_undef(char *obj_name, t_spaces_l *spaces);
void mx_print_maj_min(char *obj_name, t_spaces_l *spaces);
void mx_get_obj_time(char *obj);
void mx_print_link(char *obj_name, char *linked_file, char *not_need);
void mx_d_flag_with_l(char *obj, t_spaces_l *spaces, t_buffer_struct_l buf_struct);
void mx_fill_struct_spaces(t_spaces_l *spaces, char *obj, t_add_in_func *audit);
void mx_print_atr_l(struct stat obj_stat, char *obj_name);
void mx_buff_func_in_loop (char *obj, t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit);
void mx_print_with_flags (char *obj, t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit);
int mx_longest_space (struct dirent *entry, char *obj, int longest);
int mx_numbers_pwgid (char * obj, struct dirent *entry, int longest, t_add_in_func *audit);
int mx_numbers_pwgid_without_a (char * obj, struct dirent *entry, int longest, t_add_in_func *audit);
int mx_numbers_pwuid (char * obj, struct dirent *entry, int longest, t_add_in_func *audit);
int mx_number_links (char * obj, struct dirent *entry, int longest, t_add_in_func *audit);

#endif
