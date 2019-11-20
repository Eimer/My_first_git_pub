NAME = pathfinder

LIBAR = ./libmx/libmx.a

DIROBJ = obj

LIB = ./libmx

SRC = src/main.c \
src/mx_printerr.c \
src/mx_isdigit.c \
src/mx_count_islands.c \
src/mx_itoa.c \
src/mx_mystrcmp.c \
src/mx_nofile.c \
src/mx_is_empty.c \
src/mx_invalid_line.c \
src/mx_print_invalid_line.c \
src/mx_filling_islands.c \
src/mx_no_repeat.c \
src/mx_is_number.c

OUT = main.o \
mx_printerr.o \
mx_isdigit.o \
mx_count_islands.o \
mx_itoa.o \
mx_mystrcmp.o \
mx_nofile.o \
mx_is_empty.o \
mx_invalid_line.o \
mx_print_invalid_line.o \
mx_filling_islands.o \
mx_no_repeat.o \
mx_is_number.o

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
