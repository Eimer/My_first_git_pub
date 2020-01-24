#include "../inc/uls.h"

// static bool is_empty_dir

void mx_get_obj_info(int argc, char *argv[]) {
    struct stat obj_stat;
    // DIR *dir;
    // struct dirent *entry;
    int count = 0;
    //char **arr_dirs = mx_arr_dirs(argc, argv);
    char **arr_files = mx_arr_files(argc, argv);
    
    while (arr_files[count]) {
        lstat(arr_files[count],&obj_stat);
        printf( (S_ISDIR(obj_stat.st_mode)) ? "d" : "-");
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
        printf("\n\n");
        count++;
        printf("%c", '\n');
    }
    // dir = opendir(obj_name);
    // while ((entry = readdir(dir)) != NULL) {
    //     if(entry->d_name[0]!= '.')
    //         count++;
    // }

}
