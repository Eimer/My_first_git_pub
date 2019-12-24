#include "../inc/uls.h"

char **flags = {"-l", "-a"};

static void noassces(int argc, char *argv[]) {
    char *flag = mx_strdup("ab");
    int lol = 0;
    int m = 1;

argc++;
    // for (int m = 1;  < argc; m++) {
        if (argv[m][0] != '-') {
            mx_printerr("usage: ./uls [-ab] [file ...]\n");
            exit(0);
        }
        for (int index = 1; index < mx_strlen(argv[m]); index++) {
            for (int check = 0; check < 2; check++) {
                if (argv[m][index] == flag[check]) {
                    lol = 1;
                }
            }
            if (lol != 1) {
                mx_printerr("usage: ./uls [-ab] [file ...]\n");
                exit(0);
            }
        }
    // }
    free(flag);
}

void mx_errors(int argc, char *argv[]) {
    noassces(argc, argv);
}
