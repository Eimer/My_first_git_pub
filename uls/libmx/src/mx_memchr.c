#include "../inc/libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
	char new;
	char *str = NULL;

	if (c > 0 && c < 10)
		new = c + 48;
	else
		new = c;
	str = (char*) s;
	for (size_t i = 0; i < n; i++) {
		if (str[i] == new)
			return &str[i];
	}
	return NULL;
}
