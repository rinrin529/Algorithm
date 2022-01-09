#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int arr[32][32] = { 0, };
	int r = 0, c = 0, w = 0;
	int answer = 0;
	cin >> r >> c >> w;
	for (int i = 1; i < 31; i++) {
		arr[i][1] = 1;
		arr[i][i] = 1;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= i; j++) {
			if (j != 1 && j != i) {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	int count = 0;
	int check = 1;
	int row = r;
	int col = c;
	for (int i = r; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			if (count == w + 1) {
				i = 100;
				j = 100;
				break;
			}
			if (j != 1 && j != i) {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
			if (i == row && j == col) {
				answer += arr[i][j];
				count += 1;
				col += 1;
				if (count == check) {
					check += 1;
					count = 0;
					row += 1;
					col = c;
				}
				if (check == w + 1) {
					cout << answer;
					return 0;
				}
			}
		}
	}
	return 0;
}
