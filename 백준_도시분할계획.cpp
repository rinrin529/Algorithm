#include <iostream>
#include <queue>
using namespace std;
int house_parent[100005] = { 0, };
int n = 0, m = 0;
priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int get_parent(int a) {
	if (house_parent[a] == a) {
		return a;
	}
	return house_parent[a] = get_parent(house_parent[a]);
}

void set_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) {
		house_parent[b] = a;
	}
	else {
		house_parent[a] = b;
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
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int a = 0, b = 0, c = 0;
	long long answer = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
	}

	for (int i = 1; i <= n; i++) {
		house_parent[i] = i;
	}

	for (int i = 1; i <= n - 2; ) {
		a = pq.top().second.first;
		b = pq.top().second.second;
		c = pq.top().first;
		pq.pop();
		if (is_cycle(a, b) == false) { // 네트워크 연결
			i += 1;
			answer += c;
			set_parent(a, b);
		}
	}

	cout << answer;
	return 0;
}
