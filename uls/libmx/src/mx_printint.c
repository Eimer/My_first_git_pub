#include "libmx.h"

void vstatic(int n) {
    int buffer = n;
    int pow = 1;
    int count = 0;

    while (n != 0) {
        n = n / 10;
        count++;
    }
    for (int i = 0; i < count - 1; i++) {
        pow = pow * 10; 
    }
    for (int i = 0; i < count; i++) {
        mx_printchar(buffer / pow + 48);
        buffer = buffer % pow;
        pow = pow / 10;
    }
}

void mx_printint(int n) {
    if (n == -2147483648) {
        mx_printstr("-2147483648");
        return;
    }
    if (n == 0) {
        mx_printchar('0');
    }
    if (n < 0) {
        n = n * -1;
        mx_printchar('-');
    }
    vstatic(n);
}
