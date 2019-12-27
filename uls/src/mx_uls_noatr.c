#include "../inc/uls.h"

static int count_obj() {
    int res = 0;
<<<<<<< HEAD
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
=======

    if (arr_dirs) {
        while (arr_dirs[res]){
            res++;
        }
    }
    return res;
}

static int count_files(char **arr_files) {
    int res = 0;

    if (arr_files) {
        while (arr_files[res]){
>>>>>>> master
            res++;
        }
    }
    closedir(dir);
    return res;
}

<<<<<<< HEAD
char **mx_uls_noatr(int argc, char const *argv[]) {
    DIR *dir;
    struct dirent *entry;
    int count_el = 0;
    char **overall_arr = (char**)malloc(sizeof(char *) * (count_obj() + 1));
    
    overall_arr[count_obj()] = NULL;
    dir = opendir(".");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            overall_arr[count_el] = mx_strnew(mx_strlen(entry->d_name));
            overall_arr[count_el] = mx_strcpy(overall_arr[count_el], entry->d_name);
            count_el++;
        }
    }
    closedir(dir);
    mx_output(argc, argv, overall_arr);
=======
static char **memory_for_general_arr(char **arr_files, char **arr_dirs) {
    int files_number = count_files(arr_files);
    int dirs_number = count_dirs(arr_dirs);
    char **general_arr = (char **)malloc(sizeof(char *) * (files_number + dirs_number + 1));

    general_arr[files_number + dirs_number] = NULL;
    return general_arr;

}

static char **filling_overall_arr(char **arr_files, char **arr_dirs) {
    int files_number = count_files(arr_files);
    int dirs_number = count_dirs(arr_dirs);
    char **overall_arr = memory_for_general_arr(arr_files, arr_dirs);
    int count = 0;

    for (int i = 0; i < files_number; i++) {
        overall_arr[count] = mx_strnew(mx_strlen(arr_files[i]));
        mx_strcpy(overall_arr[count], arr_files[i]);
        count++;
    }
    for (int j = 0; j < dirs_number; j++) {
        overall_arr[count] = mx_strnew(mx_strlen(arr_dirs[j]));
        mx_strcpy(overall_arr[count], arr_dirs[j]);
        count++;
    }
    return overall_arr;
}

char **mx_uls_noatr(int argc, char const *argv[]) {
    char **arr_files = mx_arr_files(argc, argv);
    char **arr_dirs = mx_arr_dirs(argc,argv);
    char **overall_arr = filling_overall_arr(arr_files, arr_dirs);

>>>>>>> master
    return overall_arr;
}
