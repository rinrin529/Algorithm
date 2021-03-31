#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int n = 0, m = 0;
	int row = 0;
	int col = 0;
	char map[51][51] = { 0 };
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int w_start = 0;
	int b_start = 0;
	int answer = 25000;
	while (row + 8 <= n) {
		col = 0;
		while (col + 8 <= m) {
			for (int i = row; i < row + 8; i++) {
				for (int j = col; j < col + 8; j++) {
					if ((i + j) % 2 == 0) {
						if (map[i][j] == 'W') {	// W로 시작
							b_start++;
						}
						else {
							w_start++;
						}
					}
					else {
						if (map[i][j] == 'W') {	// W로 시작
							w_start++;
						}
						else {
							b_start++;
						}
					}
				}
			}
 			answer = min(answer, b_start);
			answer = min(answer, w_start);
			b_start = 0;
			w_start = 0;
			col++;
		}
		row++;
	}
	if (answer == 25000) {
		cout << 0;
	}
	else {
		cout << answer;
	}
	return 0;
}
