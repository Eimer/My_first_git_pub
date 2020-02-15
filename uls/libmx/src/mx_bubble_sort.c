#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int counter = 0;
    char *buff;

    if (size < 0)
        return 0;
    for (int j = 0; j < size - 1; j++) {
        for (int i = 0; i < size - 1 - j; i++) {
            if (mx_strcmp(arr[i], arr[i + 1]) > 0) {
                buff = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buff;
                counter++;
            }
        }
    }
    return counter;
}
