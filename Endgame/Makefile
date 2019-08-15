SRC = src/main.c \
      src/g_rendmap.c \
      src/g_test.c \
      src/g_start_screen.c \
      src/g_second_screen.c \
      src/mx_strlen.c \
	  src/g_third_screen.c \
	  src/g_print_map.c \
	  src/g_move_player.c \
	  src/g_move_enemy.c \
	  src/g_attack.c \
      src/g_print_stats.c \
  	  src/g_level_success.c \
      src/g_game_over.c \
	  src/g_game_over2.c 

BIN = endgame

OUT = main.o \
	  src/g_test.o \
	  g_rendmap.o \
	  g_start_screen.o \
	  g_second_screen.o \
      mx_strlen.o \
	  g_third_screen.o \
	  g_print_map.o \
	  g_move_player.o \
	  g_move_enemy.o \
	  g_attack.o \
	  g_print_stats.o \
	  g_level_success.o \
      g_game_over.o \
	  g_game_over2.o 
	  
all: 
	@clang -Werror -Wextra -Wall -Wpedantic -lncurses  $(SRC) -o $(BIN)

install:
	clang -c $(SRC)
	ar -r minilibmx.a $(OUT)

uninstall: 
	rm $(BIN)
	clean
		
clean:
	rm $(OUT)
	@rm minilibmx.a

reinstall:
	clang -c $(SRC)
	ar -r minilibmx.a $(OUT)
	rm $(OUT)
	rm minilibmx.a
