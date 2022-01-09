#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dir_r[4] = { -1,0,1,0 };
int dir_c[4] = { 0,1,0,-1 };
int r = 0, c = 0, t = 0;
int map[51][51] = { 0, };
queue <pair<int, int>> dust;
vector <int> cleaner;
void Spread_dust() {
	int temp_map[51][51] = { 0, };
	int size = dust.size();
	while (!dust.empty()) {
		int count = 0;
		int row = dust.front().first;
		int col = dust.front().second;
		int spread = map[row][col] / 5;
		for (int k = 0; k < 4; k++) {
			int new_r = row + dir_r[k];
			int new_c = col + dir_c[k];
			if (new_r >= 0 && new_r < r && new_c >= 0 && new_c < c) {
				if (map[new_r][new_c] != -1) {
					temp_map[new_r][new_c] += (spread);
					count++;
				}
			}
		}
		dust.pop();
		map[row][col] -= (spread*count);
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] += temp_map[i][j];
		}
	}
}
void Cycle_air() {
	int cl_r = cleaner[0];
	for (int row = cl_r; row > 0; row--) {
		if (map[row][0] != -1) {
			map[row][0] = map[row - 1][0];
		}
	}
	for (int col = 0; col < c - 1; col++) {
		if (map[0][col] != -1) {
			map[0][col] = map[0][col + 1];
		}
	}
	for (int row = 0; row < cl_r; row++) {
		map[row][c-1] = map[row + 1][c-1];
	}
	for (int col = c-1; col >=2; col--) {
		map[cl_r][col] = map[cl_r][col - 1];
	}
	map[cl_r][1] = 0;
	cl_r += 1;
	for (int row = cl_r; row < r-1; row++) {
		if (map[row][0] != -1) {
			map[row][0] = map[row + 1][0];
		}
	}
	for (int col = 0; col < c - 1; col++) {
		if (map[r - 1][col] != -1) {
			map[r - 1][col] = map[r - 1][col + 1];
		}
	}
	for (int row = r-1; row > cl_r; row--) {
		map[row][c - 1] = map[row - 1][c - 1];
	}
	for (int col = c - 1; col >= 2; col--) {
		map[cl_r][col] = map[cl_r][col - 1];
	}
	map[cl_r][1] = 0;
}
int main(void) {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) {
				dust.push(make_pair(i, j));
			}
			if (map[i][j] == -1) {
				cleaner.push_back(i);
			}
		}
	}
	for (int i = 0; i < t; i++) {
		Spread_dust();
		Cycle_air();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] > 0) {
					dust.push(make_pair(i, j));
				}
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] > 0) {
				answer += map[i][j];
			}
		}
	}
	cout << answer;
	return 0;
}
