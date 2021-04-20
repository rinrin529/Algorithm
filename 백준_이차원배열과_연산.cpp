#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int r = 0, c = 0, k = 0;
int r_size = 3, c_size = 3;
int map[100][100] = { 0, };

struct compare {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		else {
			return a.second > b.second;
		}
	}
};

void cal_row() {
	int c_max = 0;
	for (int i = 0; i < r_size; i++) {
		int num_count[101] = { 0, };
		queue <int> number;
		priority_queue <pair<int, int>, vector<pair<int, int>>, compare> pq;
		for (int j = 0; j < c_size; j++) {
			int num = map[i][j];
			if (num > 0) {
				if (num_count[num] == 0) {
					number.push(num);
				}
				num_count[num]++;
			}
			map[i][j] = 0;
		}
		while (!number.empty()) {
			int n = number.front();
			number.pop();
			pq.push({ n, num_count[n] });
		}
		int pq_size = pq.size() * 2;
		c_max = max(c_max, pq_size);
		int idx = 0;
		while (!pq.empty()) {
			map[i][idx] = pq.top().first;
			map[i][idx + 1] = pq.top().second;
			pq.pop();
			idx += 2;
			if (idx > 100) {
				break;
			}
		}
	}
	c_size = c_max;
}

void cal_col() {
	int r_max = 0;
	for (int i = 0; i < c_size; i++) {
		int num_count[101] = { 0, };
		queue <int> number;
		priority_queue <pair<int, int>, vector<pair<int, int>>, compare> pq;
		for (int j = 0; j < r_size; j++) {
			int num = map[j][i];
			if (num > 0) {
				if (num_count[num] == 0) {
					number.push(num);
				}
				num_count[num]++;
			}
			map[j][i] = 0;
		}
		while (!number.empty()) {
			int n = number.front();
			number.pop();
			pq.push({ n, num_count[n] });
		}
		int pq_size = pq.size() * 2;
		r_max = max(r_max, pq_size);
		int idx = 0;
		while (!pq.empty()) {
			map[idx][i] = pq.top().first;
			map[idx + 1][i] = pq.top().second;
			pq.pop();
			idx += 2;
			if (idx > 100) {
				break;
			}
		}
	}
	r_size = r_max;
}

int main(void) {
	int answer = 0;
	cin >> r >> c >> k;
	r -= 1;
	c -= 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	if(map[r][c] == k) {
		cout << 0;
		return 0;
	}
	while (1) {
		answer++;
		if (answer > 100) {
			cout << -1;
			return 0;
		}
		if (r_size >= c_size) {
			cal_row();
		}
		else {
			cal_col();
		}
		if (map[r][c] == k) {
			break;
		}
		if (c_size > 100) {
			c_size = 100;
		}
		if (r_size > 100) {
			r_size = 100;
		}
	}
	cout << answer;
	return 0;
 }
