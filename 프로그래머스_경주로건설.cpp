#include <string>
#include <vector>
#include <queue>
using namespace std;
int dir_r[4] = { 0,0,1,-1 };
int dir_c[4] = { 1,-1,0,0 };
int d[4] = { 2,2,1,1 }; // 가로,가로, 세로,세로
int solution(vector<vector<int>> board) {
	int cost_map[28][28] = { 0, };
	int answer = 0;
	int size = board.size();
	queue<pair<pair<int, int>, pair<int, int>> > pq; // {{가격, 방향},{row, col}} (가로:2, 세로:1)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cost_map[i][j] = 999999;
		}
	}
	cost_map[0][0] = 0;
	if (board[1][0] == 0) {
		cost_map[1][0] = 100;
		pq.push({ {100,1}, {1,0} }); //(가로:2, 세로:1)
	}
	if (board[0][1] == 0) {
		cost_map[0][1] = 100;
		pq.push({ {100,2}, {0,1} });
	}
	
	while (!pq.empty()) {
		int row = pq.front().second.first;
		int col = pq.front().second.second;
		int dir = pq.front().first.second;
		int cost = pq.front().first.first;
		pq.pop();
		if (row == size - 1 && col == size - 1)
			continue;
		if (cost_map[row][col] < cost)
			continue;
		for (int i = 0; i < 4; i++) {
			int nextRow = row + dir_r[i];
			int nextCol = col + dir_c[i];
			int nextCost = 0;
			if (d[i] == dir) {
				nextCost = cost + 100;
			}
			else {
				nextCost = cost + 500 + 100;
			}
			if (nextRow >= 0 && nextRow < size && nextCol >= 0 && nextCol < size) {
				if (board[nextRow][nextCol] == 0) {
					if (cost_map[nextRow][nextCol] >= nextCost) {
						cost_map[nextRow][nextCol] = nextCost;
						pq.push({ {nextCost,d[i]},{nextRow, nextCol} }); //(가로:2, 세로:1)
					}
				}
			}
		}
	}
	return cost_map[size-1][size-1];
}
