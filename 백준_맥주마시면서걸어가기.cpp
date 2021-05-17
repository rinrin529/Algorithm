#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t = 0, n = 0;
int house_x = 0, house_y = 0;
int party_x = 0, party_y = 0;
vector <pair<int, int>> store;
bool bfs() {
	int visit[103] = { 0, };
	queue <pair<int, int>> q;
	q.push({ house_x, house_y });
	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();
		if (abs(now_x - party_x) + abs(now_y - party_y) <= 1000) {
			return true;
		}
		for (int i = 0; i < n; i++) {
			int dist = abs(store[i].first - now_x) + abs(store[i].second - now_y);
			if (dist <= 1000 && visit[i] == 0) {
				visit[i] = 1;
				q.push({ store[i].first,store[i].second });
			}
		}
	}
	return false;
}
int main(void) {
	vector<int> ans;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> house_x >> house_y;
		int store_x = 0, store_y = 0;
		store.clear();
		for (int j = 0; j < n; j++) {
			cin >> store_x >> store_y;
			store.push_back({ store_x, store_y });
		}
		cin >> party_x >> party_y;
		if (bfs() == true) {
			ans.push_back(1);
		}
		else {
			ans.push_back(-1);
		}
	}
	for (int i = 0; i < t; i++) {
		if (ans[i] == 1) {
			cout << "happy" << endl;
		}
		else {
			cout << "sad" << endl;
		}
	}
	return 0;
}
