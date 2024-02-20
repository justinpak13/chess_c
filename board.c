#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "board.h"

Board *new_board(void){
	Board *board = malloc(sizeof(Board));
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			board -> values[i][j] = ' ';
		}
	}

	for (int i = 0; i < 9; i++){
		board -> remaining[i] = i + 1;
	}

	board -> total_remaining = 9;

	return board;
}

void board_to_string(Board *board, char *board_string){
	int counter = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			board_string[counter] = board ->values[i][j];
		}
	}
}

Board *string_to_board(char * board_string){
	Board *result = new_board();


	for (int i = 0; i < 9; i++){
		if (board_string[1] != ' '){
			add_char(result, board_string[i], i+1);
		}
	}


	return result;
}

void print_board(Board *board){
	for (int i = 0; i < 3; i++){
		printf("|");
		for (int j = 0; j < 3; j++){
			printf("%c", board -> values[i][j]);
			printf("|");
		}
		printf("\n-------\n");
	}

}

void print_coordinates(){
	printf("|1|2|3|\n");
	printf("|4|5|6|\n");
	printf("|7|8|9|\n");
}

int validate(Board *board, int coord){
	if (coord < 1){
		return 1;
	}

	if (coord > 9){
		return 1;
	}

	const int NUMBER_OF_CHOICES = 9;
	for (int i = 0; i < NUMBER_OF_CHOICES; i++){
		if (board -> remaining[i] == coord){
			// is a valid choice 
			//board -> remaining[i] = 0;
			return 0;
		}
	}
	
	// i was not a valid choice
	return 2;

}

int add_char(Board *board, char c, int i){
	if (validate(board, i) != 0) {
		printf("That space is already taken\n");
		return 1;
	}
	int x;
	int y;
	switch(i){
		case 1:
			x = 0;
			y = 0;
			break;
		case 2:
			x = 1;
			y = 0;
			break;
		case 3:
			x = 2;
			y = 0;
			break;
		case 4:
			x = 0;
			y = 1;
			break;
		case 5:
			x = 1;
			y = 1;
			break;
		case 6:
			x = 2;
			y = 1;
			break;
		case 7:
			x = 0;
			y = 2;
			break;
		case 8:
			x = 1;
			y = 2;
			break;
		case 9:
			x = 2;
			y = 2;
			break;
	}
	board -> values[y][x] = c;
	if (c != ' ') {

		board -> total_remaining -= 1;
	}

	board -> remaining[i-1] = 0;
	return 0;
}

int check_winner(Board *board){
	// no winner = 0
	// x wins = 1 
	// o wins = -1
	
	// checking left and right
	if (board -> values[0][0] == board -> values[0][1] 
		&& board -> values[0][1] == board ->values[0][2]
		&& board -> values[0][2] != ' '){
		if ((board -> values[0][2]) == 'X'){
			return 1;
		} else {
			return -1;
		}
	} 

	if (board -> values[1][0] == board -> values[1][1] 
		&& board -> values[1][1] == board ->values[1][2]
		&& board -> values[1][2] != ' '){
		if ((board -> values[1][2]) == 'X'){
			return 1;
		} else {
			return -1;
		}
	} 

	if (board -> values[2][0] == board -> values[2][1] 
		&& board -> values[2][1] == board ->values[2][2]
		&& board -> values[2][2] != ' '){
		if ((board -> values[2][2]) == 'X'){
			return 1;
		} else {
			return -1;
		}
	} 

	// checking up and down
	if (board -> values[0][0] == board -> values[1][0] 
		&& board -> values[1][0] == board -> values[2][0]
		&& board -> values[2][0] != ' '){
		if (board -> values[2][0] == 'X'){
			return 1;
		} else {
			return -1;
		}
	}

	if (board -> values[0][1] == board -> values[1][1] 
		&& board -> values[1][1] == board -> values[2][1]
		&& board -> values[2][1] != ' '){
		if (board -> values[2][1] == 'X'){
			return 1;
		} else {
			return -1;
		}
	}

	if (board -> values[0][2] == board -> values[1][2] 
		&& board -> values[1][2] == board -> values[2][2]
		&& board -> values[2][2] != ' '){
		if (board -> values[2][2] == 'X'){
			return 1;
		} else {
			return -1;
		}
	}

	// checking both diagonals
	if (board -> values[0][0] == board -> values[1][1] 
		&& board -> values[1][1] == board -> values[2][2]
		&& board -> values[2][2] != ' '){
		if (board -> values[2][2] == 'X'){
			return 1;
		} else {
			return -1;
		}
	}
	
	if (board -> values[0][2] == board -> values[1][1] 
		&& board -> values[1][1] == board -> values[2][0]
		&& board -> values[2][0] != ' '){
		if (board -> values[2][0] == 'X'){
			return 1;
		} else {
			return -1;
		}
	}
	return 0;
}

int get_random_remaining_value(Board *board){
	srand(time(NULL));
	int counter = 0;
	int array[9];

	for (int i = 0; i < 9; i++){
		if (board -> remaining[i] != 0){
			array[counter] = board -> remaining[i];
			counter++;
		}
	}

	if (counter == 0){
		return 1;
	}

	int rand_value = array[(rand() % counter)];

	return rand_value;

}
