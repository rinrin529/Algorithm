#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int row = 5;
int col = 5;
int dir_r[4] = { -1,0,1,0 };  // U(1) R(10) D(100) L(1000)  비트 연산
int dir_c[4] = { 0,1,0,-1 };  // U R D L

int check_range(int new_row, int new_col) {
	if (new_row >= 0 && new_row <= 10 && new_col >= 0 && new_col <= 10) {
		return 1;
	}
	else {
		return 0;
	}
}

int solution(const char* dirs) {
	int answer = 0;
	int size = strlen(dirs);    // sizeof(dirs)/sizeof(char) 하면 틀림
	int new_row = 0;
	int new_col = 0;
	int map[11][11] = { 0, };
	unsigned char dir = 0;

	for (int i = 0; i < size; i++) {
		if (dirs[i] == 'U') {
			new_row = row + dir_r[0];
			new_col = col + dir_c[0];
			dir = 1;
		}
		else if (dirs[i] == 'R') {
			new_row = row + dir_r[1];
			new_col = col + dir_c[1];
			dir = 2;
		}
		else if (dirs[i] == 'D') {
			new_row = row + dir_r[2];
			new_col = col + dir_c[2];
			dir = 4;
		}
		else {   // L
			new_row = row + dir_r[3];
			new_col = col + dir_c[3];
			dir = 8;
		}
		if (check_range(new_row, new_col)) {
			int check = map[new_row][new_col] & dir;
			if (check != dir) {
				map[new_row][new_col] += dir;
				if (dir == 1) { // U - D
					map[row][col] += 4;
				}
				else if (dir == 2) { // R - L
					map[row][col] += 8;
				}
				else if (dir == 4) { // D - U
					map[row][col] += 1;
				}
				else { // L - R
					map[row][col] += 2;
				}
				answer++;
			}
			row = new_row;
			col = new_col;
		}
	}

	return answer;
}
