#include <iostream>
#include <vector>
using namespace std;
#define max 10
int map[10][10] = { 0, };
int paper[6] = { 0,5,5,5,5,5 };
int check = 0;
int answer = 500;
vector <pair<int, int>> v;
int check_size(int row, int col, int size) {
	if (row + size > max || col + size > max) {
		return 0;
	}
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (map[i][j] != 1) {
				return 0;
			}
		}
	}
	return 1;
}
void update_map(int row, int col, int size, int back) {
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (back == 1) {
				map[i][j] = 1;	// 원상복구
			}
			else {
				map[i][j] = 2;	// 색종이 덮음
			}
		}
	}
}
void dfs(int count, int total, int idx) {
	if (check == total) {	// 전부다 커버가 되었는 지
		if (answer > count) {
			answer = count;
		}
		return;
	}
	int row = v[idx].first;
	int col = v[idx].second;
	if (map[row][col] == 1) {
		for (int size = 5; size > 0; size--) {
			if (check_size(row, col, size) == 1 && paper[size] > 0) {
				count++;
				paper[size]--;
				update_map(row, col, size, 0);	// 색종이 덮음
				total += (size*size);
				dfs(count, total, idx + 1);
				update_map(row, col, size, 1);	// 색종이 치움
				total -= (size*size);
				paper[size]++;
				count--;
			}
		}
	}
	else {
		dfs(count, total, idx + 1);
	}
}
int main(void) {
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				v.push_back(make_pair(i, j));
				check++;
			}
		}
	}
	dfs(0, 0, 0);
	if (answer == 500) {
		cout << -1;
	}
	else {
		cout << answer;
	}
	return 0;
}
