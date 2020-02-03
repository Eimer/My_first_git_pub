#include "../inc/uls.h"

int main (int argc, char **argv) {
    // t_add_in_func *audit = (t_add_in_func *)malloc(sizeof(t_add_in_func));
    // mx_uls_noatr(argc, argv);
    int i = 0;
    // if (mx_strcmp(argv[1], "-a") == 0)
    //     i = 0; // if i = 0 -> -a
    // else
    //     i = 1;
    if (argc == 1)
        argv[1] = ".";
        // mx_flag_aR(argc, argv);
    // mx_flag_r(argc, argv);
    mx_enter_fileordir(argc, argv, i);
    // argc = 0;
    // free(audit);
    // system("leaks -q uls");
    return 0;
}
