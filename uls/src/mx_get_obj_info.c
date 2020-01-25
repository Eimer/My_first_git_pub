#include "../inc/uls.h"

// static bool is_empty_dir

void mx_get_obj_info(char *obj_name) {
    struct stat obj_stat;
    // DIR *dir;
    // struct dirent *entry;
    //char **arr_dirs = mx_arr_dirs(argc, argv);
    if (mx_dirorfile(obj_name) == 1) {
        lstat(obj_name,&obj_stat);
        //printf( (S_ISDIR(obj_stat.st_mode)) ? "d" : "-");
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
        printf("%c", '\n');
    }
    if (mx_dirorfile(obj_name) == 0) {
        lstat(obj_name,&obj_stat);
        printf( (S_ISDIR(obj_stat.st_mode)) ? "d" : "-");
        //printf( (S_ISLNK(obj_stat.st_mode)) ? "l" : "-");
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
        printf("%c", '\n');
    }
    // dir = opendir(obj_name);
    // while ((entry = readdir(dir)) != NULL) {
    //     if(entry->d_name[0]!= '.')
    //         count++;
    // }
}
