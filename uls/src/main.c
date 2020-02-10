#include "../inc/uls.h"

// void mx_test(char **argv) {
//     struct stat buf;
//     lstat(argv[1], &buf);

//     mx_printint(buf.st_atime);
// }

int main (int argc, char **argv) {
    // mx_quick(argv, 1, argc);
    // for (int u = 1; u < argc; u++) {
    //     mx_printstr(argv[u]);
    //     mx_printstr("\n");
    // }

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
    // system("leaks -q uls");
    return audit->main_return;
}
