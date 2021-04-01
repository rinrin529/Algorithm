#include <iostream>
#include <vector>
using namespace std;
vector <int> robot;
int n = 0, k = 0;
int strong[202] = { 0, };	// 1 ~ 2N
int robot_con[202] = { 0, };
int up = 0;
int down = 0;
void rotate() {
	up--;
	down--;
	if (up == 0) {
		up = 2*n;
	}
	if (down == 0) {
		down = 2*n;
	}
}
void move_robot() {
	for (int i = 0; i < robot.size(); i++) {	// 로봇 이동
		int idx = robot[i];
		int new_idx = 0;
		if (idx == 2 * n) {
			new_idx = 1;
		}
		else {
			new_idx = idx + 1;
		}
		if (robot_con[new_idx] == 0 && strong[new_idx] > 0) {
			strong[new_idx]--;
			robot[i] = new_idx;	// 이동
			robot_con[new_idx] = 1;
			robot_con[idx] = 0;
			if (strong[new_idx] == 0) {
				k--;
			}
		}
	}
}
void check_robot_down() { // 로봇 땅에 내려놓기
	int befo_down_idx = 0;
	if (down - 1 == 0) {
		befo_down_idx = 2 * n;
	}
	else {
		befo_down_idx = down - 1;
	}
	for (int i = 0; i < robot.size(); i++) {
		int idx = robot[i];
		if (idx == befo_down_idx) {
			robot.erase(robot.begin() + i);
			robot_con[idx] = 0;
		}
	}
}
void put_robot() { // 로봇 컨베이어에 올려놓기
	if (robot_con[up] == 0 && strong[up] > 0) {
		strong[up]--;
		robot_con[up] = 1;
		robot.push_back(up);
		if (strong[up] == 0) {
			k--;
		}
	}
}
int main(void) {
	int answer = 1;
	cin >> n >> k;
	for (int i = 1; i <= 2 * n; i++) {
		cin >> strong[i];
	}
	up = 1;
	down = up + n;
	while (1) {
		rotate();
		check_robot_down();
		move_robot();
		check_robot_down();
		put_robot();
		if (k <= 0) {
			break;
		}
		answer++;
	}
	cout << answer;
	return 0;
}
