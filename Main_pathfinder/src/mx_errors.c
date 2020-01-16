#include "../inc/pathfinder.h"

void mx_errors(int argc, char *argv[]) {
    int err_line = 0;
    
    mx_true_argumensts(argc);
    mx_openfile(argv);
    mx_true_content(argv);
    mx_first_line(argv);
    err_line = mx_invalid_line(argv);
    if (err_line) {
        mx_print_invalid_line(argv, mx_itoa(err_line));
        exit(0);
    }
    if (!mx_islands_no_repeat(argv)) {
        mx_printerr("error: invalid number of islands\n");
        exit(0);
    }
}
