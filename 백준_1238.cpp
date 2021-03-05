/*
	1. 시간 효율성 줄이는 방법 : 거꾸로 생각하기
	다익스트라를 뒤짚어서 생각해야한다

	2. 계속해서 틀린 이유 : find_smallest_time 함수
	가장 최단 시간의 node idx를 찾는 부분에서 
	누적 time을 기반으로 해서 찾아야 했는데 map을 기반으로 해서 자꾸 틀렸다....
*/
#include <iostream>
#include <cstring>

using namespace std;
#define none 1000000

int map[1001][1001] = { 0, };   // row: 시작 점, col: 끝 점, data: 소요시간
int back_time[1001] = { 0, };
int go_time[1001] = { 0, };
int n = 0, m = 0, x = 0;

int find_smallest_time(int start, int* visit, int check) {
	int idx = -1;
	int time = none;

	if (check == 1) {  // x to node
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 1)continue;
			if (back_time[i] < time) {
				time = back_time[i];
				idx = i;
			}
		}
	}
	else { // node to x
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 1)continue;
			if (go_time[i] < time) {
				time = go_time[i];
				idx = i;
			}
		}
	}
	return idx;
}

void Node_to_X(int x) { // 각각 노드에서 x 까지 최단거리 구하기
	int visit[1001] = { 0, };
	int newNode = x;

	for (int i = 1; i <= n; i++)
		go_time[i] = none;

	for (int i = 1; i <= n; i++) {
		if (map[i][newNode] != none)
			go_time[i] = map[i][newNode];
	}
	go_time[newNode] = 0;
	visit[newNode] = 1;

	for (int i = 0; i < n; i++) {
		newNode = find_smallest_time(newNode, visit, 0);
		if (newNode == -1) break;
		visit[newNode] = 1;
		for (int j = 1; j <= n; j++) {
			if (visit[j] == 1) continue;
			if (go_time[j] > go_time[newNode] + map[j][newNode])
				go_time[j] = go_time[newNode] + map[j][newNode];
		}
	}

	return;
}

void X_to_Node(int start) { //newNode 시작점 x 목적지 idx 처음 시작점
	int visit[1001] = { 0, };
	int newNode = start;

	for (int i = 1; i <= n; i++)
		back_time[i] = none;

	for (int i = 1; i <= n; i++) {
		if (map[newNode][i] != none)
			back_time[i] = map[newNode][i];
	}
	back_time[newNode] = 0;
	visit[newNode] = 1;

	for (int i = 0; i < n; i++) {
		newNode = find_smallest_time(newNode, visit, 1);
		if (newNode == -1) break;
		visit[newNode] = 1;
		for (int j = 1; j <= n; j++) {
			if (visit[j] == 1) continue;
			if (back_time[j] > back_time[newNode] + map[newNode][j])
				back_time[j] = back_time[newNode] + map[newNode][j];
		}
	}

	return;
}

int main(void) {
	int a = 0, b = 0, c = 0;
	int ans = 0;

	cin >> n >> m >> x;

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=n; j++) {
			map[i][j] = none;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (map[a][b] > c)
			map[a][b] = c;
	}

	Node_to_X(x); // 각각 노드에서 x 까지 최단거리 구하기
	X_to_Node(x); // x에서 모든 노드까지 최단 거리 구하기

	for (int i = 1; i <=n; i++) {
		if (go_time[i] + back_time[i] > ans) {
			ans = go_time[i] + back_time[i];
		}
	}

	cout << ans;
	return 0;
}
