#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> triangle) {
	int dp[501][501] = { 0, };
	int answer = 0;
	
	int height = triangle.size();
	dp[0][0] = triangle[0][0];
	for (int i = 1; i < height; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
			answer = max(answer, dp[i][j]);
		}
	}
	return answer;
}
