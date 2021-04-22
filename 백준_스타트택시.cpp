#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int map[22][22] = { 0, };
int n = 0, m = 0;
long long car[3] = { 0, };	// row, col, 남은 연료
int people[500][4] = { 0, };
int dir_r[4] = { -1,0,1,0 };
int dir_c[4] = { 0,1,0,-1 };

pair<int, int > find_dest(int person, int drop_idx) {	//사람idx, 거리
	queue <pair<int, int>> q;
	int dist_map[22][22] = { 0, };
	int visit[22][22] = { 0 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist_map[i][j] = 900;
		}
	}
	q.push({ car[0],car[1] });
	dist_map[car[0]][car[1]] = 0;
	visit[car[0]][car[1]] = 1;

	while (!q.empty()) {	// 최단 거리 구하기
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_r = row + dir_r[i];
			int new_c = col + dir_c[i];
			if (new_r > 0 && new_r <= n && new_c <= n && new_c > 0) {
				if (map[new_r][new_c] != 1) {	// 벽이 아니면
					dist_map[new_r][new_c] = min(dist_map[new_r][new_c], dist_map[row][col] + 1);
					if (visit[new_r][new_c] == 0) {
						q.push({ new_r, new_c });
						visit[new_r][new_c] = 1;
					}
				}
			}
		}
	}
	if (person == 1) {	// 태울 사람 거리 찾기 return (사람idx, 거리)
		pair<pair<int, int>, pair<int, int>> find_min;
		find_min.first.first = 900;
		find_min.first.second = 900;
		find_min.second.first = 900;
		find_min.second.second = 900;

		for (int i = 0; i < m; i++) {
			if (people[i][0] != -1) {
				int row = people[i][0];
				int col = people[i][1];
				int dist = dist_map[row][col];
				if (dist < find_min.first.first) {
					find_min.first.first = dist;
					find_min.first.second = i;
					find_min.second.first = row;
					find_min.second.second = col;
				}
				else if (dist == find_min.first.first) {
					if (row < find_min.second.first) {
						find_min.first.first = dist;
						find_min.first.second = i;
						find_min.second.first = row;
						find_min.second.second = col;
					}
					else if (row == find_min.second.first) {
						if (col < find_min.second.second) {
							find_min.first.first = dist;
							find_min.first.second = i;
							find_min.second.first = row;
							find_min.second.second = col;
						}
					}
				}
			}
		}
		pair<int, int> output;
		if (find_min.first.first == 900) {
			output.first = -1;
			output.second = -1;
		}
		else {
			output.first = find_min.first.second;
			output.second = find_min.first.first;
		}
		return (output); //사람idx, 거리
	}
	else {	// 도착 지점  거리 찾기
		pair<int, int> output;
		int row = people[drop_idx][2];
		int col = people[drop_idx][3];
		int dist = dist_map[row][col];
		if (dist == 900) {
			output.first = -1;
			output.second = -1;
		}
		else {
			output.first = drop_idx;
			output.second = dist;
		}
		return (output);
	}
}

int main(void) {
	cin >> n >> m >> car[2];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	cin >> car[0] >> car[1];
	int r = 0, c = 0, dr = 0, dc = 0;
	for (int i = 0; i < m; i++) {
		cin >> r >> c >> dr >> dc;
		people[i][0] = r;
		people[i][1] = c;
		people[i][2] = dr;
		people[i][3] = dc;
	}

	while (1) {
		int end_check = 0;
		for (int i = 0; i < m; i++) {
			if (people[i][0] ==-1) {
				end_check++;
			}
		}

		if (end_check == m) {
			break;
		}

		pair<int, int> find_person = find_dest(1, 0); //(사람idx, 거리)
		int dist = find_person.second;
		int p_idx = find_person.first;
		if (dist == -1) {
			cout << -1;
			return 0;
		}
		if (car[2] - dist <= 0) {
			cout << -1;
			return 0;
		}
		else {
			int row = people[p_idx][0];
			int col = people[p_idx][1];
			car[0] = row;
			car[1] = col;
			car[2] -= dist;
			pair<int, int> drop_person = find_dest(0, p_idx);
			dist = drop_person.second;
			if (car[2] - dist < 0) {
				cout << -1;
				return 0;
			}
			else if(dist == -1) {
				cout << -1;
				return 0;
			}
			else {
				car[0] = people[p_idx][2];
				car[1] = people[p_idx][3];
				car[2] += dist;
				people[p_idx][0] = -1;	// 승객 삭제
			}
		}
	}
	cout << car[2];
	return 0;
}
