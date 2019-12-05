#include "../inc/pathfinder.h"

char **mx_memory_for_islands(char *str) {
    int count = 0;

    char **splited_islands = NULL;
    char **buff = NULL;
    buff = mx_strsplit(str, '\n');
    while (buff[count]) {
        for(int j = mx_strlen(buff[count]) - 1; j >= 0; j--) {
            if (buff[count][j] != ',') {
                buff[count][j] = '\0';
            }
            else {
                buff[count][j] = '\0';
                break;
            }
        }
        count++;
    }
    splited_islands = (char **)malloc(sizeof(char *) * (count * 2));
    splited_islands[count] = NULL;
    return splited_islands;
}
