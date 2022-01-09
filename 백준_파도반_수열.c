#include <stdio.h>
int main(void) {
	int t = 0;
	long long dp[101] = { 0, };
	long long answer[1000] = { 0, };
	scanf("%d", &t);
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i <= 100; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}
	for (int i = 0; i < t; i++) {
		int n = 0;
		scanf("%d", &n);
		answer[i] = dp[n];
	}
	for (int i = 0; i < t; i++) {
		printf("%ld\n", answer[i]);
	}
	return 0;
}
