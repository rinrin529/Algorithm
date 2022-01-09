#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int row = 0 , col = 0;
int map[501][501] = { 0, };
int tetro_idx[19][4][2] = {	// 각각 모양 좌표 전부  뽑기
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
	{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
	{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
	{{0, 0}, {1, 0}, {0, 1}, {0, 2}},
	{{0, 0}, {1, 0}, {2, 0}, {2, -1}},
	{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
	{{0, 0}, {1, 0}, {2, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
	{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	{{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
	{{0, 0}, {1, 0}, {0, 1}, {-1, 1}},
	{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	{{0, 0}, {0, 1}, {1, 1}, {-1, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {1, 1}},
};
int main() {
	cin >> row >> col;
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			cin >> map[y][x];
		}
	}
	int answer = 0;
	for (int i = 0; i < 19; i++) {
		for (int y = 0; y < row; y++) {
			for (int x = 0; x < col; x++) {
				int sum = 0;
				for (int t = 0; t < 4; t++) {
					int ny = y + tetro_idx[i][t][0];
					int nx = x + tetro_idx[i][t][1];
					if (ny < 0 || nx < 0 || ny >= row || nx >= col) {
						sum = 0;
						break;
					}
					sum += map[ny][nx];
				}
				answer = max(answer, sum);
			}
		}
	}
	cout << answer << endl;
	return 0;
}
