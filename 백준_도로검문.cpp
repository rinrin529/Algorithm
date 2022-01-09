#include <iostream>
#include <vector>
#include <queue>

#define INF 99999999
using namespace std;
int n = 0, m = 0;
vector <pair<int,int>> lines[1001]; // {{a,b}, time}
int preNode[1001] = { 0, };

int get_time(int police, int no_a, int no_b) {
	int time[1001] = { 0, };
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ -1,1 }); // time, a, b
	for (int i = 2; i <= n; i++) {
		time[i] = INF;
	}
	while (!pq.empty()) {
		int b = pq.top().second;
		int t = pq.top().first;
		pq.pop();
		if (time[b] < t)
			continue;

		for (int i = 0; i < lines[b].size(); i++) {
			int new_a = lines[b][i].first;
			int new_t = time[b] + lines[b][i].second;
			if (!(b == no_a && new_a == no_b)) {
				if (time[new_a] > new_t) {
					pq.push({ new_t ,new_a });
					time[new_a] = new_t;
					if (police == -1) {
						preNode[new_a] = b;
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
		lines[a].push_back({ b,c });
		lines[b].push_back({ a,c });
		if (b == n) {
			check++;
		}
	}
	if (check == 1) {
		cout << -1;
		return 0;
	}
	min = get_time(-1, -1, -1);
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
