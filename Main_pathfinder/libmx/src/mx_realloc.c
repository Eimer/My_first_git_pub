#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    char *res;
    char *buff = ptr;
    if(!ptr && size != 0) {
        res = (void *) malloc(size);
        return res;
    }
    if(size == 0) {
        free(ptr);
        return NULL;
    }
    
    res = (char *) malloc(size* sizeof(char));
    for (size_t i = 0; i < size; i++) {
        res[i] = buff[i];
    }
    free(ptr);
    ptr = NULL;
    return res;
}
