/*
  <시간 초과 해결 방법>
  bfs를 사용해서 랜덤 노드에서의 다른 노드까지 최대의 길이를 구할 때,
  각각의 노드에서 모두 bfs를 실행하지 않아도 먼저 수행한 노드에서 최대 거리가 나온 노드를 시작점으로 해서 bfs를 돌리면 구할 수 있다.
  2번만 수행해도 된다는 뜻
*/
#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <cstring>

using namespace std;
long unsigned int map[100001] = { 0, };
long unsigned int temp[100001] = { 0, };
queue <pair<int, long unsigned int>> node;
vector <pair<int, long unsigned int>> tree[100001];
queue <int> start;
long unsigned int ans = 0;
int visit[100001] = { 0, };

int bfs(int i) {
	int v = 0, d = 0;
	int Max_node = 0;
	node.push(make_pair(i, 0));
	start.push(i);
	visit[i] = 1;
	while (!node.empty()) { // BFS
		v = node.front().first; // 도착 노드
		d = node.front().second; // 거리
		temp[v] = temp[start.front()] + d; // i에서 도착노드 v까지의 total 거리, 즉 i -> start.front() -> v 이렇게 경로 설정

		if (map[v] < temp[v]) { // 가장 긴 거리로 update
			map[v] = temp[v];
			if (ans < map[v]) {
				ans = map[v];
				Max_node = v;
			}
		}
		node.pop();
		start.pop();
		for (int j = 0; j < tree[v].size(); j++) {
			if (visit[tree[v][j].first] == 0) {
				node.push(tree[v][j]);
				start.push(v);
				visit[tree[v][j].first] = 1;
			}
		}
	}
	memset(temp, 0, sizeof(temp));
	memset(visit, 0, sizeof(visit));
	return Max_node;
}

int main(void) {
	int Vnum = 0;
	int idx = 0;
	int v = 0;
	long unsigned int d = 0;
	cin >> Vnum;

	for (int i = 0; i < Vnum; i++) {
		cin >> idx;
		while (1) {
			cin >> v;
			if (v == -1)
				break;
			cin >> d;
			tree[idx].push_back(make_pair(v, d));
		}
	}
	int max_node = bfs(1);
	bfs(max_node);
	cout << ans;

	return 0;
}
