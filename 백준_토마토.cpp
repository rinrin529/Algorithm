#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int dir_r[6] = { -1,0,1,0,0,0 };
int dir_c[6] = { 0,1,0,-1,0,0 };
int m = 0, n = 0, h = 0;

int main(void) {
	cin >> m >> n >> h;
	int box[101][101][101] = { 0, };
	int visit[101][101][101] = { 0, };

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> box[k][i][j];
			}
		}
	}

	queue <pair<pair<int,int>, int>> q;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[k][i][j] == 1 && visit[k][i][j] == 0) {
					q.push({ {i,j},k });
					visit[k][i][j] = 1;
				}
			}
		}
	}
	int ans = 0;

	while (!q.empty()) {
		int row = q.front().first.first;
		int col = q.front().first.second;
		int hei = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int new_r = row + dir_r[i];
			int new_c = col + dir_c[i];
			int new_h = hei;
			if (i == 4) {
				new_h += 1;
			}
			if (i == 5) {
				new_h -= 1;
			}
			if (new_h >= 0 && new_h < h && new_r >= 0 && new_r < n && new_c >= 0 && new_c < m) {
				if (visit[new_h][new_r][new_c] == 0 && box[new_h][new_r][new_c] == 0) {
					visit[new_h][new_r][new_c] = visit[hei][row][col] + 1;
					if (visit[new_h][new_r][new_c] > ans) {
						ans = visit[new_h][new_r][new_c];
					}
					box[new_h][new_r][new_c] = 1;
					q.push({ {new_r,new_c},new_h });
				}
			}
		}
	}
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[k][i][j] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	if (ans == 0) {
		cout << ans;
	}
	else {
		cout << ans - 1;
	}

	return 0;
}
