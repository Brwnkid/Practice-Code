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
  currentPlayer = O;
}

bool putMark(int i, int j){
  if (board[i][j] == EMPTY){
    board[i][j] = currentPlayer;
    return true;
  }
  return false;
}

bool isWinner(int currentPlayer){
  int win = currentPlayer*3;
  if(board[0][0] + board[0][1] + board [0][2] == win){ return true;}
  else if(board[1][0] + board[1][1] + board [1][2] == win){ return true;}
  else if(board[2][0] + board[2][1] + board [2][2] == win){ return true;}
  else if(board[0][0] + board[1][0] + board [2][0] == win){ return true;}
  else if(board[0][1] + board[1][1] + board [2][1] == win){ return true;}
  else if(board[0][2] + board[1][2] + board [2][2] == win){ return true;}
  else if(board[0][0] + board[1][1] + board [2][2] == win){ return true;}
  else if(board[0][2] + board[1][1] + board [2][0] == win){ return true;}
  return false;
}

void printBoard(){
  cout << "  0 1 2" << endl;
  for(int i = 0; i < BOARD_SIZE; i++){
    cout << i << " ";
    for(int j = 0; j < BOARD_SIZE; j++){
      if(board[i][j]==X){
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
      cout << "\n  -+-+-\n";
    }
  }
  cout << endl;
}

int main(){
  clearBoard();
  bool win = false;
  int row; int col;
  while(!win){
    currentPlayer = -currentPlayer;
    printBoard();
    cout << "Current Player: ";
    if(currentPlayer == 1){
      cout << "X" << endl;
    }else{
      cout << "O" << endl;
    }
    cout << "Which row do you want to mark? ";
    cin >> row;
    while(row > 2 || row < 0){
      cout << "Invalid row. Please enter a row(0-2): ";
      cin >> row;      
    }
    cout << "Which column do you want to mark? ";
    cin >> col;
    while(col > 2 || col < 0){
      cout << "Invalid column. Please enter a row(0-2): ";
      cin >> col;      
    }
    while(!putMark(row,col)){
      printBoard();
      cout << "Invalid entry. There is already a mark in that location." << endl;
          cout << "Which row do you want to mark? ";
      cin >> row;
      while(row > 2 || row < 0){
        cout << "Invalid row. Please enter a row(0-2): ";
        cin >> row;      
      }
      cout << "Which column do you want to mark? ";
      cin >> col;
      while(col > 2 || col < 0){
        cout << "Invalid column. Please enter a row(0-2): ";
        cin >> col;      
      }
    }
    win = isWinner(currentPlayer);
  }
  printBoard();
  cout << "Congratulations Player ";
  if(currentPlayer == 1){
    cout << "X. You win!" << endl;
  }else{
    cout << "O. You win!" << endl;
  }

}
