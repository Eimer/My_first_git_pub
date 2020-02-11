#include "../inc/uls.h"

static int mx_test(char *argv) {
    struct stat buf;

    lstat(argv, &buf);
    return buf.st_size;
}

static void swap(char **arr, int i, int j) {
    char *temp;

    if (mx_test(arr[i]) != mx_test(arr[j])) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

char **mx_quick(char **arr, int left, int right) {
    // char *temp;
    int i = left;
    int j = right;
    int pivot = (left + right) / 2;

    if (i < j) {
        while (i <= j) {
            while (mx_test(arr[i]) > mx_test(arr[pivot]))
                i++;
            while (mx_test(arr[j]) < mx_test(arr[pivot]))
                j--;
            if (i < j)
                swap(arr, i, j);
            if (i == j && mx_strcmp(arr[i], arr[j]) > 0)
                swap(arr, i, j);
            if (mx_test(arr[i]) == mx_test(arr[pivot])) {
                if (mx_strcmp(arr[i], arr[pivot]) > 0)
                    swap(arr, i, pivot);
                i++;
            }
            if (mx_test(arr[j]) == mx_test(arr[pivot])) {
                if (mx_strcmp(arr[j], arr[pivot]) > 0)
                    swap(arr, j, pivot);
                j--;
            }
        }
        mx_quick(arr, left, j);
        mx_quick(arr, i, right);
    }
    return arr;
}
