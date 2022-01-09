#include <iostream>
#include <vector>
using namespace std;
int n = 0;
int answer = 0;
vector <pair<int, int>> v;	// { day, pay }

void dfs(int sum, int day) {
	if (day + v[day].first == n + 1) {
		sum += v[day].second;
		if (sum > answer) {
			answer = sum;
		}
		return;
	}
	if (day + v[day].first > n + 1) {
		if (sum > answer) {
			answer = sum;
		}
		return;
	}
	sum += v[day].second;
	int workDay = v[day].first;
	for (int i = day+workDay; i <= n; i++) {
		dfs(sum, i);
	}
}

int main(void) {
	int day = 0, pay = 0;
	cin >> n;
	v.push_back({ 0,0 });
	for (int i = 0; i < n; i++) {
		cin >> day >> pay;
		v.push_back({ day, pay });
	}
	for (int i = 1; i <= n; i++) {
		dfs(0, i);
	}
	cout << answer;
	return 0;
}
