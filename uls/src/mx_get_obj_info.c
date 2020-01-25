#include "../inc/uls.h"

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
    lstat(obj, &buf);
    char *res_time = ctime(&buf.st_ctime);
    for (int i = 4 ; i < mx_strlen(res_time) - 9; i++)
        printf("%c", res_time[i]);
}

void mx_get_obj_info(char *obj_name) {
    struct stat obj_stat;
    // DIR *dir;
    // struct dirent *entry;
    //char **arr_dirs = mx_arr_dirs(argc, argv);
    if (mx_dirorfile(obj_name) == 1) {
        lstat(obj_name,&obj_stat);
        printf( (S_ISLNK(obj_stat.st_mode)) ? "l" : "-");
        printf( (obj_stat.st_mode & S_IRUSR) ? "r" : "-");
        printf( (obj_stat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (obj_stat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (obj_stat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (obj_stat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (obj_stat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (obj_stat.st_mode & S_IROTH) ? "r" : "-");
        printf( (obj_stat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (obj_stat.st_mode & S_IXOTH) ? "x" : "-");
        printf("%s", "  ");
        printf( "%d", obj_stat.st_nlink);
        printf("%s", " ");
    }
    else if (mx_dirorfile(obj_name) == 0) {
        lstat(obj_name,&obj_stat);
        printf( (obj_stat.st_mode & S_IRUSR) ? "r" : "-");
        printf( (obj_stat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (obj_stat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (obj_stat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (obj_stat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (obj_stat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (obj_stat.st_mode & S_IROTH) ? "r" : "-");
        printf( (obj_stat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (obj_stat.st_mode & S_IXOTH) ? "x" : "-");
        printf("%s", "  ");
        printf( "%d", obj_stat.st_nlink);
        printf("%s", " ");
    }
    else {
        lstat(obj_name,&obj_stat);
        printf( (S_ISBLK(obj_stat.st_mode)) ? "b" : "-");
        printf( (obj_stat.st_mode & S_IRUSR) ? "r" : "-");
        printf( (obj_stat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (obj_stat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (obj_stat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (obj_stat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (obj_stat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (obj_stat.st_mode & S_IROTH) ? "r" : "-");
        printf( (obj_stat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (obj_stat.st_mode & S_IXOTH) ? "x" : "-");
        printf("%s", "  ");
        printf( "%d", obj_stat.st_nlink);
        printf("%s", " ");
    }
    get_obj_pwuid(obj_name);
    printf("%s", "  ");
    get_obj_pwgid(obj_name);
    printf("%s", "  ");
    printf( "%lld", obj_stat.st_size);
    printf("%s", " ");
    get_obj_time(obj_name);
    printf("%s", " ");
    printf("%s", obj_name);
    printf("%c", '\n');
    // dir = opendir(obj_name);
    // while ((entry = readdir(dir)) != NULL) {
    //     if(entry->d_name[0]!= '.')
    //         count++;
    // }
}
