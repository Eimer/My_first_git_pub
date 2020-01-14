#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
	int j = 0;
	int i = mx_strlen(s) - 1;
	while(i > j) {
		mx_swap_char(&s[i], &s[j]);
		i--;
		j++;
	}
}
