#include<stdio.h>

//.......functions we will need.......
void resetBoard();
void printBoard();
int checkFreeSpaces(); // need to return how much spaces are free
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

// Create  board,  player and computer
char board[3][3]; // tic tac toe frame is like 3X3 matrix
char const COMPUTER='0'; //as its constant
char const USER='X';

void main(){
board [3][3]=' ';
//need to reset the board first before starting a game......>
resetBoard();
printBoard();//print the board

}

// adding reset functionalities to resetBoard()
// to reset a board should be empty for that we will store spaces on each index of the array
void resetBoard(){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){ //as row and column will be three loop goes till 3
            board[3][3]=' ';
        }
        
    }
}
//printing the board
void printBoard(){
/* board should be printed with the values and horizontal and vetical perpendicular lines like
   |   |   
---|---|---
   |   |   
---|---|---
   |   |  
*/

printf("  %c | %c  | %c ", board[0][0],board[0][1], board[0][2]);
printf("\n---|---|---\n");

printf("  %c | %c  | %c ", board[1][0],board[1][1], board[1][2]);
printf("\n---|---|---\n");

printf("  %c | %c  | %c ", board[2][0],board[2][1], board[2][2]);
   printf("\n");
}