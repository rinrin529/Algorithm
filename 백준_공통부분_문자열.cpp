#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dp[4000][4000] = { 0, };
	int max = 0;
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j]) {
				if (i - 1 >= 0 && j - 1 >= 0) {
					dp[i][j] = (dp[i - 1][j - 1] + 1);
				}
				else {
					dp[i][j] = 1;
				}
				if (dp[i][j] > max) {
					max = dp[i][j];
				}
			}
		}
	}
	cout << max;

	return 0;
}
