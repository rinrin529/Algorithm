#include <iostream>
using namespace std;
int map[17][17] = { 0, };
int mapsize = 0;
int result = 0;
void dfs(int shape, int row, int col) {	// shape: 가로(1) 세로(2) 대각선(3)
	if (shape == 1) {	// 가로
		col = col + 1;
		if (row == mapsize && col == mapsize) {
			result++;
			return;
		}
		if (col + 1 <= mapsize && map[row][col + 1] == 0) {
			dfs(1, row, col); // 가로 이동
		}
		if (col + 1 <= mapsize && row + 1 <= mapsize && map[row + 1][col + 1] == 0 && map[row][col+1]==0 && map[row+1][col]==0) {
			dfs(3, row, col); // 대각선 이동
		}
	}
	else if (shape == 2) {	// 세로
		row = row + 1;
		if (row == mapsize && col == mapsize) {
			result++;
			return;
		}
		if (row + 1 <= mapsize && map[row + 1][col] == 0) {
			dfs(2, row, col); // 세로 이동
		}
		if (col + 1 <= mapsize && row + 1 <= mapsize && map[row + 1][col + 1] == 0 && map[row][col + 1] == 0 && map[row + 1][col] == 0) {
			dfs(3, row, col); // 대각선 이동
		}
	}
	else {
		row += 1;
		col += 1;
		if (row == mapsize && col == mapsize) {
			result++;
			return;
		}
		if (col + 1 <= mapsize && map[row][col + 1] == 0) {
			dfs(1, row, col); // 가로 이동
		}
		if (row + 1 <= mapsize && map[row + 1][col] == 0) {
			dfs(2, row, col); // 세로 이동
		}
		if (col + 1 <= mapsize && row + 1 <= mapsize && map[row + 1][col + 1] == 0 && map[row][col + 1] == 0 && map[row + 1][col] == 0) {
			dfs(3, row, col); // 대각선 이동
		}
	}
}
int main(void) {
	cin >> mapsize;
	for (int i = 1; i <= mapsize; i++) {
		for (int j = 1; j <= mapsize; j++)
			cin >> map[i][j];
	}
	dfs(1, 1, 1);
	cout << result;
	return 0;
}
