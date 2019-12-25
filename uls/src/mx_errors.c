#include "../inc/uls.h"

static void check_fileordir(char const *argv[], int ind_char, int argc) {
    while (ind_char < argc) {
        if (mx_dirorfile(argv[ind_char]) == 1 
            || (mx_dirorfile(argv[ind_char]) == 0)) {
            mx_printstr("YES\n");
        }
        else {
            mx_printerr("./uls ");
            mx_printerr(argv[ind_char]);
            mx_printerr(": No such file or directory");
        }
        ind_char++;
    }
}

// static void check_flag(char const *argv[], int lol, int ind_char) {
//     // mx_printstr(" LOL ");
//     // mx_printint(lol);
//     if (argv[ind_char][0] == '-' && argv[ind_char][1] == '-' 
//         && argv[ind_char][2] != '\0') {
//         mx_printstr("usage: ./uls [-ab] [file ...]\n");
//         return;
//     }
//     if (argv[ind_char][0] != '-') {
//         mx_printerr("usage: ./uls [-ab] [file ...]\n");
//         exit(0);
//     }
//     if (lol == 0) {
//         mx_printerr("usage: ./uls [-ab] [file ...]\n");
//         exit(0);
//     }
// }

static void noassces(int argc, char const *argv[]) {
    char *flag = mx_strdup("ab");
    int lol = 0;

    for (int ind_char = 1;  ind_char < argc; ind_char++) {
        for (int index = 1; index < mx_strlen(argv[ind_char]); index++)
            for (int check = 0; check < 2; check++) {
                if (argv[ind_char][index] == flag[check]) {
                    lol = 1;
                    break;
                }
                lol = 0;
            }
        // check_flag(argv, lol, ind_char);
        if (argv[ind_char][0] == '-' && argv[ind_char][1] == '-'
            && argv[ind_char][2] == '\0') {
            check_fileordir(argv, ++ind_char, argc);
            return;
        }
    }
    free(flag);
}

void mx_errors(int argc, char const *argv[]) {
    noassces(argc, argv);
}
