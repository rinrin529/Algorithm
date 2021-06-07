#include <iostream>
#include <queue>
using namespace std;
int com_parent[1005] = { 0, };
int n = 0, m = 0;
priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int get_parent(int a) {
	if (com_parent[a] == a) {
		return a;
	}
	return com_parent[a] = get_parent(com_parent[a]);
}

void set_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) {
		com_parent[b] = a;
	}
	else {
		com_parent[a] = b;
	}
}

bool is_cycle(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	int a = 0, b = 0, c = 0;
	int answer = 0;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
	}

	for (int i = 1; i <= n; i++) {
		com_parent[i] = i;
	}

	while (!pq.empty()) {
		a = pq.top().second.first;
		b = pq.top().second.second;
		c = pq.top().first;
		pq.pop();
		if (is_cycle(a, b) == false) { // 네트워크 연결
			answer += c;
			set_parent(a, b);
		}

		int check = get_parent(1);
		int end = 1;
		for (int i = 1; i <= n; i++) {
			if (check != get_parent(i)) {
				end = 0;
				break;
			}
		}

		if (end == 1) {
			break; // 네트워크 연결 종료
		}
	}
	cout << answer;
	return 0;
}
