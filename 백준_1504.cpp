#include <iostream>

using namespace std;
#define none 1000000

int map[801][801] = { 0, };
int dist_v1[801] = { 0, };
int dist_v2[801] = { 0, };
int n = 0, e = 0;

int find_smallest_time(int start, int* visit, int* dist) {
	int idx = -1;
	int time = none;

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1)continue;
		if (dist[i] < time) {
			time = dist[i];
			idx = i;
		}
	} 
	return idx;
}

void Dijkstra_v1(int start ) { //newNode 시작점 x 목적지 idx 처음 시작점
	int visit[801] = { 0, };
	int newNode = start; 

	for (int i = 1; i <= n; i++)
		dist_v1[i] = none;

	for (int i = 1; i <= n; i++) {
		if (map[newNode][i] != none)
			dist_v1[i] = map[newNode][i];
	}
	dist_v1[newNode] = 0;
	visit[newNode] = 1;

	for (int i = 0; i < n; i++) {
		newNode = find_smallest_time(newNode, visit, dist_v1);
		if (newNode == -1) break;
		visit[newNode] = 1;
		for (int j = 1; j <= n; j++) {
			if (visit[j] == 1) continue;
			if (dist_v1[j] > dist_v1[newNode] + map[newNode][j] && map[newNode][j] != none)
				dist_v1[j] = dist_v1[newNode] + map[newNode][j];
		}
	}
}

void Dijkstra_v2(int start ) { //newNode 시작점 x 목적지 idx 처음 시작점
	int visit[801] = { 0, };
	int newNode = start;

	for (int i = 1; i <= n; i++)
		dist_v2[i] = none;

	for (int i = 1; i <= n; i++) {
		if (map[newNode][i] != none)
			dist_v2[i] = map[newNode][i];
	}
	dist_v2[newNode] = 0;
	visit[newNode] = 1;

	for (int i = 0; i < n; i++) {
		newNode = find_smallest_time(newNode, visit, dist_v2);
		if (newNode == -1) break;
		visit[newNode] = 1;
		for (int j = 1; j <= n; j++) {
			if (visit[j] == 1) continue;
			if (dist_v2[j] > dist_v2[newNode] + map[newNode][j])
				dist_v2[j] = dist_v2[newNode] + map[newNode][j];
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	int a = 0, b = 0, c = 0;
	int v1 = 0, v2 = 0;
	cin >> n >> e;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = none;
		}
	}

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
	}

	cin >> v1 >> v2;

	q.push(make_pair(v1, 0));
	Dijkstra_v1(v1);

	q.push(make_pair(v2, 0));
	Dijkstra_v2(v2);

	if (dist_v1[v2] == none ) {
		cout << -1;
		return 0;
	}
	else {
		if (dist_v1[1] + dist_v2[n] < dist_v1[n] + dist_v2[1] ) {
			ans = dist_v1[1] + dist_v1[v2] + dist_v2[n];
			// 1 - v1 - v2 - n 선택
		}
		else if (dist_v1[1] + dist_v2[n] >= dist_v1[n] + dist_v2[1]) {
			ans = dist_v2[1] + dist_v1[v2] + dist_v1[n];
			// 1 - v2 - v1 - n 선택
		}
		cout << ans;
		return 0;
	}

	cout << -1;

	return 0;
}
