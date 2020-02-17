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
                    if(mx_count_numbers(buf.st_nlink) > longest)
                        longest = mx_count_numbers(buf.st_nlink);
                    free(buff);
            }
            else if (audit->flags[2] == 1){
                if (mx_strcmp(entry->d_name, ".") != 0 
                    && mx_strcmp(entry->d_name, "..") != 0) {
                    buff = mx_strjoin(obj, entry->d_name);
                    lstat(buff, &buf);
                    if(mx_count_numbers(buf.st_nlink) > longest)
                        longest = mx_count_numbers(buf.st_nlink);
                    free(buff);
                }
            }
            else {
                if (entry->d_name[0] != '.') {
                    buff = mx_strjoin(obj, entry->d_name);
                    lstat(buff, &buf);
                    if(mx_count_numbers(buf.st_nlink) > longest)
                            longest = mx_count_numbers(buf.st_nlink);
                    free(buff);
                }
            }
        }
        closedir(dir);
    }
    return longest;
}

int mx_longest_numbers_pwuid(char *obj, t_add_in_func *audit) {
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
            if (audit->flags[1] != 1) {
                if (entry->d_name[0] != '.') {
                    if(mx_strlen(pwuid->pw_name) > longest)
                        longest = mx_strlen(pwuid->pw_name);
                    free(buff);
                }
            }
            else {
                if(mx_strlen(pwuid->pw_name) > longest)
                    longest = mx_strlen(pwuid->pw_name);
                free(buff);            
            }
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
    char *buff = NULL;
    struct group *groups;

    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL) {
            buff = mx_strjoin(obj, entry->d_name);
            lstat(buff, &buf);
            groups = getgrgid(buf.st_gid);
            if (audit->flags[1] != 1) {
                if (entry->d_name[0] != '.') {
                    if (!groups) {
                        if (mx_count_numbers(buf.st_gid) > longest)
                            longest = mx_count_numbers(buf.st_gid);
                    }
                    else if (mx_strlen(groups->gr_name) > longest)
                        longest = mx_strlen(groups->gr_name);
                    free(buff);
                }
            }
            else {
                if (!groups) {
                    if (mx_count_numbers(buf.st_gid) > longest)
                        longest = mx_count_numbers(buf.st_gid);
                }
                else if (mx_strlen(groups->gr_name) > longest)
                    longest = mx_strlen(groups->gr_name);
                free(buff);            
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
                    if (mx_count_numbers(buf.st_size) > longest)
                        longest = mx_count_numbers(buf.st_size);
                    free(buff);
                }
            }
            else {
                buff = mx_strjoin(obj, entry->d_name);
                lstat(buff, &buf);
                if (mx_count_numbers(buf.st_size) > longest)
                    longest = mx_count_numbers(buf.st_size);
                free(buff);                
            }
        }
        closedir(dir);
    }
    return longest;
}
