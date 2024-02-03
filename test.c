#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include <stdbool.h>
#include "tree.h"

int test_accross(){
	Board *test_board = new_board();
	add_char(test_board, 'X', 1);
	add_char(test_board, 'X', 2);
	add_char(test_board, 'X', 3);

	if (check_winner(test_board) != 1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 1);
	add_char(test_board, 'O', 2);
	add_char(test_board, 'O', 3);

	if (check_winner(test_board) != -1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 1);
	add_char(test_board, 'X', 2);
	add_char(test_board, 'O', 3);

	if (check_winner(test_board) != 0){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'X', 4);
	add_char(test_board, 'X', 5);
	add_char(test_board, 'X', 6);

	if (check_winner(test_board) != 1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 4);
	add_char(test_board, 'O', 5);
	add_char(test_board, 'O', 6);

	if (check_winner(test_board) != -1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 4);
	add_char(test_board, 'X', 5);
	add_char(test_board, 'O', 6);

	if (check_winner(test_board) != 0){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'X', 7);
	add_char(test_board, 'X', 8);
	add_char(test_board, 'X', 9);

	if (check_winner(test_board) != 1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 7);
	add_char(test_board, 'O', 8);
	add_char(test_board, 'O', 9);

	if (check_winner(test_board) != -1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 7);
	add_char(test_board, 'X', 8);
	add_char(test_board, 'O', 9);

	if (check_winner(test_board) != 0){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	printf("Test Passed\n");
	return 0;
}

int test_vertical(){
	Board *test_board = new_board();
	add_char(test_board, 'X', 1);
	add_char(test_board, 'X', 4);
	add_char(test_board, 'X', 7);

	if (check_winner(test_board) != 1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 1);
	add_char(test_board, 'O', 4);
	add_char(test_board, 'O', 7);

	if (check_winner(test_board) != -1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 1);
	add_char(test_board, 'X', 4);
	add_char(test_board, 'O', 7);

	if (check_winner(test_board) != 0){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'X', 2);
	add_char(test_board, 'X', 5);
	add_char(test_board, 'X', 8);

	if (check_winner(test_board) != 1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 2);
	add_char(test_board, 'O', 5);
	add_char(test_board, 'O', 8);

	if (check_winner(test_board) != -1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 2);
	add_char(test_board, 'X', 5);
	add_char(test_board, 'O', 8);

	if (check_winner(test_board) != 0){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'X', 3);
	add_char(test_board, 'X', 6);
	add_char(test_board, 'X', 9);

	if (check_winner(test_board) != 1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 3);
	add_char(test_board, 'O', 6);
	add_char(test_board, 'O', 9);

	if (check_winner(test_board) != -1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 3);
	add_char(test_board, 'X', 6);
	add_char(test_board, 'O', 9);

	if (check_winner(test_board) != 0){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	printf("Test Passed\n");
	return 0;
}

int test_diagonal(){
	Board *test_board = new_board();
	add_char(test_board, 'X', 1);
	add_char(test_board, 'X', 5);
	add_char(test_board, 'X', 9);

	if (check_winner(test_board) != 1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 1);
	add_char(test_board, 'O', 5);
	add_char(test_board, 'O', 9);

	if (check_winner(test_board) != -1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 1);
	add_char(test_board, 'X', 5);
	add_char(test_board, 'O', 9);

	if (check_winner(test_board) != 0){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'X', 3);
	add_char(test_board, 'X', 5);
	add_char(test_board, 'X', 7);

	if (check_winner(test_board) != 1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 3);
	add_char(test_board, 'O', 5);
	add_char(test_board, 'O', 7);

	if (check_winner(test_board) != -1){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	test_board = new_board();
	add_char(test_board, 'O', 3);
	add_char(test_board, 'X', 5);
	add_char(test_board, 'O', 7);

	if (check_winner(test_board) != 0){
		printf("test_accross Test failed");
		return 1;

	}

	free(test_board);

	printf("Test Passed\n");
	return 0;
}



int test_string_to_board(){
	char test[10] = {'O','X','X','X','X','X','X','X','O','\0'};
	Board *board_test = string_to_board(test);

	print_board(board_test);


	return 0;
}

int test_generate_node(){
	char test[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'};
	Board *board_test = string_to_board(test);

	node *test_node = generate_node(test, 'X');

	free_tree(test_node);
	free(board_test);

	return 0;
}

int test_evaluate_node(){
	char test[10] = {'X','O',' ','X',' ','O',' ','O',' ','\0'};
	Board *board_test = string_to_board(test);

	node *test_node = generate_node(test, 'O');

	int number_of_nodes = get_number_of_next_nodes(test_node);
	int temp;
	for (int i = 0; i < number_of_nodes; i++){
		temp = minimax(test_node -> next_nodes[i], true);
		printf("%s %i\n", test_node -> next_nodes[i] -> board_string, temp);
	}


	free_tree(test_node);
	free(board_test);
	return 0;
}

int test_minimax(){
	char test[10] = {' ','O',' ',
		         ' ',' ','X',
	                 'X','O',' ','\0'};
	Board *board_test = string_to_board(test);

	node *test_node = generate_node(test, 'O');


	printf("%i\n",get_next_move(test_node, true));

	free_tree(test_node);
	free(board_test);
	return 0;

}


int main(void){

	test_minimax();
	//test_evaluate_node();
	test_generate_node();
	int counter = 0;
	counter += test_accross();
	counter += test_vertical();
	counter += test_diagonal();

	if (counter == 0){
		printf("All Tests Passed");
		return 0;
	} 


	return 1;
}



