#ifndef TREE_H_
#define TREE_H_
#include "board.h"
#include <stdbool.h>

typedef struct node{
	char board_string[10];
	char current_char;
	struct node *next_nodes[];
	
}node;

node *generate_tree(char *board_string, char prev_char);
node *generate_node(char *board_string, char prev_char);
void free_tree(node *beginning);
int evaluate_node(node *current_node);
int get_number_of_next_nodes(node *current_node);
int minimax(node *current_node, bool maximizing_player);
int get_next_move(node *current_node, bool maximizing_player);

#endif
