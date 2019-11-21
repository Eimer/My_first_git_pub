#include "../inc/pathfinder.h"

int main(int argv, char*argc[]) {

    char *str_from_file = NULL;
    int count = 0;
    int invalid_line = 0;
    char *first_line = NULL;
    mx_true_argumensts(argv);
    mx_openfile(argc);
    mx_true_content(argc);
    str_from_file = mx_file_to_str(argc[1]);
    mx_islands_arr(str_from_file);
    return 0;
    while(str_from_file[count]!= '\n') {
        count++;
    }
    first_line = mx_fill_first_line(first_line, str_from_file);
    
    if(!mx_isdigit(first_line)) {
        mx_printerr("error: line 1 isn't valid");
        free(str_from_file);
        free(first_line);
        return 0;
    }
    invalid_line = mx_invalid_line(str_from_file);

    if(invalid_line != 0) {
        mx_print_invalid_line(str_from_file);
        return 0;
    }
    if(mx_mystrcmp(mx_itoa(mx_count_islands(str_from_file)), first_line) != 0 
        || mx_strlen(first_line) != mx_strlen(mx_itoa(mx_count_islands(str_from_file)))) {
        mx_printerr("error: invalid number of islands");
        return 0;
    }
    free(first_line);
    free(str_from_file);
    return 0;
}
