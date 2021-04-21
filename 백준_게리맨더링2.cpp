#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n = 0;
int map[21][21] = { 0, };
int tmp_map[21][21] = { 0, };
int answer = 999999999;

void count_number() {
	int min_a = 999999999, max_a = -1;
	int arr[6] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num = tmp_map[i][j];
			arr[num] += map[i][j];
		}
	}
	for (int i = 1; i <= 5; i++) {
		min_a = min(min_a, arr[i]);
		max_a = max(max_a, arr[i]);
	}
	if ((max_a - min_a) < answer) {
		answer = (max_a - min_a);
	}
}

void make_other_side(int x, int y, int d1, int d2) {
	for (int row = 1; row < x + d1; row++) {
		for (int col = 1; col <= y; col++) {
			if (tmp_map[row][col] == 0) {
				tmp_map[row][col] = 1;
			}
			else {
				break;
			}
		}
	}
	for (int row = 1; row <= x + d2; row++) {
		for (int col = y+1; col <= n; col++) {
			if (tmp_map[row][col] == 0) {
				tmp_map[row][col] = 2;
			}
		}
	}
	for (int row = x+d1; row <= n; row++) {
		for (int col = 1; col < y-d1+d2; col++) {
			if (tmp_map[row][col] == 0) {
				tmp_map[row][col] = 3;
			}
			else {
				break;
			}
		}
	}
	for (int row = x+d2+1; row <= n; row++) {
		for (int col = y-d1+d2; col <= n; col++) {
			if (tmp_map[row][col] == 0) {
				tmp_map[row][col] = 4;
			}
		}
	}
}

void make_5_side(int x,int y, int d1, int d2) {
	queue <pair<int, int>> upper;
	queue <pair<int, int>> down;

	for (int i = d1; i > 0; i--) {	// 5-1번
		upper.push({ x + i, y - i });
	}
	for (int i = 0; i <= d2; i++) {	// 5-2번
		upper.push({ x + i, y + i });
	}
	for (int i = 0; i < d2; i++) { // 5-3번
		down.push({ x + d1 + i, y - d1 + i });
	}
	for (int i = d1; i >= 0; i--) { // 5-4번
		down.push({ x + d2 + i, y + d2 - i });
	}

	while(!upper.empty()) {
		int up_row = upper.front().first;
		int col = upper.front().second;
		int down_row = down.front().first;
		upper.pop();
		down.pop();
		for (int r = up_row; r <= down_row; r++) {
			tmp_map[r][col] = 5;
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	for (int x = 1; x < n; x++) {
		for (int y = 1; y < n; y++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					memset(tmp_map, 0, sizeof(tmp_map));
					if (x + d1 + d2 <= n && y - d1 >= 1 && y + d2 <= n) {
						make_5_side(x, y, d1, d2);
						make_other_side(x, y, d1, d2);
						count_number();
					}

				}
			}
		}
	}
	cout << answer;
	return 0;
 }
