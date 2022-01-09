#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> board)
{
	int row_size = board.size();
	int col_size = board[0].size();
	int answer = 0;
    if(row_size == 1 || col_size == 1){
        for(int i=0; i<row_size; i++){
            for(int j=0; j<col_size; j++){
                if(board[i][j]==1){
                    return 1;
                }
            }
        }
        return 0;
    }
	for (int row = 1; row < row_size; row++) {
		for (int col = 1; col < col_size; col++) {
			if (board[row][col] > 0) {
				board[row][col] = min(board[row][col - 1], min(board[row - 1][col], board[row - 1][col - 1])) + 1;
				answer = max(answer, board[row][col]);
			}
		}
	}
	return (answer*answer);
}
