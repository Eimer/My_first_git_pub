#include "../inc/uls.h"

static void check_fileordir(char **argv, int ind_str, t_add_in_func *audit) {
    char **print_error = (char **)malloc(sizeof(char *) * audit->argc);
    int count = 0;
    struct stat buf;

    for (count = 0; count < audit->argc; count++)
        print_error[count] = NULL;
    for (count = 0; ind_str < audit->argc; ind_str++)
        if (stat(argv[ind_str], &buf) == -1) {
            print_error[count++] = mx_strdup(argv[ind_str]);
            audit->check_n++;
        }
    for (count = 0; print_error[count] != NULL; count++);
    mx_bubble_sort(print_error, count);
    for (int j = 0; print_error[j] != NULL; j++) {
        errno = 0;
        stat(print_error[j], &buf);
        mx_printerr("uls: ");
        mx_printerr(print_error[j]);
        mx_printerr(": ");
        mx_printerr(strerror(errno));
        mx_printerr("\n");
        audit->main_return = 1;
    }
    mx_del_strarr(&print_error);
}

static int check_flag(char **argv, int check, int ind_str,
                        t_add_in_func *audit) {
    if (argv[ind_str][0] == '-' && argv[ind_str][1] == '-'
        && argv[ind_str][2] == '\0') {
            check_fileordir(argv, ++ind_str, audit);
            return 1;
    }
    if (argv[ind_str][0] != '-') {
        check_fileordir(argv, ind_str, audit);
        return 1;
    }
    if ((argv[ind_str][0] == '-' && argv[ind_str][1] == '-'
        && argv[ind_str][2] != '\0') || check == 0) {
        mx_printstr("usage: uls [-aARrl1] [file ...]\n");
        audit->main_return = 1;
        exit(1);
    }
    return 0;
}

static void write_flags(char flag, t_add_in_func *audit) {
    if (flag == 'a')
        audit->flags[1] = 1;
    if (flag == 'A' && audit->flags[1] == 0)
        audit->flags[2] = 1;
    if (flag == 'R')
        audit->flags[3] = 1;
    if (flag == 'l')
        audit->flags[4] = 1;
    if (flag == '1')
        audit->flags[5] = 1;
    if (flag == 'r')
        audit->flags[6] = 1;
    if (flag == 't')
        audit->flags[7] = 1;
    if (flag == 'S')
        audit->flags[8] = 1;
    if (flag == 'd')
        audit->flags[9] = 1;
    if (flag == 'f') {
        audit->flags[1] = 1;
        audit->flags[10] = 1;
        audit->flags[2] = 0;
    }
}

void mx_errors(int argc, char **argv, t_add_in_func *audit, char *flag) {
    int check = 0;
    int s_f = mx_strlen(flag);// strlen_flag

    for (int ind_str = 1;  ind_str < argc; ind_str++)
        for (int index = 1; index < mx_strlen(argv[ind_str])
            || index == 1; index++)
            for (int i_f = 0; i_f < s_f; i_f++) {// index_flag
                check = 0;
                if (argv[ind_str][index] == flag[i_f]
                    && argv[ind_str][0] == '-') {
                    write_flags(flag[i_f], audit);
                    check = 1;
                    break;
                }
                if (i_f == s_f - 1 && argv[ind_str][index] != flag[i_f])
                    if (check_flag(argv, check, ind_str, audit) == 1)
                        return;
            }
}
