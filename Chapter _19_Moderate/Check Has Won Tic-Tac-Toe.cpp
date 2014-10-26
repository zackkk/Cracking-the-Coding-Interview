// '*' empty
// 'X' player 1
// 'O' player 2

#include<iostream>
#include<vector>
using namespace std;

class solution_19_2 {

public:
	bool hasWonTicTacToe(vector<vector<char>> &board, char player){
		// check rows and cols
		for(int i = 0; i < 3; i++){
			int row_count = 0;
			int col_count = 0;
			for(int j = 0; j < 3; j++){
				if(board[i][j] == player) row_count++;
				if(board[j][i] == player) col_count++;
			}
			if(row_count == 3 || col_count == 3) return true;
		}
		// check diagonal
		if(board[1][1] == player){
			if(board[0][0] == player && board[2][2] == player)
				 return true;
			if(board[0][2] == player && board[2][0] == player)
				return true;
		}
		return false;
	}
};
