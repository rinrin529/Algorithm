#include <iostream>
#include <vector>
using namespace std;
int dir_r[8] = { -1,-1,0,1,1,1,0,-1 };
int dir_c[8] = { 0,1,1,1,0,-1,-1, -1 };
vector <vector<int>> map[52][52];
void Check_split(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int map_size = map[i][j].size();
			if (map_size > 1) {
				int m_sum = 0;
				int s_sum = 0;
				int dir_check = map[i][j][0][2] % 2;	// 짝수 = 0, 홀수 = 1
				int dir_same = 1;	// 같으면 1, 다르면 0
				for (int k = 0; k < map_size; k++) {
					m_sum += map[i][j][k][0];
					s_sum += map[i][j][k][1];
					if (dir_same == 1) {
						if (dir_check != map[i][j][k][2] % 2) {
							dir_same = 0;
						}
					}
				}
				if (dir_same == 1) {  // 방향 0, 2, 4, 6
					map[i][j].clear();
					if (m_sum / 5 > 0) {
						for (int dir = 0; dir < 7; ) {
							vector <int> fire_ball = { m_sum / 5, s_sum / map_size, dir };
							map[i][j].push_back(fire_ball);
							dir += 2;
						}
					}
				}
				else {  // 방향 1, 3, 5, 7
					map[i][j].clear();
					if (m_sum / 5 > 0) {
						for (int dir = 1; dir < 8; ) {
							vector <int> fire_ball = { m_sum / 5, s_sum / map_size, dir };
							map[i][j].push_back(fire_ball);
							dir += 2;
						}
					}
				}
			}
		}
	}
}
pair<int, int> Set_row_col(int row, int col, int dir, int s, int n) {
	int new_row = row + (dir_r[dir] * s);
	int new_col = col + (dir_c[dir] * s);
	while (1) {
		if (new_row > n) {
			new_row -= n;
		}
		else if (new_row < 1) {
			new_row += n;
		}
		else {
			break;
		}
	}
	while (1) {
		if (new_col > n) {
			new_col -= n;
		}
		else if (new_col < 1) {
			new_col += n;
		}
		else {
			break;
		}
	}
	return (make_pair(new_row, new_col));
}
void Move_fireball(int n) {
	vector < pair<int, int>> new_idx;
	vector <vector<int>> new_fire_ball;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int map_size = map[i][j].size();
			if (map_size > 0) {
				for (int k = 0; k < map_size; k++) {
					new_idx.push_back(Set_row_col(i, j, map[i][j][k][2], map[i][j][k][1], n));
					new_fire_ball.push_back(map[i][j][k]);
				}
			}
			map[i][j].clear();
		}
	}
	int new_size = new_idx.size();
	for (int i = 0; i < new_size; i++) {
		map[new_idx[i].first][new_idx[i].second].push_back(new_fire_ball[i]);
	}
}
int main(void) {
	int n = 0, num = 0, k = 0;
	int row = 0, col = 0, m = 0, d = 0, s = 0;
	cin >> n >> num >> k;
	for (int i = 0; i < num; i++) {
		cin >> row >> col >> m >> s >> d;
		vector <int> fire_ball = { m, s, d };
		map[row][col].push_back(fire_ball);
	}
	for (int i = 0; i < k; i++) {
		Move_fireball(n);
		Check_split(n);
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int map_size = map[i][j].size();
			for (int k = 0; k < map_size; k++) {
				answer += map[i][j][k][0];
			}
		}
	}
	cout << answer;
	return 0;
}
