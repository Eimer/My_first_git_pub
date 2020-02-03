#include "../inc/uls.h"


int main(int argc, char *argv[]) {
    //mx_get_obj_info("/installer.failurerequests");
    //mx_get_obj_info("main.c");
    //mx_get_obj_info("/Applications/");
    //mx_get_obj_info("/sbin");
    //mx_get_obj_info("link_to_main");
    //mx_get_obj_info(".");
    if (argc == 1) {
        argv[1] = ".";
    }
    mx_output_l(argv[1]);
    argv = NULL;
    argc = 0;
}
// static void test1_stat() {
//     char *date;
//         int ret;
//         struct stat buf;
//         if ((ret = stat("test.txt", &buf))!=0)
//             {
//             fprintf(stderr, "stat failure error .%d", ret);
//             abort();
//             }
//         date = asctime(localtime(&buf.st_ctime));
//         printf("\n %s\n", date);
//         printf("\n %d mode\n", buf.st_mode);
//         printf("\n %lld size\n", buf.st_size);
// }

// static void test2_getpwuid() {
//    struct stat buf;
//    lstat("test.txt", &buf);
//    printf("\n %d uid\n", buf.st_uid);
//    struct passwd *pwuid = getpwuid(buf.st_uid);
//    printf("%s", pwuid->pw_name);
//    write(1, &buf.st_size,10);
// }

    // t_add_in_func *audit = (t_add_in_func *)malloc(sizeof(t_add_in_func));
    // mx_uls_noatr(argc, argv);
    // int i = 0;
    // if (mx_strcmp(argv[1], "-a") == 0)
    //     i = 0; // if i = 0 -> -a
    // else
    //     i = 1;
    // if (argc == 1)
        // argv[1] = ".";
        // mx_flag_aR(argc, argv);
    // mx_flag_r(argc, argv);
    // mx_enter_fileordir(argc, argv, 3);
    // argc = 0;
    // free(audit);
    // system("leaks -q uls");
    // return 0;
// }
