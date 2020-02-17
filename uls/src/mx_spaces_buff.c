#include "../inc/uls.h"

int mx_numbers_pwgid (char * obj, struct dirent *entry, int longest, t_add_in_func *audit) {
    int res = 0;
    struct stat buf;
    struct group *groups;
    res = longest;

    audit->buff = mx_strjoin(obj, entry->d_name);
    lstat(audit->buff, &buf);
    free(audit->buff);
    groups = getgrgid(buf.st_gid);
    if (entry->d_name[0] != '.') {
        if (!groups) {
            if (mx_count_numbers(buf.st_gid) > res)
                res = mx_count_numbers(buf.st_gid);
            }
        else if (mx_strlen(groups->gr_name) > res)
            res = mx_strlen(groups->gr_name);
        }
    return res;
}

int mx_numbers_pwgid_without_a (char * obj, struct dirent *entry, int longest, t_add_in_func *audit) {
    int res = 0;
    struct group *groups;
    struct stat buf;

    res = longest;
    audit->buff = mx_strjoin(obj, entry->d_name);
    lstat(audit->buff, &buf);
    free(audit->buff);
    groups = getgrgid(buf.st_gid);
    if (!groups) {
        if (mx_count_numbers(buf.st_gid) > res)
            res = mx_count_numbers(buf.st_gid);
        }
        else if (mx_strlen(groups->gr_name) > res)
            res = mx_strlen(groups->gr_name);
    return res;
}

int mx_numbers_pwuid (char * obj, struct dirent *entry, int longest, t_add_in_func *audit) {
    struct stat buf;
    int res = 0;
    struct passwd *pwuid;

    res = longest;
    audit->buff = mx_strjoin(obj, entry->d_name);
    lstat(audit->buff, &buf);
    free(audit->buff);
    pwuid = getpwuid(buf.st_uid);
    if (audit->flags[1] != 1) {
        if (entry->d_name[0] != '.')
            if(mx_strlen(pwuid->pw_name) > res)
                res = mx_strlen(pwuid->pw_name);
    }
    else
        if(mx_strlen(pwuid->pw_name) > res)
            res = mx_strlen(pwuid->pw_name);
    return res;
}

int mx_number_links (char * obj, struct dirent *entry, int longest, t_add_in_func *audit) {
    int res = 0;
    char *buff = NULL;
    struct stat buf;

    res = longest;
    if (audit->flags[1] == 1) {
        buff = mx_strjoin(obj, entry->d_name);
        lstat(buff, &buf);
        free(buff);
        if (mx_count_numbers(buf.st_nlink) > res)
            res = mx_count_numbers(buf.st_nlink);
        }
        else if (audit->flags[2] == 1) {
            if (mx_strcmp(entry->d_name, ".") != 0
                && mx_strcmp(entry->d_name, "..") != 0)
                res = mx_longest_space (buff, entry, obj, res);
            }
            else
                if (entry->d_name[0] != '.')
                    res = mx_longest_space (buff, entry, obj, res);
    return res;
}
