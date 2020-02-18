#include "../inc/uls.h"

static void write_flags_f(char flag, t_add_in_func *audit) {
    if (flag == 'r')
        audit->flags[6] = 1;
    if (flag == 'd')
        audit->flags[9] = 1;
    if (flag == 't')
        audit->flags[8] = 1;
    if (flag == 'S')
        audit->flags[7] = 1;
}

void mx_write_flags(char flag, t_add_in_func *audit) {
    if (flag == 'a')
        audit->flags[1] = 1;
    if (flag == 'A' && audit->flags[1] == 0)
        audit->flags[2] = 1;
    if (flag == 'R')
        audit->flags[3] = 1;
    if (flag == 'l') {
        audit->flags[4] = 1;
        audit->flags[5] = 0;
    }
    if (flag == '1') {
        audit->flags[5] = 1;
        audit->flags[4] = 0;
    }
    write_flags_f(flag, audit);
    if (flag == 'f') {
        audit->flags[1] = 1;
        audit->flags[10] = 1;
        audit->flags[2] = 0;
    }
}
