#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 99999999
using namespace std;
int t = 0, n = 0, d = 0, c = 0;
vector < pair<int, pair<int, int>>> izon; // {time, {a,b}}
int answer[100][2] = { 0, };
void find_time(int idx) {
	int last_time = 0;
	int count = 0;
	int time[10001] = { 0, };
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({-1,{c,0}});
	
	for (int i = 1; i <= n; i++) {
		time[i] = INF;
	}
	time[c] = 0;
	while (!pq.empty()) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		int t = pq.top().first;
		pq.pop();
		if (time[a] < t)
			continue;
		for (int i = 0; i < d; i++) {
			int new_a = izon[i].second.first;
			int new_b = izon[i].second.second;
			int new_t = izon[i].first;
			if (a == new_b) {
				if (time[new_a] > time[a] + new_t) {
					time[new_a] = time[a] + new_t;
					pq.push({ time[new_a],{new_a, new_b} });
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (time[i] != INF) {
			count++;
			if (last_time < time[i]) {
				last_time = time[i];
			}
		}
	}
	answer[idx][0] = count;
	answer[idx][1] = last_time;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n >> d >> c;
		int a = 0, b = 0, s = 0;
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			izon.push_back({ s,{a,b} });
		}
		find_time(j);
		izon.clear();
	}
	for (int i = 0; i < t; i++) {
		cout << answer[i][0] << " " << answer[i][1] << '\n';
	}
	return 0;
}
