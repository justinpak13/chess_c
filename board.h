#ifndef BOARD_H_
#define BOARD_H_

typedef struct{
	char values[3][3];
	int remaining[9];
	int total_remaining;
}Board;

Board *new_board(void);
void print_board(Board *board);
void print_coordinates();
int validate(Board *board, int coord);
int add_char(Board *board, char c, int i);
int check_winner(Board *board);
int get_random_remaining_value(Board *board);
void board_to_string(Board *board, char *board_string);
Board *string_to_board(char * board_string);

#endif
