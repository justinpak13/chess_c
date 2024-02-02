#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"


node *generate_node(char *board_string, char prev_char){
	Board *tmp_board = string_to_board(board_string);
	if (tmp_board->total_remaining < 0){
		printf("No spaces available\n");
		return NULL;
	}


	int number_of_leaves = tmp_board -> total_remaining;
	node *result_node = malloc(sizeof(node) + number_of_leaves * sizeof(node *));
	strcpy(result_node -> board_string, board_string);
	if (prev_char == 'X'){
		result_node -> current_char = 'O';
	} else {
		result_node -> current_char = 'X';
	}

	int current = 0;
	for (int i = 0; i < 9; i++){
		if (board_string[i] == ' '){
			char tmp_string[10];
			board_string[i] = result_node -> current_char;
			strcpy(tmp_string, board_string);
			board_string[i] = ' ';
			node *tmp_node = generate_node(tmp_string, result_node -> current_char);
			if (tmp_node != NULL){
				strcpy(tmp_node -> board_string, tmp_string); 
				result_node -> next_nodes[current] = tmp_node;
				current++;
			}
		}

	}


	free(tmp_board);
	return result_node;
}

node *generate_tree(char *board_string, char prev_char){




}


