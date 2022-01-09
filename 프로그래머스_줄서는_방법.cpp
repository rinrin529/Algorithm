#include <string>
#include <vector>
using namespace std;
long long dp[22] = { 0, };
int visit[22] = { 0, };
int get_last_num(int n, int num) {
	while (1) {
		if (visit[num] == 0) {
			break;
		}
		else {
			num--;
		}
		if (num < 1) {
			num = n;
		}
	}
	return num;
}
int get_num(int n, int num) {
	while (1) {
		if (num + 1 > n) {
			num = 0;
		}
		if (visit[num + 1] == 0) {
			num += 1;
			break;
		}
		else {
			num++;
		}
	}
	return num;
}
void get_dp(int n) {
	int num = 2;
	for (int i = n - 1; i > 0; i--) {
		dp[i] = dp[i + 1] * num;
		num++;
	}
}
vector<int> solution(int n, long long k) {
	vector<int> answer;
	dp[n] = 1;
	get_dp(n);
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (k >= dp[i]) {
			idx = i;
			break;
		}
	}
	if (k == dp[1]) { // ㅇㅖ외
		for (int i = n; i > 0; i--) {
			answer.push_back(i);
		}
		return answer;
	}
	for (int i = 1; i < idx-1; i++) {
		answer.push_back(i);
		visit[i] = 1;
	}
	int num = get_num(n, 0);
	while (1) {
		if (k - dp[idx] > 0) {
			k -= dp[idx];
			num = get_num(n, num);
		}
		else if (k - dp[idx] < 0) {
			visit[num] = 1;
			answer.push_back(num);
			num = get_num(n, 0);
			idx += 1;
		}
		else { // 마지막
			answer.push_back(num);
			visit[num] = 1;
			while (1) {
				if (answer.size() == n) {
					return answer;
				}
				num = get_last_num(n, n);
				answer.push_back(num);
				visit[num] = 1;
			}
		}
	}
	return answer;
}
