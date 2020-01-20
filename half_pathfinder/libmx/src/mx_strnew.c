#include "../inc/libmx.h"

char *mx_strnew(const int size) {
	char *res;
	if (size < 0) {
		return NULL;
	}
	res = (char *) malloc(size + 1);
	for (int i = 0; i < size; i++) {
		res[i] = '\0';
	}
	res[size] = '\0';
return res;
}
