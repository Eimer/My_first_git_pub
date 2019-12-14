#include "../inc/pathfinder.h"

char **mx_filling_no_repeat(char **splited_islands) {
    int count = 0;
    while (splited_islands[count])
        count++;
    for (int i = 0; i < count; i++) {
        for(int j = 0; j < count; j++) {
            if(i != j) {
                if(mx_strcmp(splited_islands[i], splited_islands[j]) == 0) {
                    splited_islands[j] = "0";
                }
            }
        }
    }
    return splited_islands;
}
