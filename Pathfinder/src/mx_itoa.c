#include "../inc/pathfinder.h"

char *mx_itoa(int number) {
	int check = 0;
	int size = 0;
	int buff = 0;
	char *res = NULL;
	char *res1 = NULL;
	if (number == -2147483648) {
		return "-2147483648";
	}
	if (number < 0) {
		number = number * -1;
		check = 1;
		size++;
	}
	buff = number;
	while(number) {
		number = number / 10;
		size++;
	}
	res = (char *) malloc(size + 1);
	res1 = (char *) malloc(size + 1);
	for (int i = 0; i < size - check; i++) {
		res[i] = buff % 10 + 48;
		buff = buff / 10;
	}
	if(check) {
		res[size - 1] = '-';
	}
	res[size] = '\0';
	for (int i = 0; i < size; i++) {
		res1[size - i - 1] = res[i];
	}
	res1[size] = '\0';
	free(res);
	return res1;
}
