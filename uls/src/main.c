#include "../inc/uls.h"

int main (int argc, char **argv) {
    mx_output_l(argv[1]);
    exit(0);
    t_add_in_func *audit = (t_add_in_func *)malloc(sizeof(t_add_in_func));
    audit->flags = (int *)malloc(sizeof(int) * 10);

    audit->argc = argc;
    audit->check = 0;
    audit->check_n = 0;
    for (int u = 0; u < 10; u++)
        audit->flags[u] = 0;
    mx_errors(argc, argv, audit, "aARl1");
    if (audit->flags[3] == 1)
        mx_flag_aR(argc, argv, audit);
    else
        mx_enter_fileordir(argc, argv, audit);
    free(audit->flags);
    free(audit);
    // system("leaks -q uls");
    return 0;
}
