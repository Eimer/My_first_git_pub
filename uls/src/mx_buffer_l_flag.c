#include "../inc/uls.h"

void mx_main_loop_l (t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit) {
    while ((buf_struct.entry = readdir(buf_struct.dir)) != NULL) {
        buf_struct.sorted_arr_l[spaces->count] = mx_strjoin(buf_struct.tmp, buf_struct.entry->d_name);
        lstat(buf_struct.sorted_arr_l[spaces->count], &buf_struct.buf);
        if (audit->flags[1] == 1 || audit->flags[2] == 1) {
                spaces->total += buf_struct.buf.st_blocks;
                spaces->count++;
        }
        else {
            if (buf_struct.entry->d_name[0] != '.') {
                spaces->total += buf_struct.buf.st_blocks;
                spaces->count++;
            }
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
    if (mx_dirorfile(obj) == 0)
        free(buf_struct.sorted_arr_l);
}
