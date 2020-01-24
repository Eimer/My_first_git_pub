#include "../inc/uls.h"

static int logestfile(int argc, char **argv) {
    int longest = 0;
    int count_files = 0;
    char **files = mx_arr_files(argc, argv);

    if (files) {
        while (files[count_files]) {
            if (mx_strlen(files[count_files]) > longest) {
                longest = mx_strlen(files[count_files]);
            }
            count_files++;
        }
    }
    return longest;
}

static int longestdir(int argc, char **argv) {
    int longest = 0;
    char **dirs = mx_arr_dirs(argc, argv);
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    if (dirs) {
        while (dirs[count] != NULL) {
            dir = opendir(dirs[count]);
            while ((entry = readdir(dir)) != NULL) {
                if (entry->d_name[0] != '.')
                    if (mx_strlen(entry->d_name) > longest)
                        longest = mx_strlen(entry->d_name);
            }
            count++;
        }
        closedir(dir);
    }
    return longest;
}

int mx_count_longest(int argc, char **argv) {
    int longest_file = logestfile(argc, argv);
    int longest_dir = longestdir(argc, argv);
    
    if (longest_file > longest_dir) {
        return longest_file;
    }
    else {
        return longest_dir; 
    }
    return 0;
}
