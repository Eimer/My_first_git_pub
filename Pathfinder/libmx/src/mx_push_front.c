#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
    if(!list || !*list) {
        *list = mx_create_node((void *)data);
    } else {
        t_list *tmp = *list;
         *list = mx_create_node((void *)data);
        (*list)->next= tmp;
    }
}
