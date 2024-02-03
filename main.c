#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "tree.h"


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

	int x;
	int y;
	int counter = 1;
	char c;
	bool player_is_x;
	bool is_maximizing_player;
	char computer_char;
	char player_char;
	char board_string[10] = {' ',' ',' ',
	                         ' ',' ',' ',
	                         ' ',' ',' ', '\0'};

	Board *board = string_to_board(board_string);



	srand(time(NULL));
	player_is_x = (rand() % 2 == 0);
	if (player_is_x){
		computer_char = 'O';
		player_char = 'X';
		is_maximizing_player = false;
	} else {
		computer_char = 'X';
		player_char = 'O';
		is_maximizing_player = true;
	}

	print_coordinates();

	if (player_is_x == false){
		
		node *current_node = generate_node(board_string, player_char);
		x = get_next_move(current_node, is_maximizing_player, board);
		free_tree(current_node);

		add_char(board, computer_char, x);

		char temp[10];
		
		int counter = 0; 
		for (int i = 0; i < 3; i++){
			for (int j = 0; j <3; j++){
				temp[counter] = board -> values[i][j];
				counter++;
			}
		}
		temp[9] = '\0';
		strcpy(board_string, temp);


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

			char temp[10];
			
			int counter = 0; 
			for (int i = 0; i < 3; i++){
				for (int j = 0; j <3; j++){
					temp[counter] = board -> values[i][j];
					counter++;
				}
			}
			temp[9] = '\0';
			strcpy(board_string, temp);

		}

		if (check_winner(board) == 1){
			printf("X wins!\n");
			break;
		} 

		if (check_winner(board) == -1){
			printf("O wins!\n");
			break;
		} 


		node *current_node = generate_node(board_string, player_char);
		x = get_next_move(current_node, is_maximizing_player, board);


		free_tree(current_node);

		add_char(board, computer_char, x);
		char temp[10];
		
		int counter = 0; 
		for (int i = 0; i < 3; i++){
			for (int j = 0; j <3; j++){
				temp[counter] = board -> values[i][j];
				counter++;
			}
		}
		temp[9] = '\0';
		strcpy(board_string, temp);
		

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
