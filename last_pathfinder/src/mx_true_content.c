#include "../inc/pathfinder.h"

void mx_true_content(char **argc) {
    char buff_file;
    int openf = 0;
    int content_file = 0;

    openf = open(argc[1], O_RDONLY);
    content_file = read(openf, &buff_file, 1);
    if(content_file <= 0) {
        mx_is_empty(argc[1]);
        close(openf);
        exit(0);
    }
}
