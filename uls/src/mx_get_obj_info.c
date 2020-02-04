#include "../inc/uls.h"

static void print_acl(struct stat obj_stat, char *obj_name, t_spaces_l *spaces) {
    struct stat buf;
    lstat(obj_name, &buf);
    printf( (obj_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (obj_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (obj_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (obj_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (obj_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (obj_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (obj_stat.st_mode & S_IROTH) ? "r" : "-");
    printf( (obj_stat.st_mode & S_IWOTH) ? "w" : "-");
    if (obj_stat.st_mode & S_ISVTX)
        printf("%c", 't');
    else if (obj_stat.st_mode & S_IXOTH){
        printf("%c", 'x');
    }
    else
        printf("%c", '-');
    mx_get_xatr(obj_name);
    printf("%s", " ");
    for (int i = 0; i < spaces->first_col - mx_count_numbers(buf.st_nlink); i++)
        printf("%s", " ");
    printf( "%d", obj_stat.st_nlink);
    printf("%s", " ");
    
}

static void get_obj_pwgid(char *obj, t_spaces_l *spaces) {
    struct stat buf;
    lstat(obj, &buf);
    struct group *groups = getgrgid(buf.st_gid);
    if (!groups) {
        printf("%d", buf.st_gid);
        for (int i = 0; i < spaces->third_col- mx_count_numbers(buf.st_gid); i++)
            printf("%s", " ");
    }   
    else {
    printf("%s", groups->gr_name);
        for (int i = 0; i < spaces->third_col- mx_strlen(groups->gr_name); i++)
            printf("%s", " ");
    }
}

static void get_obj_pwuid(char *obj, t_spaces_l *spaces) {
    struct stat buf;
    lstat(obj, &buf);
    struct passwd *pwuid = getpwuid(buf.st_uid);
    printf("%s", pwuid->pw_name);
    for (int i = 0; i < spaces->second_col - mx_strlen(pwuid->pw_name); i++)
        printf("%c", ' ');
}

static void get_obj_time(char *obj) {
    struct stat buf;
    time_t current_time;
    lstat(obj, &buf);
    char *res_time = ctime(&buf.st_mtime);

    if ((time(&current_time)) - buf.st_mtime > 15768000) {
        for (int i = 4; i < 11; i++)
            printf("%c", res_time[i]);
        for (int i = 19; i < mx_strlen(res_time) - 1; i++)
            printf("%c", res_time[i]);
    }
    else {
        for (int i = 4; i < mx_strlen(res_time) - 9; i++)
            printf("%c", res_time[i]);
    }
}

void mx_get_obj_info(char *obj_name, char *not_need, t_spaces_l *spaces) {
    struct stat obj_stat;
    char linked_file[500];
    int link_bytes = 0;
    
    if (mx_dirorfile(obj_name) == 1) {
        lstat(obj_name,&obj_stat);
        if ((S_ISLNK(obj_stat.st_mode)))
            printf("%s", "l");
        else if (S_ISBLK(obj_stat.st_mode))
            printf("%s", "b");
        else if (S_ISCHR(obj_stat.st_mode))
            printf("%s", "c");
        else
            printf("%s", "-");
        print_acl(obj_stat, obj_name, spaces);
    }
    else if (mx_dirorfile(obj_name) == 0) {
        lstat(obj_name, &obj_stat);
        if ((S_ISLNK(obj_stat.st_mode)))
            printf("%s", "l");
        else
            printf( (S_ISDIR(obj_stat.st_mode)) ? "d" : "-");
        print_acl(obj_stat, obj_name, spaces);
    }
    else {
        lstat(obj_name, &obj_stat);
        if (S_ISBLK(obj_stat.st_mode))
            printf("%s", "b");
        else if (S_ISCHR(obj_stat.st_mode))
            printf("%s", "c");
        else
            printf("%s", "-");
        print_acl(obj_stat, obj_name, spaces);
    }
    get_obj_pwuid(obj_name, spaces);
    printf("%s", "  ");
    get_obj_pwgid(obj_name, spaces);
    printf("%s", "  ");
    for (int i = 0; i < spaces->fourth_col - mx_count_numbers(obj_stat.st_size); i++) {
        printf("%s", " ");
    }
    printf( "%lld", obj_stat.st_size);
    printf("%s", " ");
    get_obj_time(obj_name);
    printf("%s", " ");
    if ((S_ISLNK(obj_stat.st_mode))) {
        link_bytes = readlink(obj_name, linked_file, 500);
        for (int i = mx_strlen(not_need) + 1; i < mx_strlen(obj_name); i++) {
            printf("%c", obj_name[i]);
        }
        printf("%s", " -> ");
        printf("%s", linked_file);
        not_need = NULL;
    }
    else
        if (mx_strlen(obj_name) == mx_strlen(not_need))
            printf("%s", obj_name);
        else {
            for (int i = mx_strlen(not_need) + 1; i < mx_strlen(obj_name); i++) {
            printf("%c", obj_name[i]);
        }
        }
    printf("%s", "\n");
}
