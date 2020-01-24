#include "../inc/uls.h"

static void check_fileordir(char **argv, int ind_str, int argc) {
    char **print_error = (char **)malloc(sizeof(char *) * argc);
    int count = 0;

    for (count = 0; count < argc; count++)
        print_error[count] = NULL;
    for (count = 0; ind_str < argc; ind_str++)
        if (mx_dirorfile(argv[ind_str]) == -1 && errno != 13)
            print_error[count++] = mx_strdup(argv[ind_str]);
    for (count = 0; print_error[count] != NULL; count++);
    mx_bubble_sort(print_error, count);
    for (int j = 0; print_error[j] != NULL; j++) {
        mx_printerr("./uls: ");
        mx_printerr(print_error[j]);
        mx_printerr(": No such file or directory\n");
    }
    mx_del_strarr(&print_error);
}

static int check_flag(int argc, char **argv, int check, int ind_str) {
    if (argv[ind_str][0] == '-' && argv[ind_str][1] == '-'
        && argv[ind_str][2] == '\0') {
            check_fileordir(argv, ++ind_str, argc);
            return 1;
    }
    if (argv[ind_str][0] != '-') {
        check_fileordir(argv, ind_str, argc);
        return 1;
    }
    if (argv[ind_str][0] == '-' && argv[ind_str][1] == '-'
        && argv[ind_str][2] != '\0') {
        mx_printstr("usage: ./uls [-abcd] [file ...]\n");
        exit(0);
    }
    if (check == 0) {
        mx_printerr("usage: ./uls [-abcd] [file ...]\n");
        exit(0);
    }
    return 0;
}

void mx_errors(int argc, char **argv) {
    char *flag = "abcd";
    int check = 0;
    int s_f = mx_strlen(flag);// strlen_flag

    for (int ind_str = 1;  ind_str < argc; ind_str++)
        for (int index = 1; index < mx_strlen(argv[ind_str])
            || index == 1; index++)
            for (int i_f = 0; i_f < s_f; i_f++) {// index_flag
                check = 0;
                if (argv[ind_str][index] == flag[i_f]
                    && argv[ind_str][0] == '-') {
                    check = 1;
                    break;
                }
                if (i_f == s_f - 1 && argv[ind_str][index] != flag[i_f])
                    if (check_flag(argc, argv, check, ind_str) == 1)
                        return;
            }
}
