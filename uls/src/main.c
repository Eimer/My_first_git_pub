#include "../inc/uls.h"

//       printf("\n %lld size\n", buf.st_size);
// }

// static void test2_getpwuid() {
//    struct stat buf;
//    lstat("test.txt", &buf);
//    printf("\n %d uid\n", buf.st_uid);
//    struct passwd *pwuid = getpwuid(buf.st_uid);
//    printf("%s", pwuid->pw_name);
//    write(1, &buf.st_size,10);
// }

int main (int argc, char **argv) {
    // t_add_in_func *audit = (t_add_in_func *)malloc(sizeof(t_add_in_func));
    // mx_uls_noatr(argc, argv);
    // int i = 0;
    // if (mx_strcmp(argv[1], "-a") == 0)
    //     i = 0; // if i = 0 -> -a
    // else
    //     i = 1;
    if (argc == 1)
        argv[1] = ".";
        mx_flag_aR(argc, argv);
    // mx_flag_r(argc, argv);
    // mx_enter_fileordir(argc, argv, 3);
    // argc = 0;
    // free(audit);
    // system("leaks -q uls");
    return 0;
}
