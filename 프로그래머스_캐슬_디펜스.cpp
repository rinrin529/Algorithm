#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0, m = 0, d = 0;
int map[16][16] = { 0, };
vector <pair<int, int>> juk;
int attack(int g1, int g2, int g3) {	// g: 궁수 좌표
	int j_idx[3] = { -1, -1, -1 };
	int g_col[3] = { g1,g2,g3 };
	int output = 0;
	for (int i = 0; i < 3; i++) {
		int dir = 500;
		int col = 0;
		int g_row = n;
		for (int j = 0; j < juk.size(); j++) {
			int j_row = juk[j].first;
			int j_col = juk[j].second;
			int temp_dir = abs(j_row - g_row) + abs(j_col - g_col[i]);
			if (temp_dir <= d) {	// 공격 거리 이내에 존재
				if (temp_dir < dir) { // 거리가 짧은 것
					dir = abs(j_row - g_row) + abs(j_col - g_col[i]);
					col = j_col;
					j_idx[i] = j;
				}
				else if (temp_dir == dir) {	// 거리가 같을 때
					if (j_col < col) {	// 가장 왼쪽에 있는 것으로
						col = j_col;
						j_idx[i] = j;
					}
				}
				else
					continue;
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		if (j_idx[i] != -1)
			juk[j_idx[i]].first = -1;
	}
	for (int i = 0; i < juk.size(); i++) {
		if (juk[i].first == -1) {
			juk.erase(juk.begin() + i);
			i--;
			output++;
		}
	}
	return output;
}
void move() {	// 적 움직이기
	for (int i = 0; i < juk.size(); i++) {
		juk[i].first++;
		if (juk[i].first == n) {
			juk.erase(juk.begin() + i);
			i--;
		}
	}
}
int fight(int g1, int g2, int g3) {
	int output = 0;
	while (!juk.empty()) {
		output += attack(g1, g2, g3);
		move();
	}
	return output;
}
int main(void) {
	int answer = 0;
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)
				juk.push_back(make_pair(i, j));	// 적 좌표 저장
		}
	}
	vector <pair<int, int>> temp_juk = juk;
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			for (int k = j + 1; k < m; k++) {
				juk = temp_juk;
				int count = fight(i, j, k);
				if (count > answer)
					answer = count;
			}
		}
	}
	cout << answer;
	return 0;
}
