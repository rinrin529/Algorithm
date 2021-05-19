#include <iostream>
#include <vector>
#include <queue>
#define INF 999999
using namespace std;
int main(void) {
	int k = 0, n = 0;
	int a = 0, b = 0;
	vector <int> fam[105];
	int dist[105] = { 0, };
	cin >> n;
	cin >> a >> b;
	cin >> k;
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < k; i++) {
		int x = 0, y = 0;
		cin >> x >> y;
		fam[x].push_back(y);
		fam[y].push_back(x);
	}
	queue <pair<int,int>> q; // 노드, 거리
	q.push({ a,0 });
	dist[a] = 0;
	while (!q.empty()) {
		int node = q.front().first;
		int d = q.front().second;
		if (node == b) {
			cout << d;
			return 0;
		}
		q.pop();
		if (dist[node] < d)
			continue;
		for (int i = 0; i < fam[node].size(); i++) {
			int nextNode = fam[node][i];
			if (dist[nextNode] > d + 1) {
				dist[nextNode] = d + 1;
				q.push({ nextNode, d + 1 });
			}
		}
	}
	cout << -1;
	return 0;
}
