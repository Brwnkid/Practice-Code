#include <iostream>
#include <cstdlib>

using namespace std;

const int X = 1;
const int O = -1;
const int EMPTY = 0;
const unsigned int BOARD_SIZE = 3;
int board[BOARD_SIZE][BOARD_SIZE];
int currentPlayer;

void clearBoard(){
  for(int i = 0; i < BOARD_SIZE; i++){
    for(int j = 0; j < BOARD_SIZE; j++){
      board[i][j] = EMPTY;
    }
  }
  currentPlayer = X;
}

void putMark(int i, int j){
  board[i][j] = currentPlayer;
  currentPlayer = -currentPlayer;
}

void printBoard(){
  cout << "  1  2  3" << endl;
  for(int i = 0; i < BOARD_SIZE; i++){
    cout << i << " ";
    for(int j = 0; j < BOARD_SIZE; j++){
      if (board[i][j]==X){
        cout << "X";
      }else if(board[i][j]==O){
        cout << "O";
      }else{
        cout << " ";
      }
      if(j < 2){
        cout << "|";
      }
    }
    if(i<2){
      cout << "\n-+-+-\n";
    }
  }
}

int main(){
  printBoard();
}
