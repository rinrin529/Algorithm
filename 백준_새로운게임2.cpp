#include<iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
stack <int> player_map[13][13];	// 순서 k(idx)
vector <pair<pair<int,int>,int>> player; // ((row, col), 방향)
int map[13][13] = { 0, };
int change_dir[5] = { 0,2,1,4,3 };
int dir_r[5] = { 0,0,0,-1,1 };
int dir_c[5] = { 0,1,-1,0,0 };
int n = 0, k = 0;
int ans = 1;

int check_end() {
	for (int i = 1; i <= k; i++) {
		int row = player[i].first.first;
		int col = player[i].first.second;
		if (!player_map[row][col].empty()) {
			if (player_map[row][col].size() >= 4) {
				return 1;	// 게임 종료
			}
		}
	}

	return 0;
}

int check_range(int row, int col) {
	if (row >= 1 && row <= n && col >= 1 && col <= n) {
		return 1;
	}
	else {
		return 0;
	}
}

void next_is_white(int row, int col, int new_r, int new_c, int i) {
	stack <int> tmp;	// 꺼내서 저장하면 A위로 순서대로 저장 
	while (1) {
		int idx = player_map[row][col].top();
		player_map[row][col].pop();
		tmp.push(idx);
		if (idx == i) {
			break;
		}
	}
	while (!tmp.empty()) {
		int idx = tmp.top();
		player[idx].first.first = new_r;
		player[idx].first.second = new_c;
		player_map[new_r][new_c].push(idx);
		tmp.pop();
	}
}

void next_is_red(int row, int col, int new_r, int new_c, int i) {
	queue <int> tmp;	// 꺼내서 저장하면 A위로 순서 반대로 저장 
	while (1) {
		int idx = player_map[row][col].top();
		player_map[row][col].pop();
		tmp.push(idx);
		if (idx == i) {
			break;
		}
	}
	while (!tmp.empty()) {
		int idx = tmp.front();
		player[idx].first.first = new_r;
		player[idx].first.second = new_c;
		player_map[new_r][new_c].push(idx);
		tmp.pop();
	}
}

void next_is_blue(int row, int col, int new_r, int new_c, int i) {
	player[i].second = change_dir[player[i].second]; // 방향 바꿔준다.
	int blue_new_r = row + dir_r[player[i].second];
	int blue_new_c = col + dir_c[player[i].second];
	if (check_range(blue_new_r, blue_new_c) == 1) {
		if (map[blue_new_r][blue_new_c] == 0) {	// 하양
			next_is_white(row, col, blue_new_r, blue_new_c, i);
		}
		else if (map[blue_new_r][blue_new_c] == 1) {	// 빨강
			next_is_red(row, col, blue_new_r, blue_new_c, i);
		}
	}
}

int main(void) {
	int num = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	int r = 0, c = 0, d = 0;
	player.push_back({ {r,c},d });
	for (int i = 1; i <= k; i++) {
		cin >> r >> c >> d;
		player.push_back({ {r,c},d });
		player_map[r][c].push(i);
	}
	while (1) {
		if (ans == 1000) {
			ans = -1;
			break;
		}
		for (int i = 1; i <= k; i++) {
			int row = player[i].first.first;
			int col = player[i].first.second;
			int d = player[i].second;
			int new_r = row + dir_r[d];
			int new_c = col + dir_c[d];
			if (check_range(new_r, new_c) == 1) {
				if (map[new_r][new_c] == 0) {	// 하양
					next_is_white(row, col, new_r, new_c, i);
				}
				else if (map[new_r][new_c] == 1) {	// 빨강
					next_is_red(row, col, new_r, new_c, i);
				}
				else {	// 파랑
					next_is_blue(row, col, new_r, new_c, i);
				}
			}
			else {	// 범위 밖으로 이동(파랑이랑 똑같음)
				next_is_blue(row, col, new_r, new_c, i);
			}
			if (check_end() == 1) {
				cout << ans;
				return 0;
			}
		}
		ans++;
	}

	cout << ans;
	return 0;
}
