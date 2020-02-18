NAME = uls

INC = inc/uls.h

OBJ = obj

LIBMX.A = ./libmx/libmx.a

LIB = libmx

FILES = main \
	mx_arr_dirs \
	mx_arr_files \
	mx_buffer_for_get \
	mx_buffer_l_flag \
	mx_check_denied \
	mx_count_col_with_atr \
	mx_count_col \
	mx_count_longest_with_atr \
	mx_count_longest \
	mx_count_obj \
	mx_dirorfile \
	mx_enter_fileordir \
	mx_errors \
	mx_get_obj_info \
	mx_get_screencoord \
	mx_get_xatr \
	mx_mystrcmp \
	mx_output_l \
	mx_output_with_atr \
	mx_print_atr_l \
	mx_print_result \
	mx_printerr \
	mx_printint_n \
	mx_quick \
	mx_sort_overallarr \
	mx_spaces_l \
	mx_write_flags \
	mx_spaces_buff \
	mx_buff_lstat

CLANG = -std=c11 -Werror -Wextra -Wall -Wpedantic

SRC = $(addprefix ./src/, $(addsuffix .c, $(FILES)))

OUT = $(addsuffix .o, $(FILES))

all: install

install:
	@mkdir -p $(OBJ)
	@clang $(CLANG) -c $(SRC) -I $(INC)
	@mv $(OUT) $(OBJ)
	@make install -C $(LIB)
	@clang $(CLANG) $(SRC) $(LIBMX.A) -o $(NAME) -I $(INC)

clean:
	@make clean -C $(LIB)
	@rm -rf $(OBJ)
	@rm -rf $(OUT)

uninstall:
	@make uninstall -C $(LIB)
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@rm -rf $(OUT)

reinstall: uninstall install
	@make reinstall -C $(LIB)
