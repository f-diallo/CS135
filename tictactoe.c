//Name: tictactoe.c
//Purpose: to generate a game of tic tac toe with functions and user input
//Author: Fatima Diallo

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3


void clear_table(char b[][SIZE]);

void display_table(char b[][SIZE]);

void generate_player2_move(char b[][SIZE], int row, int col);

bool check_end_of_game(char b[][SIZE]);

void get_player1_move(char b[][SIZE], int row, int col);

void print_winner(char b[][SIZE]);


bool check_table_full(char a[][SIZE]);

void update_table(char a[][SIZE], int row, int col, char token);

bool check_legal_option(char a[][SIZE], int row, int col);

bool check_three_in_a_row(char a[][SIZE]);


int main ()
{
 //Declare the tic-tac-toe board
 char board[SIZE][SIZE];
 
//The row and column of the move for either player 1 or 2
 int row, col;

 //Clear the table
 clear_table(board);

 //Display the table
 display_table(board);
 do
 {

 	 //Have player 1 enter their move
 	 get_player1_move(board, row, col);

	 //Generate player 2 move
 	 generate_player2_move(board, row, col);

	//Do this while the game hasn't ended
	}while(check_end_of_game(board) == false);

	 //After the game is over, print who won
 	 print_winner(board);
 return 0;
}




//These functions appear in other functions.
bool check_table_full(char a[][SIZE]){

int i, j, turns=0;

for(i=0; i<(SIZE); i++){
	for(j=0; j<(SIZE); j++){
		if((a[i][j]=='O')||(a[i][j]=='X'))
			turns=turns+1;
}}
if(turns==9)
	return true;
else
	return false;

}
//done^

void update_table(char a[][SIZE], int row, int col, char token)
{

int i,j;

if(token=='X')
	a[row-1][col-1]='X';
else if(token=='O')
	a[row-1][col-1]='O';

for(i=0; i<(SIZE); i++){
	for(j=0; j<(SIZE); j++){
		if((a[i][j] !='O')&&(a[i][j] !='X'))
			a[i][j]='_';
}}
display_table(a);

}
//done^

bool check_legal_option(char a[][SIZE], int row, int col){

if(((row<=SIZE)&&(row>0))||((col<=SIZE)&&(col>0)))
	return true;
else
	return false;

}
//done^

bool check_three_in_a_row(char a[][SIZE]){


if(((a[0][0]=='X')&&(a[0][1]=='X')&&(a[0][2]=='X'))||((a[0][0]=='O')&&(a[0][1]=='O')&&(a[0][2]=='O')))
	return true;
else if(((a[1][0]=='X')&&(a[1][1]=='X')&&(a[1][2]=='X'))||((a[1][0]=='O')&&(a[1][1]=='O')&&(a[1][2]=='O')))
	return true;
else if(((a[2][0]=='X')&&(a[2][1]=='X')&&(a[2][2]=='X'))||((a[2][0]=='O')&&(a[2][1]=='O')&&(a[2][2]=='O')))
	return true;
else if(((a[0][0]=='X')&&(a[1][0]=='X')&&(a[2][0]=='X'))||((a[0][0]=='O')&&(a[1][0]=='O')&&(a[2][0]=='O')))
	return true;
else if(((a[0][1]=='X')&&(a[1][1]=='X')&&(a[2][1]=='X'))||((a[0][1]=='O')&&(a[1][1]=='O')&&(a[2][1]=='O')))
	return true;
else if(((a[0][2]=='X')&&(a[1][2]=='X')&&(a[2][2]=='X'))||((a[0][2]=='O')&&(a[1][2]=='O')&&(a[2][2]=='O')))
	return true;
else if(((a[0][0]=='X')&&(a[1][1]=='X')&&(a[2][2]=='X'))||((a[0][0]=='O')&&(a[1][1]=='O')&&(a[2][2]=='O')))
	return true;
else if(((a[0][2]=='X')&&(a[1][1]=='X')&&(a[2][0]=='X'))||((a[0][2]=='O')&&(a[1][1]=='O')&&(a[2][0]=='O')))
	return true;
else
	return false;

}
//done^


//These functions appear in the main function.

void clear_table(char b[][SIZE])
{
int i,j;

for(i=0; i<(SIZE); i++){
	for(j=0; j<(SIZE); j++){
		b[i][j]='_';
}
}
}
//done^

void display_table(char b[][SIZE])
{
int i, j;
printf("The current state of the game is:\n");
for(i=0; i<(SIZE); i++){
	for(j=0; j<(SIZE); j++){
		printf("%c ", b[i][j]);
	}
	printf("\n");
}
}
//done^


void generate_player2_move(char b[][SIZE], int row, int col)
{

char token='X';

do
{
	rand();
	row=rand() % (SIZE+1);
	col=rand() % (SIZE+1);
	}while(b[row-1][col-1]!= '_');
		printf("Player 2 has entered [row, col]: %d, %d\n", row, col);

update_table(b, row, col, token);
}
//done^

bool check_end_of_game(char b[][SIZE])
{

if((check_three_in_a_row(b)==true)||(check_table_full(b)==true))
	return true;
else
	return false;

}
//done^

void get_player1_move(char b[][SIZE], int row, int col)
{
char token='O';

do
{
	printf("Player 1 enter your selection [row, col]: ");
	scanf("%d, %d", &row, &col);

	}while((check_legal_option(b, row, col))==false);

update_table(b, row, col, token);
}
//done^

void print_winner(char b[][SIZE])
{
if(((b[0][0]=='O')&&(b[0][1]=='O')&&(b[0][2]=='O'))||((b[1][0]=='O')&&(b[1][1]=='O')&&(b[1][2]=='O'))||((b[2][0]=='O')&&(b[2][1]=='O')&&(b[2][2]=='O'))||((b[0][0]=='O')&&(b[1][0]=='O')&&(b[2][0]=='O'))||((b[0][1]=='O')&&(b[1][1]=='O')&&(b[2][1]=='O'))||((b[0][2]=='O')&&(b[1][2]=='O')&&(b[2][2]=='O'))||((b[0][0]=='O')&&(b[1][1]=='O')&&(b[2][2]=='O'))||((b[0][2]=='O')&&(b[1][1]=='O')&&(b[2][0]=='O')))
	printf("Congratulations, Player 1 wins!\n");
else if(((b[0][0]=='X')&&(b[0][1]=='X')&&(b[0][2]=='X'))||((b[1][0]=='X')&&(b[1][1]=='X')&&(b[1][2]=='X'))||((b[2][0]=='X')&&(b[2][1]=='X')&&(b[2][2]=='X'))||((b[0][0]=='X')&&(b[1][0]=='X')&&(b[2][0]=='X'))||((b[0][1]=='X')&&(b[1][1]=='X')&&(b[2][1]=='X'))||((b[0][2]=='X')&&(b[1][2]=='X')&&(b[2][2]=='X'))||((b[0][0]=='X')&&(b[1][1]=='X')&&(b[2][2]=='X'))||((b[0][2]=='X')&&(b[1][1]=='X')&&(b[2][0]=='X')))
	printf("Congratulations, Player 2 wins!\n");
else
	printf("Game over, no player wins.\n");
}
