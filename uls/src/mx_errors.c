#include "../inc/uls.h"

static void printerror(char *print_error, struct stat buf) {
    errno = 0;
    stat(print_error, &buf);
    mx_printerr("uls: ");
    mx_printerr(print_error);
    mx_printerr(": ");
    mx_printerr(strerror(errno));
    mx_printerr("\n");
}

static void check_fileordir(char **argv, int ind_str, t_add_in_func *audit) {
    char **print_error = (char **)malloc(sizeof(char *) * audit->argc);
    int count = 0;
    struct stat buf;

    for (count = 0; count < audit->argc; count++)
        print_error[count] = NULL;
    audit->check_n = audit->argc - ind_str;
    for (count = 0; ind_str < audit->argc; ind_str++)
        if (stat(argv[ind_str], &buf) == -1 && errno != 13)
            print_error[count++] = mx_strdup(argv[ind_str]);
    for (count = 0; print_error[count] != NULL; count++);
    mx_bubble_sort(print_error, count);
    for (int j = 0; print_error[j] != NULL; j++)
        printerror(print_error[j], buf);
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
        mx_printerr("uls: illegal option -- ");
        mx_printcharerr(audit->error);
        mx_printerr("\nusage: uls [-aARrl1dfS] [file ...]\n");
        audit->main_return = 1;
        exit(1);
    }
    return 0;
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
                    mx_write_flags(flag[i_f], audit);
                    check = 1;
                    break;
                }
                if (i_f == s_f - 1) {
                    audit->error = argv[ind_str][index];
                    if (check_flag(argv, check, ind_str, audit) == 1)
                        return;
                }
            }
}
