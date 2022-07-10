#include<stdio.h>

//.......functions we will need.......
void resetBoard();
void printBoard();
int checkFreeSpaces(); // need to return how much spaces are free
void movePlayer();
void moveComputer();
char checkWinner();
void printWinner(char);

// Create  board,  player and computer
char board[3][3]; // tic tac toe frame is like 3X3 matrix
char const COMPUTER='0'; //as its constant
char const USER='X';

void main(){
board [3][3]=' ';
//need to reset the board first before starting a game......>
char winner =' ';
resetBoard();
// print the board until none is winner and freeSpaces != 0
while (winner==' ' && checkFreeSpaces()!=0)
{
   
printBoard();//print the board
movePlayer(); //moving player on the turn of player

winner = checkWinner();//either X or 0 or space will come
if (winner!=' ' && checkFreeSpaces!=0)
{
   break;
}
}

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

// check free spaces 
int checkFreeSpaces(){ //int as need to return the amount of free spaces
int freeSpaces= 9;//initially 3 rows and 3 col = 9 free spaces
for (int i = 1; i <= 3; i++) // 3 rows
{
   for (int j = 1; j <= 3; j++) //3 cols
   {
      if (board[i][j]!=' ') //reduce no of free spaces if board[i][j] have any value
      {
         freeSpaces--;
      }
   } 
}
return freeSpaces;
}
// move player
void movePlayer(){
int row, col;
do{//need to do once either condition false or true
   //ask player whether he/she want to move row and col
printf("Eneter the row {1 to 3} you want to move: ");
scanf("%d",&row);
row--; // as a row of that col is reduced

printf("\n Eneter the column {1 to 3} you want to move of row %d: ", row);
scanf("%d",&col);
col--; //that col of that row is reduced

if (board[row][col]==' ')
{
   board[row][col]=USER;
}
else{
   printf("sorry, move cant be done, place already filled try next \n"); //place already filled
}
}
while (board[row][col]!=' ');
}

void moveComputer(){
   // create a seed based on the current time
   
   srand(time(0));
   int row, col;
   if (checkFreeSpaces()>0)
   {
      do
      {
         row= rand()%3;// get a random row
         col=rand()%3; //get a random col
      } while (board[row][col]!= ' ');
      board[row][col] = COMPUTER;
   }
   else{// no spaces avilable
printWinner(' ');// prints space if no winner
   }
   
}

char checkWinner(){ 
   /*
   check whether the elements of rows and col are equal of X or 0
   if all elements of rows or columns or diagonal are X then USER wins else if 0 COMPUTER wins else none will win
   */
  for (int row = 0; row < 3; row++)//check for row
  {
   if (board[row][0]==board[row][1] && board[row][0]==board[row][2]){
      return board[row][0];// that will return either X or 0
   }
  }
  for (int col = 0; col < 3; col++){// check on column
   if (board[0][col]==board[1][col] && board[0][col]==board[2][col]){
      return board[0][col];// that will print the element on the column 0 of row 0
   }
  }
   //for diagonals---> where value of row and colum is equal >> principal diagonal
 if (board[0][0]==board[1][1] && board[0][0]==board[2][2]){
      return board[0][0];// that will print the element on the column 0 of row 0
   }
   // for side diagonal where row+col = even on 3X3 
    if (board[0][2]==board[1][1] && board[0][2]==board[2][0]){
      return board[0][2];// that will print the element on the column 2 of row 0
   }
return ' ';// return space if none matches means for empty ones
}