#include <iostream>
using namespace std;
int map[10][10] = { 0, };
int flower[10][10] = { 0, };
int n = 0;
int answer = 160000;
void dfs(int row, int col, int count, int money) {
	
	count++;
	money += (map[row + 1][col] + map[row - 1][col] + map[row][col + 1] + map[row][col - 1] + map[row][col]);
	if (count == 3) {
		if (money < answer)
			answer = money;
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (flower[i][j] == 0 && flower[i + 1][j] == 0 && flower[i - 1][j] == 0 && flower[i][j + 1] == 0 && flower[i][j - 1] == 0) {
				flower[i + 1][j] = 1;
				flower[i - 1][j] = 1;
				flower[i][j + 1] = 1;
				flower[i][j - 1] = 1;
				flower[i][j] = 1;
				dfs(i, j, count, money);
				flower[i + 1][j] = 0;
				flower[i - 1][j] = 0;
				flower[i][j + 1] = 0;
				flower[i][j - 1] = 0;
				flower[i][j] = 0;
			}
		}
	}
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			flower[i + 1][j] = 1;
			flower[i - 1][j] = 1;
			flower[i][j + 1] = 1;
			flower[i][j - 1] = 1;
			flower[i][j] = 1;
			dfs(i, j, 0, 0);
			flower[i + 1][j] = 0;
			flower[i - 1][j] = 0;
			flower[i][j + 1] = 0;
			flower[i][j - 1] = 0;
			flower[i][j] = 0;
		}
	}
	cout << answer;
	return 0;
}
