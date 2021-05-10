#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector <pair<int, int>> v[10001];
int a = 0, b = 0, c = 0;

int bfs(int cost) {
	int visit[10001] = { 0, };
	queue <int> q;
	q.push(a);
	visit[a] = 1;
	while (!q.empty()) {
		int nowNode = q.front();
		q.pop();
		if (nowNode == b) {
			return 1;
		}
		for (int i = 0; i < v[nowNode].size(); i++) {
			int nextNode = v[nowNode][i].first;
			int nextCost = v[nowNode][i].second;
			if (visit[nextNode] == 0 && nextCost >= cost) {
				visit[nextNode] = 1;
				q.push(nextNode);
			}
		}
	}
	return -1;
}

int main(void) {
	int n = 0, m = 0;
	int max = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (c > max) {
			max = c;
		}
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	cin >> a >> b;
	int min = 0;

	while (min <= max) {
		int mid = (min + max) / 2;
		if (bfs(mid) > 0) {
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	cout << max;
	return 0;
}
