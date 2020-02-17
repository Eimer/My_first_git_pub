#include "../inc/uls.h"

void mx_fill_struct_spaces(t_spaces_l *spaces, char *obj, t_add_in_func *audit) {
    if (audit) {
        spaces->first_col = mx_longest_numbers_links(obj, audit);
        spaces->second_col = mx_longest_numbers_pwuid(obj, audit);
        spaces->third_col = mx_longest_numbers_pwgid(obj, audit);
        spaces->fourth_col = mx_longest_numbers_st_size(obj, audit);
    }
}

static int count_el_before_sorted(char *obj, t_add_in_func *audit) {
    int res = 0;
    DIR *dir = NULL;
    struct dirent *entry;

    if (mx_dirorfile(obj) == 0) {
        dir = opendir(obj);
        while ((entry = readdir(dir)) != NULL)
            if (audit->flags[1] == 1) {
                res++;
            }
            else if (audit->flags[2] == 1){
                if (mx_strcmp(entry->d_name, ".") != 0 && mx_strcmp(entry->d_name, "..") != 0)
                    res++;
            }
            else if (entry->d_name[0] != '.'){
                res++;
            }
    closedir(dir);
    }
    return res;
}

void free_mem_l(t_buffer_struct_l buf_struct, t_spaces_l *spaces) {
    if (buf_struct.sorted_arr_l) {
        spaces->count = 0;
        while (buf_struct.sorted_arr_l[spaces->count]) {
            free(buf_struct.sorted_arr_l[spaces->count]);
            spaces->count++;
        }
        free(buf_struct.sorted_arr_l);
    }
}

static void print_with_flags (char *obj, t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit) {
    while (buf_struct.sorted_arr_l[spaces->count]) {
        if (audit->flags[1] == 1) {
            mx_get_obj_info(buf_struct.sorted_arr_l[spaces->count], obj, spaces);
        }
        else if (audit->flags[2] == 1) {
            if ((mx_strcmp(&buf_struct.sorted_arr_l[spaces->count][mx_strlen(buf_struct.tmp)], "..") != 0
                && mx_strcmp(&buf_struct.sorted_arr_l[spaces->count][mx_strlen(buf_struct.tmp)], ".") != 0))
                    mx_get_obj_info(buf_struct.sorted_arr_l[spaces->count], obj, spaces);
        }
        else if (buf_struct.sorted_arr_l[spaces->count][mx_strlen(buf_struct.tmp)] != '.')
            mx_get_obj_info(buf_struct.sorted_arr_l[spaces->count], obj, spaces);
        spaces->count++;
    }
}

void mx_output_l(char *obj,t_add_in_func *audit) {
    t_buffer_struct_l buf_struct;

    t_spaces_l *spaces = (t_spaces_l*)malloc(sizeof(t_spaces_l));
    spaces->total = 0;
    spaces->count = count_el_before_sorted(obj, audit);
    if (spaces->count != 0) {
        buf_struct.sorted_arr_l = (char**)malloc(sizeof(char*) * spaces->count + 1);
        buf_struct.sorted_arr_l[spaces->count] = NULL;
    }
    if (audit->flags[9] == 1)
        mx_d_flag_with_l (obj, spaces, buf_struct);
    else {
        if (mx_dirorfile(obj) == 0) {
            if (spaces->count != 0) {
                spaces->count = 0;
                buf_struct.tmp = mx_strjoin(obj, "/");
                buf_struct.dir = opendir(buf_struct.tmp);
                mx_fill_struct_spaces(spaces, buf_struct.tmp, audit);
                mx_main_loop_l (buf_struct, spaces, audit);
                mx_print_total (buf_struct, spaces, audit);
                print_with_flags (obj, buf_struct, spaces, audit);
                free(buf_struct.tmp);
                closedir(buf_struct.dir);
        }
    }
    else {
        mx_fill_struct_spaces(spaces, obj,audit);
        mx_get_obj_info(obj, obj, spaces);
    }
    if (mx_dirorfile(obj) == 0)
        if (spaces->count != 0) 
        free_mem_l(buf_struct, spaces);
    }
    free(spaces);
}
