#ifndef HEADER_FILE
# define HEADER_FILE

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stddef.h>
#include <fcntl.h>
#include <time.h>
#include <locale.h>
#include <curses.h>

void g_test();
void g_rendmap(char **g_map, int m_x, int m_y);
void g_startscreen();
int mx_strlen(const char *s);
void g_second_screen(char *username, int m_x, int m_y);
void mx_third_screen(char *username);
void g_player_move();
void g_rend_room1(char **g_map, int i, int j, int g_rnd1);
void g_rend_room2(char **g_map, int i, int j, int g_rnd_st_x1, int g_rnd_st_y1, int g_rnd_sizex, int g_rnd_sizey);
void g_rend_room3(char **g_map, int i, int j, int g_rnd_st_x2, int g_rnd_st_y2, int g_rnd_sizex, int g_rnd_sizey);
void g_rend_room4(char **g_map, int i, int j, int m_x, int m_y, int g_rnd2_x, int g_rnd2_y);
void g_rend_spawn(char **g_map, int m_x, int m_y);
void g_print_map(char **g_map, int m_x, int m_y);
void g_move_hero(char **g_map, int m_x, int m_y, int g_hero_hp);
void g_move_enemy(char **g_map, int m_x, int m_y);
void g_attack(char **g_map, int g_move_v, int g_move_h, int m_x, int m_y);
void g_print_stats();
void g_chest(char **g_map, int i, int j);
void g_level_success(int score);
void g_game_over(int score);
void g_game_over2();

#endif
