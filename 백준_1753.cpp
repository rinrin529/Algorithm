#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
#define none 999999999

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v = 0, e = 0, k = 0;
	int a = 0, b = 0, c = 0;
	vector<pair<int, int>> bag[20001];	// [start].fisrt = end, .second = cost
	cin >> v >> e;
	cin >> k;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		bag[a].push_back(make_pair(b, c));
	}

	vector <int> dist((v+1), none);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // (dist, node)

	pq.push(make_pair(0, k));
	dist[k] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int nowNode = pq.top().second;
		pq.pop();
		
		if (dist[nowNode] < cost) 
			continue;
		
		for (int j = 0; j < bag[nowNode].size(); j++) {
			int nextNode = bag[nowNode][j].first;
			int nextDist = dist[nowNode] + bag[nowNode][j].second;
			if (dist[nextNode] > nextDist) {
				dist[nextNode] = nextDist;
				pq.push(make_pair(nextDist, nextNode));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == none)
			printf("INF\n");
		else {
			printf("%d\n", dist[i]);
		}

	}
	
	return 0;
}
