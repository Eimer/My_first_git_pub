#include "../inc/uls.h"

static void print_acl(struct stat obj_stat, char *obj_name, t_spaces_l *spaces) {
    struct stat buf;
    lstat(obj_name, &buf);
    mx_printstr( (obj_stat.st_mode & S_IRUSR) ? "r" : "-");
    mx_printstr( (obj_stat.st_mode & S_IWUSR) ? "w" : "-");
    mx_printstr( (obj_stat.st_mode & S_IXUSR) ? "x" : "-");
    mx_printstr( (obj_stat.st_mode & S_IRGRP) ? "r" : "-");
    mx_printstr( (obj_stat.st_mode & S_IWGRP) ? "w" : "-");
    mx_printstr( (obj_stat.st_mode & S_IXGRP) ? "x" : "-");
    mx_printstr( (obj_stat.st_mode & S_IROTH) ? "r" : "-");
    mx_printstr( (obj_stat.st_mode & S_IWOTH) ? "w" : "-");
    if (obj_stat.st_mode & S_ISVTX)
        mx_printchar('t');
    else if (obj_stat.st_mode & S_IXOTH){
        mx_printchar('x');
    }
    else
        mx_printchar('-');
    mx_get_xatr(obj_name);
    mx_printchar(' ');
    for (int i = 0; i < spaces->first_col - mx_count_numbers(buf.st_nlink); i++)
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
        for (int i = 0; i < spaces->third_col- mx_count_numbers(buf.st_gid); i++)
            mx_printchar(' ');
    }   
    else {
    mx_printstr(groups->gr_name);
        for (int i = 0; i < spaces->third_col- mx_strlen(groups->gr_name); i++)
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

static void get_obj_time(char *obj) {
    struct stat buf;
    time_t current_time;
    lstat(obj, &buf);
    char *res_time = ctime(&buf.st_mtime);

    if ((time(&current_time)) - buf.st_mtime > 15768000) {
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
    struct stat obj_stat;
    char *linked_file = mx_strnew(500);
    

    if (mx_dirorfile(obj_name) == 1) {
        lstat(obj_name,&obj_stat);
        if ((S_ISLNK(obj_stat.st_mode)))
            mx_printchar('l');
        else if (S_ISBLK(obj_stat.st_mode))
            mx_printchar('b');
        else if (S_ISCHR(obj_stat.st_mode))
            mx_printchar('c');
        else
            mx_printchar('-');
        print_acl(obj_stat, obj_name, spaces);
        
    }
    else if (mx_dirorfile(obj_name) == 0) {
        lstat(obj_name, &obj_stat);
        if ((S_ISLNK(obj_stat.st_mode)))
            mx_printchar('l');
        else
            mx_printstr( (S_ISDIR(obj_stat.st_mode)) ? "d" : "-");
        print_acl(obj_stat, obj_name, spaces);
    }
    else {
        lstat(obj_name, &obj_stat);
        if (S_ISBLK(obj_stat.st_mode))
            mx_printchar('b');
        else if (S_ISCHR(obj_stat.st_mode))
            mx_printchar('c');
        else
            mx_printchar('-');
        print_acl(obj_stat, obj_name, spaces);
    }
    get_obj_pwuid(obj_name, spaces);
    mx_printchar(' ');
    mx_printchar(' ');
    get_obj_pwgid(obj_name, spaces);
    mx_printchar(' ');
    if (S_ISBLK(obj_stat.st_mode) || S_ISCHR(obj_stat.st_mode)) {
        for (int i = 0; i < 4 -mx_count_numbers(major(obj_stat.st_rdev)); i++)
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
    get_obj_time(obj_name);
    mx_printchar(' ');
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
    free(linked_file);
}
