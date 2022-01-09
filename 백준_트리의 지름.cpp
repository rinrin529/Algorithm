#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n = 0;
vector <pair<int, int>> child[10003];
int ans_check = 0;
void dfs(int root, int sum) {
	if (child[root].size() == 0) {
		if (sum > ans_check) {
			ans_check = sum;
		}
		return;
	}
	for (int i = 0; i < child[root].size(); i++) {
		dfs(child[root][i].first, sum + child[root][i].second);
	}
}
int main(void) {
	int a = 0, b = 0, c = 0;
	int answer = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		child[a].push_back({ b,c });
	}
	for (int root = 1; root <= n; root++) {
		if (child[root].size() >= 2) {
			priority_queue <int> sum;
			for (int i = 0; i < child[root].size(); i++) {
				ans_check = 0;
				dfs(child[root][i].first, child[root][i].second);
				sum.push(ans_check);
			}
			int total = 0;
			total += sum.top();
			sum.pop();
			total += sum.top();
			sum.pop();
			if (answer < total) {
				answer = total;
			}
		}
		else if (child[root].size() == 1) {
			ans_check = 0;
			dfs(child[root][0].first, child[root][0].second);
			int side = ans_check;
			if (answer < side ) {
				answer = side ;
			}
		}
	}
	cout << answer;
}
