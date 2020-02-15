#include "libmx.h" 

int mx_count_words(const char *str, char c) {
    int count = 0;
    int j = 0;

    if (str == NULL)
        return -1;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == c)
            j = 0;
        else {
            if (j == 0)
                count++;
            j = 1;
        }
    }
    return count;
}
