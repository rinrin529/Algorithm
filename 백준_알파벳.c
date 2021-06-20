#include <stdio.h>
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int main(void) {
	int t = 0;
	scanf("%d", &t);
	long long answer[100000] = { 0, };
	for (int p = 0; p < t; p++) {
		int c = 0;
		long long max_output = 0;
		scanf("%d", &c);
		long long arr[2][100000] = { 0, };
		for (int i = 0; i < c; i++) {
			scanf("%d", &arr[0][i]);
		}
		for (int i = 0; i < c; i++) {
			scanf("%d", &arr[1][i]);
		}
		long long dp[2][100000] = { 0, };
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		max_output = max(max_output, max(dp[0][0], dp[1][0]));
		for (int i = 1; i < c; i++) {
			if (i >= 2) {
				dp[0][i] = max(dp[1][i - 1], dp[0][i - 2]) + arr[0][i];
				dp[0][i] = max(dp[0][i], dp[1][i - 2] + arr[0][i]);
				dp[1][i] = max(dp[0][i - 1], dp[1][i - 2]) + arr[1][i];
				dp[1][i] = max(dp[1][i], dp[0][i - 2] + arr[1][i]);
			}
			else {
				dp[0][i] = dp[1][i - 1] + arr[0][i];
				dp[1][i] = dp[0][i - 1] + arr[1][i];
			}
			max_output = max(max_output, max(dp[0][i], dp[1][i]));
		}
		answer[p] = max_output;
	}
	for (int i = 0; i < t; i++) {
		printf("%ld\n", answer[i]);
	}
	return 0;
}
