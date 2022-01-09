#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int parent[10001] = { 0, };
int v = 0, e = 0;

int find_parent(int a) { // 부모 찾기
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find_parent(parent[a]);
}

void set_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int is_cycle(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a == b) {
		return 1;
	}
	else {
		return -1;
	}
}

int main(void) {
	long long answer = 0;
	priority_queue <pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> weight;
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	int a = 0, b = 0;
	long long wei = 0;
	for (int i = 1; i <= e; i++) {
		cin >> a >> b >> wei;
		weight.push({ wei,{a,b} });
	}
	for (int i = 0; i < v - 1; ) {
		a = weight.top().second.first;
		b = weight.top().second.second;
		wei = weight.top().first;
		weight.pop();
		if (is_cycle(a, b) < 0) {
			set_parent(a, b);
			answer += wei;
			i++;
		}
	}
	cout << answer;
	return 0;
}
