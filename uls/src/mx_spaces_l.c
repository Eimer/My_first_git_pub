#include "../inc/uls.h"

int mx_count_numbers(int number) {
    int res = 0;
    if (number == 0)
        return 1;
    while (number != 0) {
        number = number / 10;
        res++;
    }
    return res;
}

int mx_longest_numbers_links(char *obj, t_add_in_func *audit) {
    DIR *dir;
    struct dirent *entry;
    int longest = 0;
    struct stat buf;
    char *buff = NULL;

    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            if (audit->flags[1] == 1) {
                buff = mx_strjoin(obj, entry->d_name);
                lstat(buff, &buf);
                free(buff);
                if (mx_count_numbers(buf.st_nlink) > longest)
                    longest = mx_count_numbers(buf.st_nlink);
            }
            else if (audit->flags[2] == 1) {
                if (mx_strcmp(entry->d_name, ".") != 0
                    && mx_strcmp(entry->d_name, "..") != 0)
                    longest = mx_longest_space (buff, entry, obj, longest);
            }
            else
                if (entry->d_name[0] != '.')
                    longest = mx_longest_space (buff, entry, obj, longest);
        }
        closedir(dir);
    }
    return longest;
}

int mx_longest_numbers_pwuid(char *obj, t_add_in_func *audit) {
    DIR *dir;
    struct dirent *entry;
    int longest = 0;

    audit->buff = NULL;
    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            longest = mx_numbers_pwuid (obj, entry, longest, audit);
        }
        closedir(dir);
    }
    return longest;
}

int mx_longest_numbers_pwgid(char *obj, t_add_in_func *audit) {
    DIR *dir;
    struct dirent *entry;
    int longest = 0;
    struct stat buf;
    struct group *groups;

    audit->buff = NULL;
    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            groups = getgrgid(buf.st_gid);
            if (audit->flags[1] != 1) {
                longest = mx_numbers_pwgid (obj, entry, longest, audit);
            }
            else {
                longest = mx_numbers_pwgid_without_a (obj, entry, longest, audit);           
            }
        }
        closedir(dir);
    }
    return longest;
}

int mx_longest_numbers_st_size(char *obj, t_add_in_func *audit) {
    DIR *dir;
    struct dirent *entry;
    int longest = 0;
    struct stat buf;
    char *buff = NULL;

    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            if (audit->flags[1] != 1) {
                if (entry->d_name[0] != '.') {
                    buff = mx_strjoin(obj, entry->d_name);
                    lstat(buff, &buf);
                    free(buff); 
                    if (mx_count_numbers(buf.st_size) > longest)
                        longest = mx_count_numbers(buf.st_size);
                }
            }
            else {
                buff = mx_strjoin(obj, entry->d_name);
                lstat(buff, &buf);
                if (mx_count_numbers(buf.st_size) > longest)
                    longest = mx_count_numbers(buf.st_size);                  
            }
        }
        closedir(dir);
    }
    return longest;
}
