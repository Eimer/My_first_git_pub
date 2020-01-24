#include "../inc/uls.h"

// static bool is_empty_dir

void mx_get_obj_info(int argc, char *argv[]) {
    struct stat obj_stat;
    // DIR *dir;
    // struct dirent *entry;
    int count = 0;
    //char **arr_dirs = mx_arr_dirs(argc, argv);
    char **arr_files = mx_arr_files(argc, (const char **)argv);
    
    while (arr_files[count]) {
        stat(arr_files[count],&obj_stat);
        printf("%llu", obj_stat.st_ino);
        count++;
        printf("%c", '\n');
    }
    // dir = opendir(obj_name);
    // while ((entry = readdir(dir)) != NULL) {
    //     if(entry->d_name[0]!= '.')
    //         count++;
    // }

}
