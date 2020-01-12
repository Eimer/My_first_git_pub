NAME = pathfinder

LIBAR = ./libmx/libmx.a

DIROBJ = obj

LIB = ./libmx

SRC = src/main.c

OUT = main.o

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
