#include <iostream>
#include <vector>
using namespace std;
int r = 0, c = 0, m = 0;
vector<vector<int>> map[102][102];
int dir_r[5] = { 0, -1,1,0,0 };
int dir_c[5] = { 0, 0,0,1,-1 };
int dir_change[5] = { 0,2,1,4,3 };

void move_shark() {
	vector<vector<int>> temp[102][102];
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (!map[i][j].empty()) {
				int dir = map[i][j][0][1];
				int new_row = i + (map[i][j][0][0] * dir_r[map[i][j][0][1]]);
				int new_col = j + (map[i][j][0][0] * dir_c[map[i][j][0][1]]);
				while (1) {
					if (new_row > r) {
						new_row = (2 * r) - new_row;
						dir = dir_change[dir];
					}
					else if (new_row < 1) {
						new_row = -(new_row) + 2;
						dir = dir_change[dir];
					}
					else {
						break;
					}
				}
				while (1) {
					if (new_col > c) {
						new_col = (2 * c) - new_col;
						dir = dir_change[dir];
					}
					else if (new_col < 1) {
						new_col = -(new_col) + 2;
						dir = dir_change[dir];
					}
					else {
						break;
					}
				}
				if (temp[new_row][new_col].empty()) {
					temp[new_row][new_col].push_back({ map[i][j][0][0],dir, map[i][j][0][2] });
				}
				else {	// 잡아먹는다
					if (temp[new_row][new_col][0][2] < map[i][j][0][2]) {
						temp[new_row][new_col].clear();
						temp[new_row][new_col].push_back({ map[i][j][0][0],dir, map[i][j][0][2] });
					}
				}
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			map[i][j].clear();
			if (!temp[i][j].empty()) {
				map[i][j] = temp[i][j];
			}
		}
	}
}

int main(void) {
	cin >> r >> c >> m;
	int sr = 0, sc = 0, s = 0, d = 0, z = 0;
	for (int i = 0; i < m; i++) {
		cin >> sr >> sc >> s >> d >> z;
		map[sr][sc].push_back({ s,d,z });
	}
	int answer = 0;
	if (m > 0) {
		for (int col = 1; col <= c; col++) {
			for (int row = 1; row <= r; row++) {
				if (!map[row][col].empty()) {
					answer += map[row][col][0][2];
					map[row][col].clear();
					break;
				}
			}
			move_shark();
		}
	}
	cout << answer;
	return 0;
 }
