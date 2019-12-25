#include "../inc/uls.h"

static void check_fileorflag(int argc, char const *argv, int lol) {
    argc--;
    if (argv[0] == '-' && argv[1] == '-' && argv[2] == '\0') {
        mx_printstr("YES");
        return;
    }
    if (argv[0] == '-' && argv[1] == '-' && argv[2] != '\0') {
        mx_printstr("usage: ./uls [-ab] [file ...]\n");
        return;
    }
    if (argv[0] != '-') { // написать функцию, которая чекает не названия файла ли это
        mx_printerr("usage: ./uls [-ab] [file ...]\n");
        exit(0);
    }
    if (lol == 0) {
        mx_printerr("usage: ./uls [-ab] [file ...]\n");
        exit(0);
    }
}

static void noassces(int argc, char const *argv[]) {
    char *flag = mx_strdup("ab");
    int lol = 0;

argc++;
    for (int ind_char = 1;  argv[ind_char] != NULL; ind_char++) {
        for (int index = 1; index < mx_strlen(argv[ind_char]); index++)
            for (int check = 0; check < 2; check++) {
                if (argv[ind_char][index] == flag[check]) {
                    lol = 1;
                    break;
                }
                lol = 0;
            }
        check_fileorflag(argc, argv[ind_char], lol);
    }
    free(flag);
}

void mx_errors(int argc, char const *argv[]) {
    noassces(argc, argv);
}
