NAME = libmx.a

DIROBJ = obj

SRC = src/mx_printchar.c \
		src/mx_binary_search.c \
		src/mx_print_unicode.c \
		src/mx_strlen.c \
		src/mx_printstr.c \
		src/mx_print_strarr.c \
		src/mx_printint.c \
		src/mx_pow.c \
		src/mx_sqrt.c \
		src/mx_nbr_to_hex.c \
		src/mx_hex_to_nbr.c \
		src/mx_strnew.c \
		src/mx_itoa.c \
		src/mx_foreach.c \
		src/mx_bubble_sort.c \
		src/mx_swap_char.c \
		src/mx_str_reverse.c \
		src/mx_del_strarr.c \
		src/mx_strdel.c \
		src/mx_get_char_index.c \
		src/mx_strdup.c \
		src/mx_strndup.c \
		src/mx_strcpy.c \
		src/mx_strncpy.c \
		src/mx_strcmp.c \
		src/mx_strcat.c \
		src/mx_strstr.c \
		src/mx_get_substr_index.c \
		src/mx_count_substr.c \
		src/mx_count_words.c \
		src/mx_del_extra_spaces.c \
		src/mx_strsplit.c \
		src/mx_strjoin.c \
		src/mx_file_to_str.c \
		src/mx_memset.c \
		src/mx_memcpy.c \
		src/mx_memccpy.c \
		src/mx_memcmp.c \
		src/mx_memchr.c \
		src/mx_memrchr.c \
		src/mx_memmove.c \
		src/mx_realloc.c \
		src/mx_create_node.c \
		src/mx_push_front.c \
		src/mx_push_back.c \
		src/mx_pop_front.c \
		src/mx_pop_back.c \
		src/mx_list_size.c \
		src/mx_sort_list.c 

OUT = mx_printchar.o \
		mx_binary_search.o \
		mx_print_unicode.o \
		mx_strlen.o \
		mx_printstr.o \
		mx_print_strarr.o \
		mx_printint.o \
		mx_pow.o \
		mx_sqrt.o \
		mx_nbr_to_hex.o \
		mx_hex_to_nbr.o \
		mx_strnew.o \
		mx_itoa.o \
		mx_foreach.o \
		mx_bubble_sort.o \
		mx_swap_char.o \
		mx_str_reverse.o \
		mx_del_strarr.o \
		mx_strdel.o \
		mx_get_char_index.o \
		mx_strdup.o \
		mx_strndup.o \
		mx_strcpy.o \
		mx_strncpy.o \
		mx_strcmp.o \
		mx_strcat.o \
		mx_strstr.o \
		mx_get_substr_index.o \
		mx_count_substr.o \
		mx_count_words.o \
		mx_del_extra_spaces.o \
		mx_strsplit.o \
		mx_strjoin.o \
		mx_file_to_str.o \
		mx_memset.o \
		mx_memcpy.o \
		mx_memccpy.o \
		mx_memcmp.o \
		mx_memchr.o \
		mx_memrchr.o \
		mx_memmove.o \
		mx_realloc.o \
		mx_create_node.o \
		mx_push_front.o \
		mx_push_back.o \
		mx_pop_front.o \
		mx_pop_back.o \
		mx_list_size.o \
		mx_sort_list.o 

CLANG = -std=c11 -Werror -Wextra -Wall -Wpedantic

INC = inc/libmx.h

all: install uninstall

install: 
	@mkdir -p $(DIROBJ)
	@clang $(CLANG) -c $(SRC) -I $(INC)
	@ar -rc $(NAME)  $(OUT)
	@mv $(OUT) $(DIROBJ)

uninstall:
	@rm -rf $(DIROBJ)

clean:
	@rm -rf $(NAME)
	@rm -rf $(DIROBJ)
	@rm -rf $(OUT)

reinstall: clean all
