#include <iostream>
#include <string>
using namespace std;
int map[64][64] = { 0, };
int n = 0;
string answer = "";
int all_same_number(int size, int row, int col) {
	int num = map[row][col];
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (map[i][j] != num) {
				return -1;
			}
		}
	}
	return num;
}
void do_function(int size, int row, int col) {
	int check = all_same_number(size, row, col);
	if (check == 1) {
		answer += '1';
	}
	else if (check == 0) {
		answer += '0';
	}
	else {
		answer += '(';
		int new_size = size / 2;
		for (int i = 0; i < 4; i++) {
			do_function(new_size, row, col);
			if (i == 0 || i == 2) {
				col += new_size;
			}
			if (i == 1) {
				row += new_size;
				col -= new_size;
			}
		}
		answer += ')';
	}
}
int main(void) {
	char temp[64][64] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp[i][j];
			map[i][j] = temp[i][j] - '0';
		}
	}
	do_function(n, 0, 0);
	cout << answer;
	return 0;
}
