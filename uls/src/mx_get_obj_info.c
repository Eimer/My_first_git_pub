#include "../inc/uls.h"

static void print_acl(struct stat obj_stat, char *obj_name) {
    printf( (obj_stat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (obj_stat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (obj_stat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (obj_stat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (obj_stat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (obj_stat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (obj_stat.st_mode & S_IROTH) ? "r" : "-");
    printf( (obj_stat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (obj_stat.st_mode & S_IXOTH) ? "x" : "-");
    mx_get_xatr(obj_name);
    printf("%s", "  ");
    printf( "%d", obj_stat.st_nlink);
    printf("%s", " ");
}

static void get_obj_pwgid(char *obj) {
    struct stat buf;
    lstat(obj, &buf);
    struct group *groups = getgrgid(buf.st_gid);
    if (!groups)
        printf ("%d",buf.st_gid);
    else
        printf("%s", groups->gr_name);
}

static void get_obj_pwuid(char *obj) {
    struct stat buf;
    lstat(obj, &buf);
    struct passwd *pwuid = getpwuid(buf.st_uid);
    printf("%s", pwuid->pw_name);
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

void mx_get_obj_info(char *obj_name) {
    struct stat obj_stat;
    char linked_file[500];
    int link_bytes = 0;
    if (mx_dirorfile(obj_name) == 1) {
        printf( (S_ISLNK(obj_stat.st_mode)) ? "l" : "-");
        lstat(obj_name,&obj_stat);
        print_acl(obj_stat, obj_name);
    }
    else if (mx_dirorfile(obj_name) == 0) {
        lstat(obj_name,&obj_stat);
        printf( (S_ISDIR(obj_stat.st_mode)) ? "d" : "-");
        print_acl(obj_stat, obj_name);
    }
    else {
        lstat(obj_name,&obj_stat);
        printf( (S_ISBLK(obj_stat.st_mode)) ? "b" : "-");
        print_acl(obj_stat, obj_name);
    }
    get_obj_pwuid(obj_name);
    printf("%s", "  ");
    get_obj_pwgid(obj_name);
    printf("%s", "  ");
    printf( "%lld", obj_stat.st_size);
    printf("%s", " ");
    get_obj_time(obj_name);
    printf("%s", " ");
    if ((S_ISLNK(obj_stat.st_mode))) {
        link_bytes = readlink("link_to_main", linked_file, 500);
        printf("%s", obj_name);
        printf("%s", " -> ");
        printf("%s", linked_file);
    }
    else
        printf("%s", obj_name);
    printf("%c", '\n');
}
