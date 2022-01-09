#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int map[4][4][2] = { 0, };	// idx, dir (물고기 없으면 idx=0)
int fish[17][2] = { 0, };	// 죽으면 -1
int dir_r[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dir_c[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int shark[3] = { 0, };	// row, col, dir
int ans = 0;

int range_ok(int row, int col) {
	if (row >= 0 && row < 4 && col >= 0 && col < 4) {
		return 1;
	}
	return 0;
}

void move_fish() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i][0] != -1) {
			int row = fish[i][0];
			int col = fish[i][1];
			int dir = map[row][col][1];
			int a_dir = map[row][col][1];
			int move_end = 0;
			while (1) {
				if (move_end == 8) {	// 이동 못하면 그냥 그대로 있기
					a_dir = dir;
					break;
				}
				int new_r = row + dir_r[a_dir];
				int new_c = col + dir_c[a_dir];
				if (range_ok(new_r, new_c) == 1) {	// 범위 속함
					if (map[new_r][new_c][0] == 0) {	// 자리 비움
						if (!(new_r == shark[0] && new_c == shark[1])) { // 상어 없음/////////////////////////여기서 틀렸다
							map[new_r][new_c][0] = i;
							map[new_r][new_c][1] = a_dir;
							fish[i][0] = new_r;
							fish[i][1] = new_c;
							map[row][col][0] = 0;
							break;
						}
					}
					else {	// 생선이랑 자리 교환
						int b_num = map[new_r][new_c][0];
						int b_dir = map[new_r][new_c][1];
						map[new_r][new_c][0] = i;
						map[new_r][new_c][1] = a_dir;
						map[row][col][0] = b_num;
						map[row][col][1] = b_dir;
						fish[i][0] = new_r;
						fish[i][1] = new_c;
						fish[b_num][0] = row;
						fish[b_num][1] = col;
						break;
					}
				}
				a_dir += 1;
				move_end++;
				if (a_dir == 9) {
					a_dir = 1;
				}
			}
			
		}
	}
}

void move_shark(int sum) {
	move_fish();
	int row = shark[0];
	int col = shark[1];
	int dir = shark[2];
	int end_check = 1;
	int tmp_map[4][4][2] = { 0, };
	int tmp_shark[3] = { 0, };
	int tmp_fish[17][2] = { 0, };	// 죽으면 -1
	memcpy(tmp_map, map, sizeof(map));
	memcpy(tmp_shark, shark, sizeof(shark));
	memcpy(tmp_fish, fish, sizeof(fish));

	for (int i = 3; i >= 1; i--) {
		int new_r = row + (dir_r[dir] * i);
		int new_c = col + (dir_c[dir] * i);
		if (range_ok(new_r, new_c) == 1) {
			if (map[new_r][new_c][0] > 0) {
				end_check = 0;
				shark[0] = new_r;
				shark[1] = new_c;
				shark[2] = map[new_r][new_c][1];
				int fish_idx = map[new_r][new_c][0];
				map[new_r][new_c][0] = 0;
				fish[fish_idx][0] = -1;
				move_shark(sum + fish_idx);	////// dfs

				memcpy(map, tmp_map, sizeof(map));
				memcpy(shark, tmp_shark, sizeof(shark));
				memcpy(fish, tmp_fish, sizeof(fish));
			}
		}
	}
	if (end_check == 1) {
		if (ans < sum) {
			ans = sum;
		}
		return;
	}
}


int main(void) {
	int fish_num = 0, fish_dir = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> fish_num >> fish_dir;
			map[i][j][0] = fish_num; 
			map[i][j][1] = fish_dir;
			fish[fish_num][0] = i;
			fish[fish_num][1] = j;
		}
	}
	shark[0] = 0;
	shark[1] = 0;
	shark[2] = map[shark[0]][shark[1]][1];
	int fish_idx = map[shark[0]][shark[1]][0];
	map[shark[0]][shark[1]][0] = 0;
	fish[fish_idx][0] = -1;
	move_shark(fish_idx);

	cout << ans;
	return 0;
}
