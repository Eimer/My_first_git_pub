#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *buff = mx_create_node(data);
    t_list *test = NULL;
    if(!(*list)) {
        *list = buff;
    }
    else {
        test = *list;
        while(test->next != NULL) {
            test = test->next;
        }
        test->next = buff;
    }
}
