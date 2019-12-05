#include "../inc/pathfinder.h"

char **mx_memory_for_each_island(char *str, char **splited_islands) {
    int count = 0;
    int count_solo_island = 0;
    int len_solo_island = 0;
    char **buff  = mx_strsplit(str, '\n');
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
    return buff;
}
