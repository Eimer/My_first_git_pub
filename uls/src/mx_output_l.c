#include "../inc/uls.h"
// static int count_numbers(int number) {
//     int res = 0;
//     while (number != 0) {
//         number = number / 10;
//         res++;
//     }
//     return res;
// }

// static int longest_numbers_links(char *obj){
//     DIR *dir;
//     struct dirent *entry;
//     int longest = 0;
//     struct stat buf;
//     int buffer = 0;

//     if (mx_dirorfile(obj) == 0) {
//         dir = opendir(obj);
//         while ((entry = readdir(dir)) != NULL) {
//             lstat(entry->d_name, &buf);
//             buffer = count_numbers(buf.st_nlink);
//             if(buffer > longest)
//                 longest = buffer;
//         }
//         closedir(dir);
//     }
//     return longest;
// }

static int count_el_before_sorted(char *obj) {
    int res = 0;
    DIR *dir = NULL;
    struct dirent *entry;

    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL)
            res++;
    closedir(dir);
    }
    return res;
}

void mx_output_l(char *obj) {
    DIR *dir = NULL;
    struct dirent *entry;
    char **sorted_arr_l = NULL;
    int count = count_el_before_sorted(obj);
    char *tmp = NULL;

    if (count != 0) {
        sorted_arr_l = (char**)malloc(sizeof(char*) * count + 1);
        sorted_arr_l[count] = NULL;
    }
    if (mx_dirorfile(obj) == 0) {
        count = 0;
        tmp = mx_strjoin(obj, "/");
        dir = opendir(tmp);
        while ((entry = readdir(dir)) != NULL) {
                sorted_arr_l[count] = mx_strnew(mx_strlen(tmp) + mx_strlen(entry->d_name));
                sorted_arr_l[count] = mx_strjoin(tmp, entry->d_name);
                count++;
        }

        sorted_arr_l = mx_sort_overallarr(sorted_arr_l);
        count = 0;
        while (sorted_arr_l[count]) {
            mx_get_obj_info(sorted_arr_l[count], obj);
            count++;
        }
    }
    else {
        mx_get_obj_info(obj, obj);
    }
    if (mx_dirorfile(obj) == 0) {
        count = 0;
        while (sorted_arr_l[count]) {
            free(sorted_arr_l[count]);
            count++;
        }
        free(sorted_arr_l);
        free(tmp);
        closedir(dir);
    }
}
