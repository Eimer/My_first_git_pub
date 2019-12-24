#include "../inc/uls.h"

t_size mx_get_screencoord() {
    struct winsize wind;
    t_size screen_res;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &wind);
    screen_res.col = wind.ws_col;
    screen_res.row = wind.ws_row;
    return screen_res;
}
