#include "../inc/libmx.h"

void mx_printchar(char c);
void mx_printint(int n) {
	int count = 0;
	int check = 0;
	int pow = 1;
	int buffer = 0;
	if(n == 0) {
		mx_printchar('0');
	}
	if(n == -2147483648) {
		mx_printchar('-');
		mx_printchar('2');
		n = 147483648;
	}
	if (n < 0) {
		n = n * -1;
		check = 1;
	}
	buffer = n;
	while(n != 0) {
		n = n / 10;
		count++;
	}
	for(int i = 0; i < count - 1; i++) {
		pow = pow * 10;
	}
	if(check) {
		mx_printchar('-');
	}
	for(int i = 0; i < count; i++) {
		mx_printchar(buffer / pow + 48);
		buffer = buffer % pow;
		pow = pow / 10;
	}
}
