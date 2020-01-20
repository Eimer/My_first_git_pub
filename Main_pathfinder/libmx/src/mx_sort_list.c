#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    t_list *i = lst->next;
    t_list *j = lst;
    void *buff = NULL;
    for(i = lst; i!= NULL; i = i->next) {
        for(j = i->next; j!= NULL; j = j->next) {
            if(cmp(i->data, j->data) == true) {
                 buff = i->data;
                 i->data = j->data;
                 j->data = buff;
            }
        }
    }
    return lst;
}
