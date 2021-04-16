#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n = 0;
int map[22][22] = { 0, };
vector <int> Baby_shark = { 0,0,0,0 }; // 0:r, 1:c, 2:size, 3:eat
vector <pair <pair<int, int>, int>> Eat_fish; // first:(first: 거리, second: col) second: row
int dir_r[4] = { -1,0,1,0 };
int dir_c[4] = { 0,+1,0,-1 };

void bfs(int r, int c) {
	int min_dist = 500;
	int visit[21][21] = { 0, };
	queue <pair<int, int>> q;
	q.push(make_pair(r, c));
	while (!q.empty()) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_r = row + dir_r[i];
			int new_c = col + dir_c[i];
			if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n) {
				if (visit[new_r][new_c] == 0 && map[new_r][new_c] <= Baby_shark[2]) {	// 자기 보다 큰 물고기 못 지나감
					visit[new_r][new_c] = visit[row][col] + 1;
					if (map[new_r][new_c] > 0 && map[new_r][new_c] < Baby_shark[2]) {
						if (min_dist >= visit[new_r][new_c]) {
							min_dist = visit[new_r][new_c];
							Eat_fish.push_back(make_pair(make_pair(min_dist, new_r), new_c));
						}
					}
					q.push(make_pair(new_r, new_c));
				}
			}
		}
	}
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				Baby_shark[0] = i;
				Baby_shark[1] = j;
				Baby_shark[2] = 2;
				map[i][j] = 0;
			}
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main(void) {
	int answer = 0;
	init();
	input();

	while (1) {
		bfs(Baby_shark[0], Baby_shark[1]);
		if (Eat_fish.empty()) {
			break;
		}
		sort(Eat_fish.begin(), Eat_fish.end());
		Baby_shark[3] += 1;
		answer += Eat_fish[0].first.first;
		Baby_shark[0] = Eat_fish[0].first.second;	// 상어 행 업데이트
		Baby_shark[1] = Eat_fish[0].second;			// 상어 열 업데이트
		Eat_fish.clear();
		map[Baby_shark[0]][Baby_shark[1]] = 0;

		if (Baby_shark[2] == Baby_shark[3]) {
			Baby_shark[2]++;
			Baby_shark[3] = 0;
		}
	}
	cout << answer;
	return 0;
}
