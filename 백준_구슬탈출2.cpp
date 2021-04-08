#include <iostream>

using namespace std;
int n = 0, m = 0;
char map[12][12] = { 0, };
int dir_r[] = { -1,0,1,0 };
int dir_c[] = { 0,1,0,-1 };
int answer = 100000;
pair<int, int> red;
pair<int, int> blue;

int move_count(int dir_idx) {
	pair<int, int> temp_red = red;
	pair<int, int> temp_blue = blue;
	int count = 0;
	int red_stop = 0;
	int blue_stop = 0;
	while (1) {
		int new_red_r = temp_red.first + dir_r[dir_idx];
		int new_red_c = temp_red.second + dir_c[dir_idx];
		int new_blue_r = temp_blue.first + dir_r[dir_idx];
		int new_blue_c = temp_blue.second + dir_c[dir_idx];
		if (map[new_blue_r][new_blue_c] == '#') {
			blue_stop = 1;	// 파랑 구슬 막힘
		}
		if (map[new_red_r][new_red_c] == '#') {
			red_stop = 1;	// 빨강 구슬 막힘
		}

		if (red_stop == 0) {	// 빨강 구슬이 막히지 않았을 때
			if (blue_stop == 1) {	// 파랑 구슬이 막혔을 때
				if (new_red_r == temp_blue.first && new_red_c == temp_blue.second) {	// 좌표가 같을 때
					red_stop = 1;
				}
				else {
					temp_red.first = new_red_r;
					temp_red.second = new_red_c;
					count++;
				}
			}
			else {
				temp_red.first = new_red_r;
				temp_red.second = new_red_c;
				count++;
			}
		}

		if (blue_stop == 0) {	// 파랑 구슬이 막히지 않았을 때
			if (red_stop == 1) {	// 빨강 구슬이 막혔을 때
				if (temp_red.first == new_blue_r && temp_red.second == new_blue_c) {	// 좌표가 같을 때
					blue_stop = 1;
				}
				else {
					temp_blue.first = new_blue_r;
					temp_blue.second = new_blue_c;
					count++;
				}
			}
			else {
				temp_blue.first = new_blue_r;
				temp_blue.second = new_blue_c;
				count++;
			}
		}

		if (red_stop && blue_stop) {	// 두개 구술 다 못 움직여서 종료
			red = temp_red;
			blue = temp_blue;
			return count;
		}

		if (map[temp_blue.first][temp_blue.second] == 'O') {
			red = temp_red;
			blue = temp_blue;
			return count;
		}
		if (map[temp_red.first][temp_red.second] == 'O') {	
			int blue_row = temp_blue.first;
			int blue_col = temp_blue.second;

			while (1) {	// 뒤에 파란 구슬이 있는지 확인해야한다.
				blue_row += dir_r[dir_idx];
				blue_col += dir_c[dir_idx];
				if (map[blue_row][blue_col] == '#') {
					red = temp_red;
					blue = temp_blue;
					return count;
				}
				if (map[blue_row][blue_col] == 'O') {	// 동시에 구멍에 빠지면 탈락
					red = temp_red;
					blue = temp_red;
					return count;
				}
			}
		}
	}
}

void dfs(int count, int befo_dir_idx) {
	if (count > 10) {
		return;	// 10회 이상 소요(종료)
	}
	if (count <= 10) {
		if (map[blue.first][blue.second] == 'O') {
			return;	// 파란공이 구멍에 빠짐(종료)
		}
		if (map[red.first][red.second] == 'O' && map[blue.first][blue.second] != 'O') {
			if (answer > count) {
				answer = count;
				return;	// 빨간 구슬이 구멍에 빠짐(종료)
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (befo_dir_idx == 0 && i==2) {
			continue;
		}
		else if (befo_dir_idx == 1 && i == 3) {
			continue;
		}
		else if (befo_dir_idx == 2 && i == 0) {
			continue;
		}
		else if (befo_dir_idx == 3 && i == 1) {
			continue;
		}
		else {
			pair<int, int> red_temp = red;
			pair<int, int> blue_temp = blue;
			if (move_count(i) != 0) {
				dfs(count + 1, i);
				red = red_temp;
				blue = blue_temp;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				blue.first = i;
				blue.second = j;
			}
			else if (map[i][j] == 'R') {
				red.first = i;
				red.second = j;
			}
		}
	}
		
	dfs(0, 4);
	if (answer == 100000) {
		cout << -1;
	}
	else {
		cout << answer;
	}
	return 0;
}
