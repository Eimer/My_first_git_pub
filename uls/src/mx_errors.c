#include "../inc/uls.h"

static void noassces(int argc, char *argv[]) {
    char *flag = mx_strdup("ab");
    int lol = 0;

argc++;
    for (int ind_char = 1;  argv[ind_char] != NULL; ind_char++) {
        if (argv[ind_char][0] != '-') { // написать функцию, которая чекает не названия файла ли это
            mx_printerr("usage: ./uls [-ab] [file ...]\n");
            exit(0);
        }
        for (int index = 1; index < mx_strlen(argv[ind_char]); index++) {
            for (int check = 0; check < 2; check++) {
                if (argv[ind_char][index] == flag[check]) {
                    lol = 1;
                    break;
                }
                lol = 0;
            }
            if (lol == 0) {
                mx_printerr("usage: ./uls [-ab] [file ...]\n");
                exit(0);
            }
        }
    }
    free(flag);
}

void mx_errors(int argc, char *argv[]) {
    noassces(argc, argv);
}
