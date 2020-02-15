#include "../inc/uls.h"

void mx_first_atr_if_dir(char *obj_name, t_spaces_l *spaces) {
    struct stat obj_stat;

    lstat(obj_name,&obj_stat);
    if ((S_ISLNK(obj_stat.st_mode)))
        mx_printchar('l');
    else if (S_ISBLK(obj_stat.st_mode))
        mx_printchar('b');
    else if (S_ISCHR(obj_stat.st_mode))
            mx_printchar('c');
    else
        mx_printchar('-');
    mx_print_acl(obj_stat, obj_name, spaces);
}

void mx_first_atr_if_file(char *obj_name, t_spaces_l *spaces) {
    struct stat obj_stat;

    lstat(obj_name, &obj_stat);
    if ((S_ISLNK(obj_stat.st_mode)))
        mx_printchar('l');
    else
        mx_printstr( (S_ISDIR(obj_stat.st_mode)) ? "d" : "-");
    mx_print_acl(obj_stat, obj_name, spaces);
}

void mx_first_atr_if_undef(char *obj_name, t_spaces_l *spaces) {
    struct stat obj_stat;

    lstat(obj_name, &obj_stat);
    if (S_ISBLK(obj_stat.st_mode))
        mx_printchar('b');
    else if (S_ISCHR(obj_stat.st_mode))
        mx_printchar('c');
    else
        mx_printchar('-');
    mx_print_acl(obj_stat, obj_name, spaces);
}

void mx_print_maj_min(char *obj_name, t_spaces_l *spaces) {
    struct stat obj_stat;

    lstat(obj_name, &obj_stat);
    if (S_ISBLK(obj_stat.st_mode) || S_ISCHR(obj_stat.st_mode)) {
        for (int i = 0; i < 4 - mx_count_numbers(major(obj_stat.st_rdev)); i++)
            mx_printchar(' ');
        mx_printint(major(obj_stat.st_rdev));
        mx_printstr(", ");
        for (int i = 0; i < 3 - mx_count_numbers(minor(obj_stat.st_rdev)); i++)
            mx_printchar(' ');
        mx_printint(minor(obj_stat.st_rdev));
    }
    else {
        for (int i = 0; i < spaces->fourth_col - mx_count_numbers(obj_stat.st_size); i++) {
            mx_printchar(' ');
        }
        mx_printchar(' ');
        mx_printint(obj_stat.st_size);
    }
    mx_printchar(' ');
    mx_get_obj_time(obj_name);
    mx_printchar(' ');
}

void mx_print_link(char *obj_name, char *linked_file, char *not_need) {
    struct stat obj_stat;

    lstat(obj_name, &obj_stat);
    if ((S_ISLNK(obj_stat.st_mode))) {
        readlink(obj_name, linked_file, 500);
        if (mx_strlen(obj_name) == mx_strlen(not_need))
            mx_printstr(obj_name);
        else 
            for (int i = mx_strlen(not_need) + 1; i < mx_strlen(obj_name); i++) {
                mx_printchar(obj_name[i]);
            }
        mx_printstr(" -> ");
        mx_printstr(linked_file);
        not_need = NULL;
    }
    else
        if (mx_strlen(obj_name) == mx_strlen(not_need))
            mx_printstr(obj_name);
        else {
            for (int i = mx_strlen(not_need) + 1; i < mx_strlen(obj_name); i++) {
            mx_printchar(obj_name[i]);
            }
        }
    mx_printchar('\n');
}
