#include "../inc/pathfinder.h"

char **mx_filling_islands(char **splited_islands, char **buff) {
    char *str = NULL;
    char *tmp;
    int count = 0;
    str = "$+±§965kostyl-";
    while(buff[count]) {
        tmp = mx_strjoin(str, buff[count]);
        str = mx_strjoin(tmp, "-");
        count++;
    }
    str[mx_strlen(str) - 1] = '\0'; 
    splited_islands = mx_strsplit(str, '-');
    free(str);
    return splited_islands;
}
