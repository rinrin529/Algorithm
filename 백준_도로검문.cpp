#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 99999999
using namespace std;
int n = 0, m = 0;
vector < pair<pair<int, int>, int>> lines; // {{a,b}, time}
int preNode[1001] = { 0, };
int get_time(int police, int no_a, int no_b) {
	int time[1001] = { 0, };
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ -1,{0,1} }); // time, a, b
	for (int i = 2; i <= n; i++) {
		time[i] = INF;
	}
	while (!pq.empty()) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		int t = pq.top().first;
		pq.pop();
		if (time[b] < t)
			continue;
		for (int i = 0; i < m; i++) {
			int new_a = lines[i].first.first;
			int new_b = lines[i].first.second;
			int new_t = time[b] + lines[i].second;
			if (b == new_a) {
				if (!(new_a == no_a && new_b == no_b)) {
					if (time[new_b] > new_t) {
						pq.push({ new_t ,{new_a, new_b} });
						time[new_b] = new_t;
						if (police == -1) {
							preNode[new_b] = b;
						}
					}
				}
			}
			if (b == new_b) {
				if (!(new_a == no_a && new_b == no_b)) {
					if (time[new_a] > new_t) {
						pq.push({ new_t ,{new_b, new_a} });
						time[new_a] = new_t;
						if (police == -1) {
							preNode[new_a] = b;
						}
					}
				}
			}
		}
	}
	return time[n];
}
int main(void) {
	int min = 0;
	int max = 0;
	int check = 0;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		lines.push_back({ {a,b},c });
		if (b == n) {
			check++;
		}
	}
	if (check == 1) {
		cout << -1;
		return 0;
	}
	min = get_time(-1,-1,-1);
	vector <pair<int, int>> v;
	int now = n;
	while (now != 1) {
		int befo = preNode[now];
		v.push_back({ befo, now });
		now = befo;
	}
	int ss = v.size();
	for (int i = 0; i < ss; i++) {
		int tmp = get_time(i, v[i].first, v[i].second);
		if (tmp == INF) {
			cout << -1;
			return 0;
		}
		if (max < tmp) {
			max = tmp;
		}
	}
	cout << max - min;
	return 0;
}
