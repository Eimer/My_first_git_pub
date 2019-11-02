#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
	for(int i = mx_strlen(s); i >= 0; i--) {
		mx_printchar(s[i]);
	}
}
