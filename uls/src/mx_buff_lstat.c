#include "../inc/uls.h"

void mx_buff_lstat (t_buffer_struct_l buf_struct, t_spaces_l *spaces) {
    buf_struct.sorted_arr_l[spaces->count]
        = mx_strjoin(buf_struct.tmp, buf_struct.entry->d_name);
        stat(buf_struct.sorted_arr_l[spaces->count], &buf_struct.buf);
        spaces->total += buf_struct.buf.st_blocks;
}
