NAME = pathfinder

LIBAR = ./libmx/libmx.a

DIROBJ = obj

LIB = ./libmx

SRC = src/main.c \
src/mx_arr_dist.c \
src/mx_arr_from.c \
src/mx_arr_to.c \
src/mx_atoi.c \
src/mx_count_dist.c \
src/mx_count_islands.c \
src/mx_count_path.c \
src/mx_fill_first_line.c \
src/mx_fill_matrix.c \
src/mx_fill_struct_distance.c \
src/mx_fill_struct_name.c \
src/mx_filling_islands.c \
src/mx_filling_no_repeat.c \
src/mx_invalid_line.c \
src/mx_is_empty.c \
src/mx_is_number.c \
src/mx_isdigit.c \
src/mx_islands_arr.c \
src/mx_itoa.c \
src/mx_matrix.c \
src/mx_memory_for_each_island.c \
src/mx_memory_for_islands.c \
src/mx_mystrcmp.c \
src/mx_no_repeat.c \
src/mx_nofile.c \
src/mx_openfile.c \
src/mx_output.c \
src/mx_output_path.c \
src/mx_path.c \
src/mx_path_dist.c \
src/mx_print_delim.c \
src/mx_print_invalid_line.c \
src/mx_printerr.c \
src/mx_true_arguments.c \
src/mx_true_content.c

OUT = main.o \
mx_arr_dist.o \
mx_arr_from.o \
mx_arr_to.o \
mx_atoi.o \
mx_count_dist.o \
mx_count_islands.o \
mx_count_path.o \
mx_fill_first_line.o \
mx_fill_matrix.o \
mx_fill_struct_distance.o \
mx_fill_struct_name.o \
mx_filling_islands.o \
mx_filling_no_repeat.o \
mx_invalid_line.o \
mx_is_empty.o \
mx_is_number.o \
mx_isdigit.o \
mx_islands_arr.o \
mx_itoa.o \
mx_matrix.o \
mx_memory_for_each_island.o \
mx_memory_for_islands.o \
mx_mystrcmp.o \
mx_no_repeat.o \
mx_nofile.o \
mx_openfile.o \
mx_output.o \
mx_output_path.o \
mx_path.o \
mx_path_dist.o \
mx_print_delim.o \
mx_print_invalid_line.o \
mx_printerr.o \
mx_true_arguments.o \
mx_true_content.o

INC = inc/pathfinder.h

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

all: install uninstall
install:
	@cd $(LIB) && make install
	@mkdir $(DIROBJ)
	@clang $(FLAGS) $(SRC) -c $(SRC) -I $(INC)
	@mv $(OUT) $(DIROBJ)
	@clang $(FLAGS) $(SRC) $(LIBAR) -o $(NAME) -I $(INC)


uninstall:
	@rm -rf $(DIROBJ)
	@cd $(LIB) && make uninstall
clean: 
	@rm -rf $(NAME)
	@cd $(LIB) && make clean
reinstall: clean all
