#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	vector <int> v;
	int n = 0;
	int dp[10005] = { 0, };
	int tmp = 0;
	cin >> n;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	dp[1] = v[1];
	if (n > 1) {
		dp[2] = v[1] + v[2];
	}
	if (n > 2) {
		for (int i = 3; i <= n; i++) {
			dp[i] = max(dp[i - 3] + v[i] + v[i - 1], dp[i - 2] + v[i]);
			dp[i] = max(dp[i], dp[i - 1]);
		}
	}
	cout << dp[n];
	return 0;
}
