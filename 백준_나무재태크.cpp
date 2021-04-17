#include <iostream>
#include <algorithm>
#include <queue>
#include <functional> 
using namespace std;
int n = 0, m = 0, k = 0;
priority_queue <int, vector<int>, greater<int>> tree[12][12];	// age, row, col
int A[12][12] = { 0, };
int map[12][12] = { 0, };
int dir_r[8] = { -1,-1,-1,0,0,1,1,1 };
int dir_c[8] = { -1,0,1,-1,1,-1,0,1 };

void Seasons() {
	int tmp_A[12][12] = { 0, };
	int new_tree[12][12] = { 0, };	// age, row, col

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			queue <int> alive;
			while (!tree[i][j].empty()) {
				if (map[i][j] - tree[i][j].top() >= 0) { // 양분 흡수
					map[i][j] -= tree[i][j].top();
					alive.push(tree[i][j].top() + 1);
					if ((tree[i][j].top() + 1) % 5 == 0) { // 나무 번식
						for (int d = 0; d < 8; d++) {
							int new_r = i + dir_r[d];
							int new_c = j + dir_c[d];
							if (new_r >= 1 && new_r <= n && new_c >= 1 && new_c <= n) {
								new_tree[new_r][new_c]++;
							}
						}
					}
				}
				else {
					tmp_A[i][j] += tree[i][j].top() / 2;	// 흡수 못하는 나무 죽음 
				}
				tree[i][j].pop();
			}
			while (!alive.empty()) {
				tree[i][j].push(alive.front()); 
				alive.pop();
			}
		}
	}
	
	////////// 겨울 : 양분 주기 ////////////
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] += (A[i][j] + tmp_A[i][j]);
			for (int k = 0; k < new_tree[i][j]; k++) {
				tree[i][j].push(1);
			}
		}
	}
}

void input() {
	int row = 0, col = 0, age = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
			map[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> row >> col >> age;
		tree[row][col].push(age);
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int solution() {
	int answer = 0;
	for (int i = 0; i < k; i++) {
		Seasons();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!tree[i][j].empty()) {
				answer+= tree[i][j].size();
			}
		}
	}
	return answer;
}
int main(void) {
	int answer = 0;
	init();
	input();
	cout << solution();
	return 0;
}
