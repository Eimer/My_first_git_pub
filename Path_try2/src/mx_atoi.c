#include "../inc/pathfinder.h"

int mx_atoi(char *str) {
    int res = 0;
    int len = mx_strlen(str);
    int pow = 1;
    for (int i = 0; i < len - 1; i++){
        pow = 10 * pow;
    }
    for (int i = 0; i < len; i++){
        res += (str[i] - 48) * pow;
        pow = pow/10;
    }
    return res;
}
