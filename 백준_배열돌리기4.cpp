#include <iostream>
#include <vector>
using namespace std;
int arr[52][52] = { 0, };
int visit[6] = { 0, };
vector <int> calculate[6];
int n = 0, m = 0, k = 0;
int answer = 90000000;
void find_Min() {
	int sum = 0;
	int output = 90000000;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = 1; j <= m; j++) {
			sum += arr[i][j];
		}
		if (sum < answer) {
			answer = sum;
		}
	}
}
void update(int r, int c, int s) {
	while (s > 0) {
		pair<int, int> idx[4] = { { r - s,c - s },{ r + s,c - s }, { r + s, c + s } ,{ r - s,c + s } };
		int temp[3] = { arr[idx[0].first][idx[0].second],arr[idx[1].first][idx[1].second],arr[idx[2].first][idx[2].second] };
		for (int i = 0; i < 4; i++) {
			int row = idx[i].first;
			int col = idx[i].second;
			for (int j = 0; j < 2 * s; j++) {
				if (i == 0) {
					arr[row][col] = arr[row][col + 1];
					col++;
				}
				else if (i == 1) {
					if (j == 2 * s - 1) {
						arr[row][col] = temp[0];
					}
					else {
						arr[row][col] = arr[row - 1][col];
						row--;
					}
				}
				else if (i == 2) {
					if (j == 2 * s - 1) {
						arr[row][col] = temp[1];
					}
					else {
						arr[row][col] = arr[row][col - 1];
						col--;
					}
				}
				else {
					if (j == 2 * s - 1) {
						arr[row][col] = temp[2];
					}
					else {
						arr[row][col] = arr[row + 1][col];
						row++;
					}
				}
			}
		}
		s--;
	}
}
void rotate(int r, int c, int s) {
	while (s > 0) {
		pair<int, int> idx[4] = { { r - s,c + s },{ r + s, c + s },{ r + s,c - s },{ r - s,c - s } };
		int temp[3] = { arr[idx[0].first][idx[0].second],arr[idx[1].first][idx[1].second],arr[idx[2].first][idx[2].second] };
		for (int i = 0; i < 4; i++) {
			int row = idx[i].first;
			int col = idx[i].second;
			for (int j = 0; j < 2 * s; j++) {
				if (i == 0) {
					arr[row][col] = arr[row][col - 1];
					col--;
				}
				else if (i == 1) {
					if (j == 2 * s - 1) {
						arr[row][col] = temp[0];
					}
					else {
						arr[row][col] = arr[row - 1][col];
						row--;
					}
				}
				else if (i == 2) {
					if (j == 2 * s - 1) {
						arr[row][col] = temp[1];
					}
					else {
						arr[row][col] = arr[row][col + 1];
						col++;
					}
				}
				else {
					if (j == 2 * s - 1) {
						arr[row][col] = temp[2];
					}
					else {
						arr[row][col] = arr[row + 1][col];
						row++;
					}
				}
			}
		}
		s--;
	}
}
void dfs(int r, int c, int s, int idx, int count) {
	if (count == k) {
		find_Min();
		return;
	}
	for (int i = 0; i < k; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			rotate(calculate[i][0], calculate[i][1], calculate[i][2]);
			dfs(calculate[i][0], calculate[i][1], calculate[i][2], i, count + 1);
			update(calculate[i][0], calculate[i][1], calculate[i][2]);
			visit[i] = 0;
		}
	}
}
int main(void) {
	int r = 0, c = 0, s = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		calculate[i].push_back(r);
		calculate[i].push_back(c);
		calculate[i].push_back(s);
	}
	for (int i = 0; i < k; i++) {
		visit[i] = 1;
		rotate(calculate[i][0], calculate[i][1], calculate[i][2]);
		dfs(calculate[i][0], calculate[i][1], calculate[i][2], i, 1);
		update(calculate[i][0], calculate[i][1], calculate[i][2]);
		visit[i] = 0;
	}
	cout << answer;
	return 0;
}
