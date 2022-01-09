#include <iostream>
#include <vector>
using namespace std;
int k = 0;
int map[4][8] = { 0, };
int turn_number[4][3] = { {1,2,3},{1,3,4},{1,0,3},{2,1,0} };
vector <int> meet_idx[4];

int turn_ok(int left, int right) {	// 회전 가능하면 1 반환
	if (map[left][meet_idx[left][1]] == map[right][meet_idx[right][0]]) {
		return -1;
	}
	else {
		return 1;
	}
}

void turn(int number, int dir) {
	int add = 0;
	if (dir == 1) {	// 시계방향 회전
		add = -1;
	}
	else {	// 반시계 방향 회전
		add = 1;
	}

	for (int i = 0; i < 2; i++) {
		meet_idx[number][i] += add;
		if (meet_idx[number][i] == -1) {
			meet_idx[number][i] = 7;
		}
		if (meet_idx[number][i] == 8) {
			meet_idx[number][i] = 0;
		}
	}
}

int main(void) {
	char temp[4][8] = { 0, };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> temp[i][j];
			map[i][j] = temp[i][j] - '0';
		}
	}
	cin >> k;
	int number = 0, dir = 0;

	meet_idx[0].push_back(-1);
	meet_idx[0].push_back(2);
	meet_idx[1].push_back(6);
	meet_idx[1].push_back(2);
	meet_idx[2].push_back(6);
	meet_idx[2].push_back(2);
	meet_idx[3].push_back(6);
	meet_idx[3].push_back(-1);

	for (int i = 0; i < k; i++) {
		cin >> number >> dir;

		if (number-1 == 0) {
			if (turn_ok(0, 1) == 1) {
				if (turn_ok(1, 2) == 1) {
					if (turn_ok(2, 3) == 1) {
						turn(0, dir);
						turn(1, -(dir));
						turn(2, dir);
						turn(3, -(dir));
					}
					else {
						turn(0, dir);
						turn(1, -(dir));
						turn(2, dir);
					}
				}
				else {
					turn(0, dir);
					turn(1, -(dir));
				}
			}
			else {
				turn(0, dir);
			}
		}
		else if (number - 1 == 1) {
			if (turn_ok(0, 1) == 1) {
				turn(0, -(dir));
			}
			if (turn_ok(1, 2) == 1) {
				if (turn_ok(2, 3) == 1) {	// 전부 다 회전
					turn(1, dir);
					turn(2, -(dir));
					turn(3, dir);
				}
				else {	// 2까지만 회전
					turn(1, dir);
					turn(2, -(dir));
				}
			}
			else {	// 2부터 회전 안함
				turn(1, dir);
			}
		}
		else if (number - 1 == 2) {
			if (turn_ok(2, 3) == 1) {
				turn(3, -(dir));
			}
			if (turn_ok(1, 2) == 1) {
				if (turn_ok(0, 1) == 1) {
					turn(2, dir);
					turn(1, -(dir));
					turn(0, dir);
				}
				else {
					turn(2, dir);
					turn(1, -(dir));
				}
			}
			else {
				turn(2, dir);
			}
		}
		else {
			if (turn_ok(2, 3) == 1) {
				if (turn_ok(1, 2) == 1) {
					if (turn_ok(0, 1) == 1) {
						turn(3, dir);
						turn(2, -(dir));
						turn(1, dir);
						turn(0, -(dir));
					}
					else {
						turn(3, dir);
						turn(2, -(dir));
						turn(1, dir);
					}
				}
				else {
					turn(3, dir);
					turn(2, -(dir));
				}
			}
			else {
				turn(3, dir);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		int idx = meet_idx[i][1] - 2;
		if (idx < 0) {
			idx += 8;
		}
		if (i == 3) {
			idx = meet_idx[i][0] + 2;
			if (idx >= 8) {
				idx -= 8;
			}
		}
		if (map[i][idx] == 1) {
			if (i == 0) {
				answer += 1;
			}
			else if (i == 1) {
				answer += 2;
			}
			else if (i == 2) {
				answer += 4;
			}
			else {
				answer += 8;
			}
		}
	}
	cout << answer;
	return 0;
}
