#include "../inc/libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
	int len = 0;
	if(arr[len] && delim) {
		while(arr[len]) {
			mx_printstr(arr[len]);
			if(arr[len + 1]) {
				mx_printstr(delim);
			}
			len++;
		}
		write(1, "\n", 1);
	}
}
