#include "../inc/uls.h"
#include <fcntl.h>
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

// static void test2_getpwuid() {
//     struct stat buf;
//     lstat("test.txt", &buf);
//     printf("\n %d uid\n", buf.st_uid);
    
//     struct passwd *pwuid = getpwuid(buf.st_uid);
//     printf("%s", pwuid->pw_name);
//     write(1, &buf.st_size,10);
// }

// static void window() {
//     struct winsize w;
//     ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
//     printf ("lines %d\n", w.ws_row);
//     printf ("columns %d\n", w.ws_col);
    
// }

int main (int argc, char const *argv[]) {
    argc = 0;
    argv = NULL;
    return 0;
}
