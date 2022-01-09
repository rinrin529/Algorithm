#include <iostream>
#include <stack>

using namespace std;
int player[22][22] = { 0, };
int visit[22] = { 0, };
int answer = 999999999;
int n = 0;

int cal_sum(int link_or_start) {
	int team[22] = { 0, };
	int idx = 0;
	int output = 0;
	if (link_or_start == 1) {	// link 팀 계산
		for(int i = 0; i < n; i++) {
			if (visit[i] == 0) {
				team[idx] = i;
				idx++;
			}
		}
	}	
	else {	// start 팀 계산
		for (int i = 0; i < n; i++) {
			if (visit[i] == 1) {
				team[idx] = i;
				idx++;
			}
		}
	}
	for (int i = 0; i < idx-1; i++) {
		for (int j = i+1; j < idx; j++) {
			int row = team[i];
			int col = team[j];
			output += (player[row][col] + player[col][row]);
		}
	}
	return (output);
}

void start_dfs(int count, int befo) {
	if (count == (n/2)) {
		int start_sum = cal_sum(0);
		int link_sum = cal_sum(1);
		if (abs(start_sum - link_sum) < answer) {
			answer = abs(start_sum - link_sum);
		}
		return;
	}
	for (int i = befo + 1; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			start_dfs(count + 1, i);
			visit[i] = 0;
		}
	}
}

int solution() {
	for (int i = 0; i < n; i++) {
		visit[i] = 1;
		start_dfs(1, i);
		visit[i] = 0;
	}
	cout << answer;
	return 0;
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> player[i][j];
		}
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main(void) {
	init();
	input();
	solution();
	return 0;
}
