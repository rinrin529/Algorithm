#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n = 0;
int map[105][105] = { 0, };
int water[105][105] = { 0, };
int dir_r[4] = { -1,0,1,0 };
int dir_c[4] = { 0,1,0,-1 };
pair<int, int> find_idx() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (water[i][j] != -1 && water[i][j] == 0) {
				return { i, j };
			}
		}
	}
	return { -1,-1 };
}

int safety_zone(int hight) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] <= hight) {
				water[i][j] = -1;
			}
		}
	}
	pair<int, int> idx = find_idx();
	queue <pair<pair<int, int>, int>> q;
	q.push({ idx,1 });
	water[idx.first][idx.second] = 1;
	int count = 1;
	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int num = q.front().second;
		q.pop();
		if (row == -1 && col == -1)
			continue;
		water[row][col] = num;
		for (int i = 0; i < 4; i++) {
			int nextR = row + dir_r[i];
			int nextC = col + dir_c[i];
			if (nextR >= 0 && nextR < n&& nextC >= 0 && nextC < n) {
				if (water[nextR][nextC] == 0) {
					water[nextR][nextC] = num;
					q.push({ {nextR, nextC},num });
				}
			}
		}
		if (num > count) {
			count = num;
		}
		if (q.empty()) {
			q.push({ find_idx(), num + 1 });
		}
	}
	return count;
}

int main(void) {
	int max = 0;
	int min = 101;
	int answer = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] < min) {
				min = map[i][j];
			}
			if (map[i][j] > max) {
				max = map[i][j];
			}
		}
	}
	for (int hight = min; hight <= max; hight++) {
		memset(water, 0, sizeof(water));
		int count = safety_zone(hight);
		if (answer < count) {
			answer = count;
		}
	}
	
	cout << answer;
	return 0;
}
