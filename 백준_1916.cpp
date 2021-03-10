#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 999999999

int main(void) {
	int n = 0, m = 0;
	int start = 0, end = 0, cost = 0;
	int a = 0, b = 0, c = 0;
	cin >> n;	//도시 갯수
	cin >> m;	//버스 갯수
	vector<pair<int, int>> info[1001];
	vector<int> dist((n + 1), INF);
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;	// cost, idx

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		info[a].push_back(make_pair(b, c));
	}
	
	cin >> start >> end;
	dist[start] = 0;
	q.push(make_pair(0, start));

	while (!q.empty()) {
		start = q.top().second;
		cost = q.top().first;
		q.pop();
		if (start == end) {
			break;
		}
		if (dist[start] < cost)
			continue;

		for (int i = 0; i < info[start].size(); i++) {
			int nextNode = info[start][i].first;
			int newCost = info[start][i].second + dist[start];
			if (dist[nextNode] > newCost) {
				dist[nextNode] = newCost;
				q.push(make_pair(newCost, nextNode));
			}
		}
	}

	cout << cost;

	return 0;
}
