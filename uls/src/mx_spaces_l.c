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

int mx_longest_numbers_links(char *obj) {
    DIR *dir;
    struct dirent *entry;
    int longest = 0;
    struct stat buf;
    char *buff = NULL;

    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            buff = mx_strjoin(obj, entry->d_name);
            lstat(buff, &buf);
            if(mx_count_numbers(buf.st_nlink) > longest)
                longest = mx_count_numbers(buf.st_nlink);
            free(buff);
        }
        closedir(dir);
    }
    return longest;
}

int mx_longest_numbers_pwuid(char *obj) {
    DIR *dir;
    struct dirent *entry;
    int longest = 0;
    struct stat buf;
    char *buff = NULL;
    struct passwd *pwuid;

    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            buff = mx_strjoin(obj, entry->d_name);
            lstat(buff, &buf);
            pwuid = getpwuid(buf.st_uid);
            if(mx_strlen(pwuid->pw_name) > longest)
                longest = mx_strlen(pwuid->pw_name);
            free(buff);
        }
        closedir(dir);
    }
    return longest;
}

int mx_longest_numbers_pwgid(char *obj) {
    DIR *dir;
    struct dirent *entry;
    int longest = 0;
    struct stat buf;
    char *buff = NULL;
    struct group *groups;
    
    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            buff = mx_strjoin(obj, entry->d_name);
            lstat(buff, &buf);
            groups = getgrgid(buf.st_gid);
            if (!groups) {
                if (mx_count_numbers(buf.st_gid) > longest)
                    longest = mx_count_numbers(buf.st_gid);
            }
            else if (mx_strlen(groups->gr_name) > longest)
                longest = mx_strlen(groups->gr_name);
            free(buff);
        }
        closedir(dir);
    }
    return longest;
}

int mx_longest_numbers_st_size(char *obj) {
    DIR *dir;
    struct dirent *entry;
    int longest = 0;
    struct stat buf;
    char *buff = NULL;

    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            buff = mx_strjoin(obj, entry->d_name);
            lstat(buff, &buf);
            if (mx_count_numbers(buf.st_size) > longest)
                longest = mx_count_numbers(buf.st_size);
            free(buff);
        }
        closedir(dir);
    }
    return longest;
}
