#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int counter = 0;
    t_list *buff = NULL;
    if(!list) {
        return 0;
    }
    buff = list;
    while(buff->next != NULL) {
        counter++;
        buff= buff->next;
    }
    return counter + 1;
}
