NAME = libmx.a
DIROBJ = obj

FILES = mx_printchar \
	mx_binary_search \
	mx_print_unicode \
	mx_strlen \
	mx_printstr \
	mx_print_strarr \
	mx_printint \
	mx_pow \
	mx_sqrt \
	mx_nbr_to_hex \
	mx_hex_to_nbr \
	mx_strnew \
	mx_itoa \
	mx_foreach \
	mx_bubble_sort \
	mx_swap_char \
	mx_str_reverse \
	mx_del_strarr \
	mx_strdel \
	mx_get_char_index \
	mx_strdup \
	mx_strndup \
	mx_strcpy \
	mx_strncpy \
	mx_strcmp \
	mx_strcat \
	mx_strstr \
	mx_get_substr_index \
	mx_count_substr \
	mx_count_words \
	mx_del_extra_spaces \
	mx_strsplit \
	mx_strjoin \
	mx_file_to_str \
	mx_memset \
	mx_memcpy \
	mx_memccpy \
	mx_memcmp \
	mx_memchr \
	mx_memrchr \
	mx_memmove \
	mx_realloc \
	mx_create_node \
	mx_push_front \
	mx_push_back \
	mx_pop_front \
	mx_pop_back \
	mx_list_size \
	mx_sort_list

SRC = $(addprefix ./src/, $(addsuffix .c, $(FILES)))
OBJ = $(addsuffix .o, $(FILES))

CLANG = -std=c11 -Werror -Wextra -Wall -Wpedantic
INC = inc

all: install uninstall

install:
	@mkdir -p $(DIROBJ)
	@clang $(CLANG) -c $(SRC) -I $(INC)
	@ar -rc $(NAME) $(OBJ)
	@mv $(OBJ) $(DIROBJ)

uninstall:
	@rm -rf $(DIROBJ)

clean:
	@rm -rf $(NAME)
	@rm -rf $(DIROBJ)
	@rm -rf $(OBJ)

reinstall: uninstall install
