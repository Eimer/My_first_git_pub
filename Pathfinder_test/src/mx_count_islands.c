#include "../inc/pathfinder.h"

int mx_count_islands(char *str) {
    int res = 0;
    int count = 0;
    int count_solo_island = 0;
    char **buff = NULL;
    char **splited_islands = NULL;
    int len_solo_island = 0;
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
    count = 0;
    while (buff[count]) {
        count_solo_island = 0;
        for(int i = 0; i < mx_strlen(buff[count]); i++) {
            if(buff[count][i] == '-') {
                splited_islands[len_solo_island] = mx_strnew(count_solo_island);
                count_solo_island = 0;
                len_solo_island++;
                i++;
            }
            count_solo_island++;
        }
        splited_islands[len_solo_island] = mx_strnew(count_solo_island);
        len_solo_island++;
        count++;
    }
    splited_islands = mx_filling_islands(splited_islands, buff);
    res = mx_no_repeat(splited_islands);
    return res;
}
