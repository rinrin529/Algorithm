#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n = 0, l = 0, r = 0;
int map[52][52] = { 0, };
int visit[52][52] = { 0, };
int dir_r[4] = { -1,0,1,0 };
int dir_c[4] = { 0,1,0,-1 };

void check_union(int rr, int cc) {
	int count = 0;
	int total = 0;
	queue <pair<int, int>> q;
	queue <pair<int, int>> contry;
	q.push({ rr,cc });
	while (!q.empty()) {
		count++;
		int row = q.front().first;
		int col = q.front().second;
		total += map[row][col];
		contry.push({ row,col });
		q.pop();
		for (int k = 0; k < 4; k++) {
			int new_r = row + dir_r[k];
			int new_c = col + dir_c[k];
			if (new_r >= 0 && new_r < n&&new_c >= 0 && new_c < n) {
				int cal = abs(map[row][col] - map[new_r][new_c]);
				if (cal <= r && cal >= l && visit[new_r][new_c] == 0) {
					visit[new_r][new_c] = 1;
					q.push({ new_r, new_c });
				}
			}
		}
	}

	if (count > 1) {
		while (!contry.empty()) {
			int row = contry.front().first;
			int col = contry.front().second;
			map[row][col] = total / count;
			contry.pop();
		}
	}
}

int main(void) {
	int answer = 0;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		int end = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0) {
					visit[i][j] = 1;
					check_union(i, j);
					end++;
				}
			}
		}
		if (end == n * n) {
			break;
		}
		answer++;
		memset(visit, 0, sizeof(visit));
	}
	cout << answer;
	   
	return 0;
 }
