#include "../inc/uls.h"

static int mx_test(char *argv) {
    struct stat buf;

    lstat(argv, &buf);
    return buf.st_mtime;
}

void mx_quick(char **arr, int left, int right) {
    char *temp;
    int i = left;
    int j = right;
    char *pivot = arr[(left + right) / 2];

    if (i < j) {
        while (i <= j) {
            while (mx_test(arr[i]) < mx_test(pivot))
                i++;
            while (mx_test(arr[j]) > mx_test(pivot))
                j--;
            if (i <= j)
                if (mx_test(arr[i]) != mx_test(arr[j])) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            if (mx_test(arr[i]) == mx_test(pivot))
                i++;
            if (mx_test(arr[j]) == mx_test(pivot))
                j--;
        }
        mx_quick(arr, left, j);
        mx_quick(arr, i, right);
    }
}
