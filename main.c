#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "tree.h"
#include "raylib.h"


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


	// Initialization of raylib window 
	// -------------------------------------------------------------------
	const int screenWidth = 600;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "TicTacToe");

	bool player_turn = true;
	while (!WindowShouldClose()){
		BeginDrawing();
		ClearBackground(RAYWHITE);
		
		//vertical lines
		DrawLineV((Vector2){(float)200, 0}, (Vector2) {(float)200, (float)screenHeight}, BLACK);
		DrawLineV((Vector2){(float)400, 0}, (Vector2) {(float)400, (float)screenHeight}, BLACK);

		// horizontal lines
		DrawLineV((Vector2){(float)0, 200}, (Vector2) {(float)screenWidth, (float)200}, BLACK);
		DrawLineV((Vector2){(float)0, 400}, (Vector2) {(float)screenWidth, (float)400}, BLACK);

		if (check_winner(board) == 1){
			DrawText("X wins!", 250, 300, 50, BLACK);
		} else if (check_winner(board) == -1){
			DrawText("O wins!", 250, 300, 50, BLACK);
		} else if (board -> total_remaining == 0){
			DrawText("TIE GAME", 250, 300, 50, BLACK);
		}


		for (int i = 0; i < 9; i++){
			if (board_string[i] != ' '){
			    if (i == 0){
				if (board_string[i] == 'O'){
					DrawCircleLines(100, 100, 75, RED);
					} else {
					DrawLine(30, 30, 170, 170, BLUE);
					DrawLine(170, 30, 30, 170, BLUE);
					}
			    }
			    if (i == 1){
				if (board_string[i] == 'O'){
					DrawCircleLines(300, 100, 75, RED);
					} else {
					DrawLine(230, 30, 370, 170, BLUE);
					DrawLine(370, 30, 230, 170, BLUE);
					}

			    }
			    if (i == 2){
				if (board_string[i] == 'O'){
				DrawCircleLines(500, 100, 75, RED);
					} else {
				DrawLine(430, 30, 570, 170, BLUE);
				DrawLine(570, 30, 430, 170, BLUE);
					}
			    }

			    if (i == 3){
				if (board_string[i] == 'O'){
				DrawCircleLines(100, 300, 75, RED);
					} else {
				DrawLine(30, 230, 170, 370, BLUE);
				DrawLine(170, 230, 30, 370, BLUE);
					}
			    }
			    if (i == 4){
				if (board_string[i] == 'O'){
				DrawCircleLines(300, 300, 75, RED);
					} else {
				DrawLine(230, 230, 370, 370, BLUE);
				DrawLine(370, 230, 230, 370, BLUE);
					}
			    }
			    if (i == 5){
				if (board_string[i] == 'O'){
				DrawCircleLines(500, 300, 75, RED);
					} else {
				DrawLine(430, 230, 570, 370, BLUE);
				DrawLine(570, 230, 430, 370, BLUE);
					}
			    }
			    if (i == 6){
				if (board_string[i] == 'O'){
				DrawCircleLines(100, 500, 75, RED);
					} else {
				DrawLine(30, 430, 170, 570, BLUE);
				DrawLine(170, 430, 30, 570, BLUE);
					}
			    }
			    if (i == 7){
				if (board_string[i] == 'O'){
				DrawCircleLines(300, 500, 75, RED);
					} else {
				DrawLine(230, 430, 370, 570, BLUE);
				DrawLine(370, 430, 230, 570, BLUE);
					}
			    }
			    if (i == 8){
				if (board_string[i] == 'O'){
				DrawCircleLines(500, 500, 75, RED);
					} else {
				DrawLine(430, 430, 570, 570, BLUE);
				DrawLine(570, 430, 430, 570, BLUE);
					}
			    }

			}
			
		}

		int input = 0;
		if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && check_winner(board) == 0 && board -> total_remaining > 0){
			x = GetMouseX();
			y = GetMouseY();
			
			if (x < 200){
			    if (y < 200){
				input = 1;
			    } else if (y < 400){
				input = 4;
			    } else {
				input = 7;
			    }
			} else if (x < 400){
			    if (y < 200){
				input = 2;
			    } else if (y < 400){
				input = 5;
			    } else {
				input = 8;
			    }
			} else {
			    if (y < 200){
				input = 3;
			    } else if (y < 400){
				input = 6;
			    } else {
				input = 9;
			    }
			}

		
			if (validate(board, input) == 0){
				add_char(board, player_char, input);
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

				//if (check_winner(board) == 1){
				//	printf("X wins!\n");
				//	break;
				//} 

				//if (check_winner(board) == -1){
				//	printf("O wins!\n");
				//	break;
				//} 

				//if (board -> total_remaining == 0){
				//	break;
				//}

				if (check_winner(board) == 0 && board -> total_remaining > 0){
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
					

					//if (check_winner(board) == 1){
					//	printf("X wins!\n");
					//	break;
					//} 

					//if (check_winner(board) == -1){
					//	printf("O wins!\n");
					//	break;
					//} 

					//if (board -> total_remaining == 0){
					//	break;
					//}
				}


			}

		}



		


		EndDrawing();
	}

	CloseWindow();
	free(board);
	return 0;
}
		//int input = 0;
		//while (input == 0){
		//	if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
		//		x = GetMouseX();
		//		y = GetMouseY();
		//		
		//		if (x < 200){
		//		    if (y < 200){
		//			input = 1;
		//		    } else if (y < 400){
		//			input = 4;
		//		    } else {
		//			input = 7;
		//		    }
		//		} else if (x < 400){
		//		    if (y < 200){
		//			input = 2;
		//		    } else if (y < 400){
		//			input = 5;
		//		    } else {
		//			input = 8;
		//		    }
		//		} else {
		//		    if (y < 200){
		//			input = 3;
		//		    } else if (y < 400){
		//			input = 6;
		//		    } else {
		//			input = 9;
		//		    }
		//		}
		//	}
		//}
		//add_char(board, player_char, input);

		//bool invalid_input_flag = true;
		//while (invalid_input_flag){
		//	int input = 0;
		//		
		//		    }

		//	}
		//	if (input != 0){
		//		int check = add_char(board,  player_char, x);
		//		if (check == 0){
		//			invalid_input_flag = false;
		//		}
		//	}
		//}

		//		char temp[10];
		//		
		//		int counter = 0; 
		//		for (int i = 0; i < 3; i++){
		//			for (int j = 0; j <3; j++){
		//				temp[counter] = board -> values[i][j];
		//				counter++;
		//			}
		//		}
		//		temp[9] = '\0';
		//		strcpy(board_string, temp);
		//	}


		//}


		//if (check_winner(board) == 1){
		//	printf("X wins!\n");
		//	break;
		//} 

		//if (check_winner(board) == -1){
		//	printf("O wins!\n");
		//	break;
		//} 

		//if (board -> total_remaining == 0){
		//	break;
		//}


		//node *current_node = generate_node(board_string, player_char);
		//x = get_next_move(current_node, is_maximizing_player, board);


		//free_tree(current_node);

		//add_char(board, computer_char, x);
		//char temp[10];
		//
		//int counter = 0; 
		//for (int i = 0; i < 3; i++){
		//	for (int j = 0; j <3; j++){
		//		temp[counter] = board -> values[i][j];
		//		counter++;
		//	}
		//}
		//temp[9] = '\0';
		//strcpy(board_string, temp);
		//

		//if (check_winner(board) == 1){
		//	printf("X wins!\n");
		//	break;
		//} 

		//if (check_winner(board) == -1){
		//	printf("O wins!\n");
		//	break;
		//} 

		//if (board -> total_remaining == 0){
		//	break;
		//}
		//}

	//if (check_winner(board) == 0){
	//	printf("Tie Game!\n");
	//}
