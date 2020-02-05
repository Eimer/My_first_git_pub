#include "../inc/uls.h"

void mx_get_xatr(char *obj) {
    int xatr = 0;
    acl_t plus;

    xatr = listxattr(obj, NULL, 0, XATTR_NOFOLLOW);
    plus = acl_get_file(obj, ACL_TYPE_EXTENDED);
    if (xatr > 0) {
        mx_printchar('@');
    }
    else if (plus != NULL)
        mx_printchar('+');
    else {
        mx_printchar(' ');
    }
    acl_free(plus);
}
