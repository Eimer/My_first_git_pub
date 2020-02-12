#include "../inc/uls.h"

static void fill_struct_spaces(t_spaces_l *spaces, char *obj) {
    spaces->first_col = mx_longest_numbers_links(obj);
    spaces->second_col = mx_longest_numbers_pwuid(obj);
    spaces->third_col = mx_longest_numbers_pwgid(obj);
    spaces->fourth_col = mx_longest_numbers_st_size(obj);
}

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

static void free_mem_l(t_buffer_struct_l buf_struct, t_spaces_l *spaces) {
    if (buf_struct.sorted_arr_l) {
        spaces->count = 0;
        while (buf_struct.sorted_arr_l[spaces->count]) {
            free(buf_struct.sorted_arr_l[spaces->count]);
            spaces->count++;
        }
        free(buf_struct.sorted_arr_l);
        free(buf_struct.tmp);
        closedir(buf_struct.dir);
    }
    free(spaces);
}

static void print_with_flags (char *obj, t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit) {
    while (buf_struct.sorted_arr_l[spaces->count]) {
        if (audit->flags[1] == 1)
            mx_get_obj_info(buf_struct.sorted_arr_l[spaces->count], obj, spaces);
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
    spaces->count = count_el_before_sorted(obj);
    if (spaces->count != 0) {
        buf_struct.sorted_arr_l = (char**)malloc(sizeof(char*) * spaces->count + 1);
        buf_struct.sorted_arr_l[spaces->count] = NULL;
    }
    if (mx_dirorfile(obj) == 0) {
        spaces->count = 0;
        buf_struct.tmp = mx_strjoin(obj, "/");
        buf_struct.dir = opendir(buf_struct.tmp);
        fill_struct_spaces(spaces, buf_struct.tmp);
        mx_main_loop_l (buf_struct, spaces);
        mx_print_total (buf_struct, spaces, audit);
        print_with_flags (obj, buf_struct, spaces, audit);
    }
    else {
            fill_struct_spaces(spaces, obj);
            mx_get_obj_info(obj, obj, spaces);
         }
    free_mem_l(buf_struct, spaces);
}
