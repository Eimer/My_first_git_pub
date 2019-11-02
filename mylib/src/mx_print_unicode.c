#include "../inc/libmx.h"
void mx_print_unicode(wchar_t c) {
	char res[4];
	if(c < 0x80) {
		res[0] = c >> (0 & 0x7f) | 0x00;
		res[1] = '\0';
		res[2] = '\0';
		res[3] = '\0';
	}
		else if(c < 0x0800) {
		res[0] = c >> (6 & 0x1f) | 0xc0;
		res[1] = c >> (0 & 0x3f) | 0x80;
		res[2] = '\0';
		res[3] = '\0';
	}
		else if(c < 0x010000) {
		res[0] = c >> (12 & 0x0f) | 0xe0;
		res[1] = c >> (6 & 0x3f) | 0x80;
		res[2] = c >> (0 & 0x3f) | 0x80;
		res[3] = '\0';
	}
		else if(c < 0x110000) {
		res[0] = c >> (18 & 0x07) | 0xf0;
		res[1] = c >> (12 & 0x3f) | 0x80;
		res[2] = c >> (6 & 0x3f) | 0x80;
		res[3] = c >> (0 & 0x3f) | 0x80;
	}
		write(1, res, 4);
}
