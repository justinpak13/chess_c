#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include <stdbool.h>
#include <time.h>


//need to create tree logic to plan optimal decision based on state of board

int get_input(void){
	int coordinate;
	bool flag = true;
	while (flag){
		printf("Please enter a number (1-9) to select: ");
		scanf("%i", &coordinate);
		if (coordinate >= 1 && coordinate <=9){
			flag = false;
		} else {
			printf("Invalid Input!");
		}
	}
	return coordinate;
}

void play_game(){}

int main(void){

	Board *board = new_board();
	int x;
	int counter = 1;
	char c;
	bool player_is_x;
	char computer_char;
	char player_char;

	srand(time(NULL));
	player_is_x = (rand() % 2 == 0);
	if (player_is_x){
		computer_char = 'O';
		player_char = 'X';
	} else {
		computer_char = 'X';
		player_char = 'O';
	}

	print_coordinates();

	if (player_is_x == false){
		x = get_random_remaining_value(board);
		add_char(board, computer_char, x);
	}
	while (board -> total_remaining > 0){
		print_board(board);

		bool invalid_input_flag = true;
		while (invalid_input_flag){
			x = get_input();

			int check = add_char(board,  player_char, x);
			if (check == 0){
				invalid_input_flag = false;
			}
		}

		if (check_winner(board) == 1){
			printf("X wins!\n");
			break;
		} 

		if (check_winner(board) == -1){
			printf("O wins!\n");
			break;
		} 

		x = get_random_remaining_value(board);
		add_char(board, computer_char, x);

		if (check_winner(board) == 1){
			printf("X wins!\n");
			break;
		} 

		if (check_winner(board) == -1){
			printf("O wins!\n");
			break;
		} 
	}

	if (check_winner(board) == 0){
		printf("Tie Game!\n");
	}


	print_board(board);

	free(board);
	return 0;
}
