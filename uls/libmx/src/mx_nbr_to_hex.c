#include "libmx.h"

static void func(int nbr, int a) {
    while (nbr / 16 != 0) {
        nbr = nbr / 16;
        a++;
    }
}

char *mx_nbr_to_hex(unsigned long nbr) {
    char *hex = NULL;
    int a = 0;
    int buff = nbr;
    int result = 0;

    if (nbr == 0)
        return 0;
    func(nbr, a);
    hex = mx_strnew(a);
    for (int i = a; i >= 0; i--) {
        result = buff % 16;
        if (result > 9 && result < 16)
            hex[i] = (char)(result + 87);
        else
            hex[i] = (char)(result + 48);
        buff = buff / 16;
    }
    return hex;
}
