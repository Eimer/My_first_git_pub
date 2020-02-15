#include "../inc/uls.h"

void mx_main_loop_l (t_buffer_struct_l buf_struct, t_spaces_l *spaces) {
    while ((buf_struct.entry = readdir(buf_struct.dir)) != NULL) {
        buf_struct.sorted_arr_l[spaces->count] = mx_strjoin(buf_struct.tmp, buf_struct.entry->d_name);
        lstat(buf_struct.sorted_arr_l[spaces->count], &buf_struct.buf);
        spaces->total += buf_struct.buf.st_blocks;
        spaces->count++;
    }
}

void mx_print_total (t_buffer_struct_l buf_struct, t_spaces_l *spaces, t_add_in_func *audit) {
    buf_struct.sorted_arr_l = mx_sort(buf_struct.sorted_arr_l, audit);
    spaces->count = 0;
    mx_printstr("total ");
    mx_printint(spaces->total);
    mx_printchar('\n');
}
