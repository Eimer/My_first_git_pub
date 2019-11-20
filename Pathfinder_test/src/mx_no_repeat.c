#include "../inc/pathfinder.h"

int mx_no_repeat(char **splited_islands) {
    int test_c = 0;
    int count_no_repeat = 0;
    int res = 0;
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
    while(splited_islands[count_no_repeat]) {
        if(mx_strcmp("0", splited_islands[count_no_repeat]) != 0){
            res++;
        }
        count_no_repeat++;
    }
    return res;
}
