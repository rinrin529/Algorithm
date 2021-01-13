#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n = 0, k = 0;
int w = 0, v = 0;
int dp[101][1000001];
vector <vector<int>> arr;

int knapsack(int pos, int k) {
	if (dp[pos][k] > 0)
		return dp[pos][k];

	if (pos == n)
		return 0;

	int ok = 0;
	if (k - arr[pos][0] >= 0) {
		ok = knapsack(pos + 1, k - arr[pos][0]) + arr[pos][1];
	}
	int no = knapsack(pos + 1, k);

	return dp[pos][k] = max(ok, no);
}

int main(void) {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		vector<int> wv;
		cin >> w >> v;
		wv.push_back(w);
		wv.push_back(v);
		arr.push_back(wv);
	}
	cout << knapsack(0, k);
	return 0;
}
