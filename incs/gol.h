#ifndef GOL_H
#define GOL_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <signal.h>

#define MAX_ITEMS 100

#define MAX_LINE_LENGTH 1024

int **init_array(int num_rows, int num_cols);
void seed_array(int **arr, int num_rows, int num_cols);
void check_alive(int **map, int **buffer, int num_rows, int num_cols);
bool check_neigbours(int **map, int i, int j, int num_rows, int num_cols);
void copy_buffer(int **map, int **buffer, int num_rows, int num_cols);
void display_game(int **map, int num_cols, int num_rows);
void parse_file_to_2d_array(const char *file_path, int ***array, int *rows, int *cols);

#endif