#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    const char* big_str = big;
    const char *little_str = little;
      
    if(!big_str || !little || big_len == 0 || little_len == 0) {
        return NULL;
    }
    for (size_t i = 0; i < big_len; i++) {
        for (size_t j = 0; j < little_len; j++) {
            if(mx_strcmp(&big_str[i], &little_str[j]) != 0) {
                break;
            }
            else {
                return (void *)&big_str[i];
            }
        }
        
    }
    return NULL;
}
