#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char s[5] = {0};

    if (c < 0x80)
        s[0] = c >> (0 & 0x7F) | 0x00;
   	else if (c < 0x0800) {
        s[0] = c >> (6 & 0x1F) | 0xC0;
        s[1] = c >> (0 & 0x3F) | 0x80;
    }
    else if (c < 0x010000) {
        s[0] = c >> (12 & 0x0F) | 0xE0;
        s[1] = c >> (6  & 0x3F) | 0x80;
        s[2] = c >> (0  & 0x3F) | 0x80;
    }
    else if (c < 0x110000) {
        s[0] = c >> (18 & 0x07) | 0xF0;
        s[1] = c >> (12 & 0x3F) | 0x80;
        s[2] = c >> (6  & 0x3F) | 0x80;
        s[3] = c >> (0  & 0x3F) | 0x80;
    }
        write(1, s, 5);
}
