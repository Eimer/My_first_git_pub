 #include "libmx.h" 

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int i = 0;
    int j = 0;

    if ((str == NULL) || (sub == NULL))
        return -1;
    while (i <= mx_strlen(str)) {
        while (str[i] == sub[j])
            j++;
        if (mx_strlen(sub) == j) {
            count++;
            j = 0;
        }
        i++;
    }
    return count;
}
