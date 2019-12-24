#include "../inc/uls.h"

// static void test1_readdir(const char *argv[]) {
//     DIR *dir;
//     struct dirent *entry;

//     dir = opendir(argv[1]);
//     if (!dir) {
//         perror("diropen");
//         exit(1);
//     };
//     while ( (entry = readdir(dir)) != NULL) {
//         mx_printstr(entry->d_name);
//         mx_printstr("\t");
//     }
//     mx_printstr("\n");
//     closedir(dir);
// }

// static void test1_stat() {
//     char *date;
//         int ret;
//         struct stat buf;
//         if ((ret = stat("test.txt", &buf))!=0)
//           {
//             fprintf(stderr, "stat failure error .%d", ret);
//             abort();
//           }
//         date = asctime(localtime(&buf.st_ctime));
//         printf("\n %s\n", date);
//         printf("\n %d mode\n", buf.st_mode);
//         printf("\n %lld size\n", buf.st_size);
// }

int main (int argc, char *argv[]) {
    // argc = 0;
    // argv = NULL;
    mx_errors(argc, argv);
    return 0;
}
