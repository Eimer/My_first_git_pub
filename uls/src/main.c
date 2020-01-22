#include "../inc/uls.h"

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
//     struct stat buf;
//     lstat("test.txt", &buf);
//     printf("\n %d uid\n", buf.st_uid);
//     struct passwd *pwuid = getpwuid(buf.st_uid);
//     printf("%s", pwuid->pw_name);
//     write(1, &buf.st_size,10);
// }

int main(int argc, char const *argv[]) {

     mx_enter_fileordir(argc, argv);
     // if (argc == 1)
     //      mx_uls_noatr(argc, argv);
     // else {
     // mx_errors(argc, argv);
     // char **arr_files = mx_arr_files(argc, argv);
     // if (arr_files != NULL)
     // mx_output(argc, argv, arr_files);
     // char **arr_dirs = mx_arr_dirs(argc, argv);
     // mx_output(argc, argv, arr_dirs);
     // }
     // system("leaks -q uls");
     return 0;
}

// int main (int argc, char const *argv[]) {

//      mx_uls_noatr(argc, argv);
// //     // argc = 0;
// //     // test1_readdir(argv);
// //     // argv = NULL;
// //     //system("leaks -q a.out");
// //     // system("leaks -q uls");
//      return 0;
// }
