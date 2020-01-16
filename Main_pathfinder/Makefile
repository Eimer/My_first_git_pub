NAME = pathfinder

OBJ = obj

LIBMX.A = ./libmx/libmx.a

LIB = libmx

CLANG = -std=c11 -Werror -Wextra -Wall -Wpedantic

SRC = src/main.c \
src/mx_arr_dist.c \
src/mx_arr_from.c \
src/mx_arr_path.c \
src/mx_arr_to.c \
src/mx_atoi.c \
src/mx_buff_print.c \
src/mx_errors.c \
src/mx_fill_s_arr.c \
src/mx_first_line.c \
src/mx_get_min.c \
src/mx_get_no_repeat.c \
src/mx_invalid_line.c \
src/mx_is_empty.c \
src/mx_isdigit.c \
src/mx_islands_no_repeat.c \
src/mx_nofile.c \
src/mx_openfile.c \
src/mx_output.c \
src/mx_path_dist.c \
src/mx_print_delim.c \
src/mx_print_first_line.c \
src/mx_print_invalid_line.c \
src/mx_printerr.c \
src/mx_restore_path.c \
src/mx_strcat.c \
src/mx_true_arguments.c \
src/mx_true_content.c


OUT = main.o \
mx_arr_dist.o \
mx_arr_from.o \
mx_arr_path.o \
mx_arr_to.o \
mx_atoi.o \
mx_buff_print.o \
mx_errors.o \
mx_fill_s_arr.o \
mx_first_line.o \
mx_get_min.o \
mx_get_no_repeat.o \
mx_invalid_line.o \
mx_is_empty.o \
mx_isdigit.o \
mx_islands_no_repeat.o \
mx_nofile.o \
mx_openfile.o \
mx_output.o \
mx_path_dist.o \
mx_print_delim.o \
mx_print_first_line.o \
mx_print_invalid_line.o \
mx_printerr.o \
mx_restore_path.o \
mx_strcat.o \
mx_true_arguments.o \
mx_true_content.o

INC = inc/pathfinder.h

all: install uninstall

install:
	@mkdir -p $(OBJ)
	@clang $(CLANG) -c $(SRC) -I $(INC)
	@mv $(OUT) $(OBJ)
	@make install -C $(LIB)
	@clang $(CLANG) $(SRC) $(LIBMX.A) -o $(NAME) -I $(INC)

uninstall:
	@rm -rf $(OBJ)
	@make uninstall -C $(LIB)

clean:
	@make clean -C $(LIB)
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@rm -rf $(OUT)

reinstall: clean all
	@make reinstall -C $(LIB)