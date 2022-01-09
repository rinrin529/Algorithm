#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int score[51] = { 0 }; 
int dices[10] = { 0, };
vector <int> red_map(33,0);
vector <int> blue_map(33, 0);
int ans = 0;
int player[4][3] = { 0, };
void init() {
	for (int i = 1; i <= 20; i++) {
		score[i] = (i * 2);
	}
	for (int i = 0; i < 20; i++) {
		red_map[i] = i + 1;
	}
	red_map[20] = 50;	// 50 == end

	blue_map[5] = 21;
	blue_map[21] = 22; score[21] = 13;
	blue_map[22] = 23; score[22] = 16;
	blue_map[23] = 24; score[23] = 19;
	
	blue_map[10] = 25; score[24] = 25;
	blue_map[25] = 26; score[25] = 22;
	blue_map[26] = 24; score[26] = 24;

	blue_map[15] = 27;
	blue_map[27] = 28; score[27] = 28;
	blue_map[28] = 29; score[28] = 27;
	blue_map[29] = 24; score[29] = 26;

	blue_map[24] = 30;
	blue_map[30] = 31; score[30] = 30;
	blue_map[31] = 20; score[31] = 35;
	blue_map[20] = 50; score[50] = 0;
}

int go_red_ok(int dice, int player_idx) {
	int next_point = player[player_idx][0];
	for (int i = 0; i < dice; i++) {
		next_point = red_map[next_point];
		if (next_point == 50) {
			player[player_idx][0] = next_point;
			return 1;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (player[i][0] == next_point) { 
			return 0; // 이동하려는 칸에 말이 이미 있으면 불가능
		}
	}
	player[player_idx][0] = next_point;
	if (blue_map[next_point] != 0) {
		player[player_idx][1] = 1;	// blue로 가야한다
	}
	player[player_idx][2] += score[next_point];
	return 1;
}

int go_blue_ok(int dice, int player_idx) {
	int next_point = player[player_idx][0];
	for (int i = 0; i < dice; i++) {
		next_point = blue_map[next_point];
		if (next_point == 50) {
			player[player_idx][0] = next_point;
			return 1;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (player[i][0] == next_point) {
			return 0; // 이동하려는 칸에 말이 이미 있으면 불가능
		}
	}
	player[player_idx][0] = next_point;
	player[player_idx][2] += score[next_point];
	return 1;
}

void dfs(int dice_idx, int player_idx, int count) {
	if (count == 10) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += player[i][2];
		}
		if (sum > ans) {
			ans = sum;
		}
		return;
	}

	for (int idx = 0; idx < 4; idx++) {
		if (player[idx][0] != 50) {
			int tmp_player[4][3] = { 0, };
			memcpy(tmp_player, player, sizeof(tmp_player));
			if (player[idx][1] == 0) {
				if (go_red_ok(dices[dice_idx + 1], idx) == 1) {
					dfs(dice_idx + 1, idx, count + 1);
					memcpy(player, tmp_player, sizeof(tmp_player));
				}
			}
			else {
				if (go_blue_ok(dices[dice_idx + 1], idx) == 1) {
					dfs(dice_idx + 1, idx, count + 1);
					memcpy(player, tmp_player, sizeof(tmp_player));
				}
			}
		}
	}
}

int main(void) {
	init();
	for (int i = 0; i < 10; i++) {
		cin >> dices[i];
	}
	go_red_ok(dices[0], 0);
	dfs(0, 0, 1);
	cout << ans;
	return 0;
}
