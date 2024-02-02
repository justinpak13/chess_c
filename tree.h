#ifndef TREE_H_
#define TREE_H_
#include "board.h"

typedef struct node{
	char board_string[10];
	char current_char;
	struct node *next_nodes[];
	
}node;

node *generate_tree(char *board_string, char prev_char);
node *generate_node(char *board_string, char prev_char);

#endif
