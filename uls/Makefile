NAME = uls

OBJ = obj

LIBMX.A = ./libmx/libmx.a

LIB = libmx

CLANG = -std=c11 -Werror -Wextra -Wall -Wpedantic

SRC = src/main.c

OUT = main.o 

INC = inc/uls.h

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
