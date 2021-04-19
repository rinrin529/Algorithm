#include <iostream>
using namespace std;
int n = 0, m = 0, h = 0;
int a = 0, b = 0;
int answer = 5;
int map[33][13] = { 0, }; // 오른쪽 이동: 본인 칸 확인, 왼쪽 이동: 본인 col-1 칸 확인
int go_route() {
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (map[j][start] == 1) {
				start += 1;   // 사다리 오른쪽으로 이동
			}
			else if (map[j][start - 1] == 1) {
				start -= 1;   // 사다리 왼쪽으로 이동
			}
		}
		if (start != i) {
			return 0; // i가 i로 이동 못함
		}
	}
	return 1;
}
void dfs(int count, int row_idx, int col_idx) {
	if (go_route() == 1) {
		if (answer > count) {
			answer = count;
		}
		return;
	}
	if (count == 3) {
		return;
	}
	if (answer > 2) {
		for (int col = col_idx; col < n; col++) {
			for (int row = 1; row <= h; row++) {
				if (map[row][col] == 0 && map[row][col - 1] == 0 && map[row][col + 1] == 0) {
					map[row][col] = 1;
					dfs(count + 1, row, col);
					map[row][col] = 0;
				}
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	if (go_route() == 1) {
		cout << 0;
		return 0;
	}
	for (int col = 1; col < n; col++) {
		if (answer > 1) {
			for (int row = 1; row <= h; row++) {
				if (map[row][col] == 0 && map[row][col - 1] == 0 && map[row][col + 1] == 0) {
					map[row][col] = 1;
					dfs(1, row, col);
					map[row][col] = 0;
				}
			}
		}
	}
	if (answer > 3) {
		cout << -1;
	}
	else {
		cout << answer;
	}
	return 0;
}
