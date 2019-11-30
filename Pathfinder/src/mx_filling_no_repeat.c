#include "../inc/pathfinder.h"

char **mx_filling_no_repeat(char **splited_islands) {
    int test_c = 0;
    while(splited_islands[test_c]) {
        test_c++;
    }
    for (int i = 0; i < test_c; i++) {
        for(int j = 0; j < test_c; j++) {
            if(i != j) {
                if(mx_strcmp(splited_islands[i], splited_islands[j]) == 0) {
                    splited_islands[j] = "0";
                }
            }
        }
    }
    return splited_islands;
}
