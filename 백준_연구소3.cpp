#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int n = 0, m = 0;
int answer = 999999999;
int visit[52][52] = { 0, };
int map[52][52] = { 0, };
int tmp_map[52][52] = { 0, };
int dir_r[4] = { -1,0,1,0 };
int dir_c[4] = { 0,1,0,-1 };
vector <pair<int, int>> virus;
stack <pair<int, int>> choose_v;

int end_spread() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int bfs() {
	int tmp_ans = 0;
	queue <pair<int, int>> q;
	stack <pair<int, int>> tmp;
	while (!choose_v.empty()) {
		visit[choose_v.top().first][choose_v.top().second] = 1;
		q.push({ choose_v.top().first, choose_v.top().second });
		tmp.push({ choose_v.top().first, choose_v.top().second });
		choose_v.pop();
	}

	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_r = row + dir_r[i];
			int new_c = col + dir_c[i];
			if (new_r < n && new_r >= 0 && new_c < n && new_c >= 0) {
				if (map[new_r][new_c] == 0 && visit[new_r][new_c]==0) {
					visit[new_r][new_c] = 1;
					map[new_r][new_c] = map[row][col] + 1;
					q.push({ new_r,new_c });
					if (map[new_r][new_c] > tmp_ans) {
						tmp_ans = map[new_r][new_c];
					}
				}
				if (map[new_r][new_c] == 1 && visit[new_r][new_c] == 0) {	// 활성을 비활성화로
					map[new_r][new_c] = map[row][col] + 1; /////////////
					visit[new_r][new_c] = 1;
					q.push({ new_r,new_c });
				}
			}
		}
	}
	while (!tmp.empty()) {
		choose_v.push({ tmp.top().first, tmp.top().second });
		tmp.pop();
	}
	if (end_spread() == 0) {
		return -1;
	}
	else {
		return tmp_ans - 1;
	}
}

void choose_virus(int befo, int count, int vsize) {
	if (count == m) {
		int tmp = bfs();
		if (tmp > 0) {
			if (tmp < answer) {
				answer = tmp;
			}
		}
		memcpy(map, tmp_map, sizeof(tmp_map));
		memset(visit, 0, sizeof(visit));
		return;
	}
	else if (count > m) {
		return;
	}
	else {
		if ((m - count) > (vsize - (befo + 1))) {
			return;
		}
		for (int i = befo + 1; i < vsize; i++) {
			choose_v.push({ virus[i].first, virus[i].second });
			choose_virus(i, count + 1, vsize);
			choose_v.pop();
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;	// 벽은 -1
			}
			else if (map[i][j] == 2) {
				map[i][j] = 1;
				virus.push_back({ i,j });
			}
		}
	}
	memcpy(tmp_map, map, sizeof(map));
	if (end_spread() == 1) {
		cout << 0;
		return 0;
	}
	int vsize = virus.size();
	for (int i = 0; i <= vsize-m; i++) {
		choose_v.push({ virus[i].first, virus[i].second });
		choose_virus(i, 1, vsize);
		choose_v.pop();
	}
	if (answer == 999999999) {
		cout << -1;
	}
	else {
		cout << answer;
	}
	return 0;
 }
