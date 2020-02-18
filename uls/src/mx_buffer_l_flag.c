#include "../inc/uls.h"

void mx_main_loop_l (t_buffer_struct_l buf_struct,
                        t_spaces_l *spaces, t_add_in_func *audit) {
    spaces->total = 0;
    while ((buf_struct.entry = readdir(buf_struct.dir)) != NULL) {
        if (audit->flags[1] == 1) {
                mx_buff_lstat (buf_struct, spaces);
                spaces->count++;
        }
        else if (audit->flags[2] == 1) {
            if (mx_strcmp(buf_struct.entry->d_name, ".") != 0
                && mx_strcmp(buf_struct.entry->d_name, "..") != 0) {
                    mx_buff_lstat (buf_struct, spaces);
                    spaces->count++;
                }
        }
        else 
            if(buf_struct.entry->d_name[0] != '.') {
                mx_buff_lstat (buf_struct, spaces);
                spaces->count++;
        }
    }
}

void mx_print_total (t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit) {
    buf_struct.sorted_arr_l = mx_sort(buf_struct.sorted_arr_l, audit);
    spaces->count = 0;
    mx_printstr("total ");
    mx_printint(spaces->total);
    mx_printchar('\n');
}

void mx_d_flag_with_l (char *obj, t_spaces_l *spaces, t_buffer_struct_l buf_struct) {
    spaces->count = 0;
    buf_struct.tmp = mx_strjoin(obj, "/");
    mx_fill_struct_spaces(spaces, buf_struct.tmp, NULL);
    free(buf_struct.tmp);
    mx_get_obj_info(obj, obj, spaces);
}

void mx_buff_func_in_loop (char *obj, t_buffer_struct_l buf_struct, 
                            t_spaces_l *spaces, t_add_in_func *audit) {
    if (spaces->count != 0) {
        spaces->count = 0;
        buf_struct.tmp = mx_strjoin(obj, "/");
        buf_struct.dir = opendir(buf_struct.tmp);
        mx_fill_struct_spaces(spaces, buf_struct.tmp, audit);
        mx_main_loop_l ( buf_struct, spaces, audit);
        mx_print_total (buf_struct, spaces, audit);
        mx_print_with_flags (obj, buf_struct, spaces, audit);
        free(buf_struct.tmp);
        closedir(buf_struct.dir);
    }
}

int mx_longest_space (struct dirent *entry, char *obj, int longest) {
    struct stat buf;
    char *buff = NULL;
    buff = mx_strjoin(obj, entry->d_name);
    free(buff);
    lstat(buff, &buf);
    if(mx_count_numbers(buf.st_nlink) > longest)
        longest = mx_count_numbers(buf.st_nlink);
    return longest;
}
