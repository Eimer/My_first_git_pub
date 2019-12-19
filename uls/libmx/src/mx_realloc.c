#include "../inc/libmx.h"
void *mx_realloc(void *ptr, size_t size) {
	void *s;

	if (size == 0 && ptr == NULL) {
		return NULL;
	}
	if (ptr == NULL) {
		return malloc(size);
	}
	if (size == 0) {
		return ptr;
	}
	s = malloc(size);
	mx_memcpy(s, ptr, size);
	return s;
}
