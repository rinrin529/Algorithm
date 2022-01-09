#include <string>
#include <vector>
#include <iostream>
using namespace std;
int map[12][12] = { 0, };
int been_col[12] = { 0, };
int dir_r[4] = { -1,1,1,-1 };
int dir_c[4] = { 1,1,-1,-1 };
int answer = 0;
int can_attack(int row, int col,int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				int r = i;
				int c = j;
				for (int k = 0; k < 4; k++) {
					for (int l = 1; l < n; l++) {
						int new_r = r + (dir_r[k] * l);
						int new_c = c + (dir_c[k] * l);
						if (new_r == row && new_c == col) {
							return 1;
						}
						if (new_r < 0 || new_r >= n || new_c < 0 || new_c >= n) {
							break;
						}
					}
				}
			}
		}
	}
	return -1;
}
void put_queen(int befo_r, int count, int n) {
	if (count == n) {
		answer++;
		return;
	}
	for (int j = 0; j < n; j++) {
		if (map[befo_r+1][j] == 0 && been_col[j] == 0) {
			if (can_attack(befo_r + 1, j, n) < 0) {
				map[befo_r + 1][j] = 1;
				been_col[j] = 1;
				put_queen(befo_r + 1, count + 1, n);
				map[befo_r + 1][j] = 0;
				been_col[j] = 0;
			}
		}
	}
}
int solution(int n) {
	for (int j = 0; j < n; j++) {
		map[0][j] = 1;
		been_col[j] = 1;
		put_queen(0, 1, n);
		been_col[j] = 0;
		map[0][j] = 0;
	}
	return answer;
}
