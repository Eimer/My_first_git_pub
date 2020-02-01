#include "../inc/uls.h"

<<<<<<< HEAD
static int count_numbers(int number) {
    int res = 0;
    while (number != 0) {
        number = number / 10;
        res++;
    }
    return res;
}

static int longest_numbers_links(char *obj){
    DIR *dir;
    struct dirent *entry;
    int longest = 0;
    struct stat buf;
    int buffer = 0;

    dir = opendir(obj);
    while ((entry = readdir(dir)) != NULL) {
        lstat(entry->d_name, &buf);
        buffer = count_numbers(buf.st_nlink);
        if(buffer > longest)
            longest = buffer;
    }
    closedir(dir);
    return longest;
}
=======
// static int count_numbers(int number) {
//     int res = 0;
//     while (number != 0) {
//         number = number / 10;
//         res++;
//     }
//     printf("%d ", res);
//     return res;
// }

// static int count_spaces_first_col(char *obj) {
//     struct stat buf;
//     lstat(obj, &buf);
//     int len_amount_links = 0;
//     return len_amount_links;
// }
>>>>>>> e68011273594c96126954a8cff075241797b35a5

// static int count_spaces_first_col(char *obj) {

// }

void mx_output_l(char *obj) {
    DIR *dir;
    struct dirent *entry;
    int longest_first_col = 0;
    longest_first_col = longest_numbers_links(obj);
    exit(0);
    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            mx_get_obj_info(entry->d_name);
<<<<<<< HEAD
=======
            // count_spaces_first_col(obj);
>>>>>>> e68011273594c96126954a8cff075241797b35a5
        }
    }
    else {
        mx_get_obj_info(obj);
    }
    closedir(dir);
}
