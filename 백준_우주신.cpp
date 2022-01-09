#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
int n = 0, m = 0;
vector<pair<int, int>> xy;
priority_queue <pair<double,pair<int,int>>,vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> lines;
int parent[1002] = { 0, };

int get_parent(int a) { // a 노드의 부모 찾기
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = get_parent(parent[a]);
}

void union_parent(int a, int b) { // 부모 설정
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int is_cycle(int a, int b) { // 사이클 찾기
	a = get_parent(a);
	b = get_parent(b);
	if (a != b) {
		return -1;
	}
	else {
		return 1;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double answer = 0;
	int x = 0, y = 0;
	int a = 0, b = 0;

	cin >> n >> m;
	xy.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		xy.push_back({ x,y });
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		union_parent(a, b);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double dx = pow(xy[i].first - xy[j].first, 2);
			double dy = pow(xy[i].second - xy[j].second, 2);
			double cal = sqrt(dx + dy);
			lines.push({ cal, {i, j}});
		}
	}
	
	while (!lines.empty()) {
		int a = lines.top().second.first;
		int b = lines.top().second.second;
		double dist = lines.top().first;
		lines.pop();
		if (is_cycle(a, b) < 0) {
			union_parent(a, b);
			answer += dist;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << answer;
	return 0;
}
