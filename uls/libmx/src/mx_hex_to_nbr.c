#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    int a = 0;
    unsigned long b = 0;
    unsigned long n = 1;

    if (hex == NULL)
        return 0;
    while (hex[a++]);
    for (int i = a - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9')
            b += (hex[i] - 48) * n;
        else if (hex[i] >= 65 && hex[i] <= 70)
            b += (hex[i] - 55) * n ;
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            b += (hex[i] - 87) * n;
        n = n * 16;
    }
    if (hex == NULL)
        return 0;
    return b;
}
