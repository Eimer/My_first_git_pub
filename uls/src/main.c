#include "../inc/uls.h"

int main(int argc, char*argv[]) {
t_add_in_func *audit = (t_add_in_func *)malloc(sizeof(t_add_in_func));

    audit->flags = (int *)malloc(sizeof(int) * 10);
    audit->main_return = 1;
    audit->argc = argc;
    audit->check = 0;
    audit->check_n = 0;
    for (int u = 0; u < 10; u++)
        audit->flags[u] = 0;
    mx_errors(argc, argv, audit, "aARrl1tSdf");
    if (audit->check_n > 1)
        audit->flags[0] = 1;
    mx_enter_fileordir(argc, argv, audit);
    free(audit->flags);
    free(audit);
    //system("leaks -q uls");
    return audit->main_return;
}
