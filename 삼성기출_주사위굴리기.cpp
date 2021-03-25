#include <iostream>
#include <algorithm>
using namespace std;
int dice[7] = { 0, };
void move_dice(int dir) {
	int temp[7] = { 0, };
	copy(dice, dice + 7, temp);
	if (dir == 1) {	// 동쪽
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (dir == 2) {	// 서쪽
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[4] = temp[1];
		dice[6] = temp[4];
	}
	else if (dir == 3) {	// 북쪽
		dice[1] = temp[5];
		dice[2] = temp[1];
		dice[5] = temp[6];
		dice[6] = temp[2];
	}
	else {	// 남쪽
		dice[1] = temp[2];
		dice[2] = temp[6];
		dice[5] = temp[1];
		dice[6] = temp[5];
	}
}
int main(void) {
	int n = 0, m = 0, row = 0, col = 0, k = 0;
	int map[21][21] = { 0, };
	cin >> n >> m >> row >> col >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int dir = 0;
	for (int i = 0; i < k; i++) {
		cin >> dir;
		if (dir == 1)
			col += 1;
		else if (dir == 2)
			col -= 1;
		else if (dir == 3)
			row -= 1;
		else
			row += 1;
		if (row >= 0 && row < n && col >= 0 && col < m) {
			move_dice(dir);
			if (map[row][col] == 0) {
				map[row][col] = dice[6];
			}
			else {
				dice[6] = map[row][col];
				map[row][col] = 0;
			}
			cout << dice[1] << endl;
		}
		else {	// 범위를 벗어난 경우 좌표 이동 원상복구
			if (dir == 1)
				col -= 1;
			else if (dir == 2)
				col += 1;
			else if (dir == 3)
				row += 1;
			else
				row -= 1;
		}
	}
	return 0;
}
