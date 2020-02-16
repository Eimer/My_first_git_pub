#include "../inc/uls.h"

void mx_print_acl(struct stat obj_stat, char *obj_name, t_spaces_l *spaces) {
    struct stat buf;

    lstat(obj_name, &buf);
    mx_print_atr_l(obj_stat, obj_name);
    if (obj_stat.st_mode & MX_S_ISVTX)
        mx_printchar('t');
    else if (obj_stat.st_mode & MX_S_IXOTH)
        mx_printchar('x');
    else
        mx_printchar('-');
    mx_get_xatr(obj_name);
    mx_printchar(' ');
    for (int i = 0; i < spaces->first_col - mx_count_numbers(buf.st_nlink);
            i++)
        mx_printchar(' ');
    mx_printint(obj_stat.st_nlink);
    mx_printchar(' ');
}

static void get_obj_pwgid(char *obj, t_spaces_l *spaces) {
    struct stat buf;
    lstat(obj, &buf);
    struct group *groups = getgrgid(buf.st_gid);
    if (!groups) {
        mx_printint(buf.st_gid);
        for (int i = 0; i < spaces->third_col - mx_count_numbers(buf.st_gid);
            i++)
            mx_printchar(' ');
    }   
    else {
    mx_printstr(groups->gr_name);
        for (int i = 0; i < spaces->third_col - mx_strlen(groups->gr_name);
            i++)
            mx_printchar(' ');
    }
}

static void get_obj_pwuid(char *obj, t_spaces_l *spaces) {
    struct stat buf;
    lstat(obj, &buf);

    struct passwd *pwuid = getpwuid(buf.st_uid);
    mx_printstr(pwuid->pw_name);
    for (int i = 0; i < spaces->second_col - mx_strlen(pwuid->pw_name); i++)
        mx_printchar(' ');
}

void mx_get_obj_time(char *obj) {
    struct stat buf;
    time_t current_time;
    lstat(obj, &buf);
    char *res_time = ctime(&buf.st_mtime);

    if ((time(&current_time)) - buf.st_mtime > 15000000) {
        for (int i = 4; i < 11; i++)
            mx_printchar(res_time[i]);
        for (int i = 19; i < mx_strlen(res_time) - 1; i++)
            mx_printchar(res_time[i]);
    }
    else {
        for (int i = 4; i < mx_strlen(res_time) - 9; i++)
            mx_printchar(res_time[i]);
    }
}

void mx_get_obj_info(char *obj_name, char *not_need, t_spaces_l *spaces) {
    char *linked_file = mx_strnew(500);

    if (mx_dirorfile(obj_name) == 1)
        mx_first_atr_if_dir(obj_name, spaces);
    else if (mx_dirorfile(obj_name) == 0)
        mx_first_atr_if_file(obj_name, spaces);
    else
        mx_first_atr_if_undef(obj_name, spaces);
    get_obj_pwuid(obj_name, spaces);
    mx_printchar(' ');
    mx_printchar(' ');
    get_obj_pwgid(obj_name, spaces);
    mx_printchar(' ');
    mx_print_maj_min(obj_name, spaces);
    mx_print_link(obj_name, linked_file, not_need);
    free(linked_file);
}
