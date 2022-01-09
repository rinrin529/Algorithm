#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int map[301][301] = { 0, };			// 빙산
int see_point[301][301] = { 0, };	// 바다와 닿은 면
int check_count(int row, int col) {	// 빙산의 갯수를 체크하는 함수
	int count = 0;
	int visit[301][301] = { 0, };
	queue <pair<int, int>> q;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] != 0) {
				q.push(make_pair(i, j));	// 시작점 찾기
				visit[i][j] = 1;
				count = 1;
				i = 400;
				j = 400;
			}
		}
	}
	while (!q.empty()) {
		if (count > 1) {
			return count;	// 최소 시간만 찾으면 된다
		}
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (r - 1 >= 0) {	// 위
			if (map[r - 1][c] != 0 && visit[r - 1][c] == 0) {
				q.push(make_pair(r - 1, c));
				visit[r - 1][c] = 1;
			}
		}
		if (r + 1 < row) {	// 아래
			if (map[r + 1][c] != 0 && visit[r + 1][c] == 0) {
				q.push(make_pair(r + 1, c));
				visit[r + 1][c] = 1;
			}
		}
		if (c + 1 < col) {	// 오른쪽
			if (map[r][c + 1] != 0 && visit[r][c + 1] == 0) {
				q.push(make_pair(r, c + 1));
				visit[r][c + 1] = 1;
			}
		}
		if (c - 1 >= 0) {	// 왼쪽
			if (map[r][c - 1] != 0 && visit[r][c - 1] == 0) {
				q.push(make_pair(r, c - 1));
				visit[r][c - 1] = 1;
			}
		}
		if (q.empty()) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					if (map[i][j] != 0 && visit[i][j] == 0) {
						count++;
						q.push(make_pair(i, j));	// 시작점 찾기
						visit[i][j] = 1;
						i = 400;
						j = 400;
					}
				}
			}
		}
	}
	return count;
}
void check_see_point(int row, int col) {	// 빙산 주변 바다가 닿은 면 갯수 체크
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] != 0) {
				int num = 0;
				if (i - 1 >= 0) {	// 위
					if (map[i - 1][j] == 0)
						num++;
				}
				if (i + 1 < row) {	// 아래
					if (map[i + 1][j] == 0)
						num++;
				}
				if (j + 1 < col) {	// 오른쪽
					if (map[i][j + 1] == 0)
						num++;
				}
				if (j - 1 >= 0) {	// 왼쪽
					if (map[i][j - 1] == 0)
						num++;
				}
				if (see_point[i][j] != num) {	// 업데이트
					see_point[i][j] = num;
				}
			}
		}
	}
}
void melt_mountain(int row, int col) {	// 빙산이 녹는 것을 수행하는 함수
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] != 0)
				map[i][j] -= see_point[i][j];
			if (map[i][j] < 0)
				map[i][j] = 0;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int answer = 0;
	int row = 0, col = 0;
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}

	check_see_point(row, col);

	while (1) {
		melt_mountain(row, col);
		check_see_point(row, col);
		answer++;
		int count = check_count(row, col);
		if (count > 1) {
			cout << answer;
			return 0;
			break;
		}
		if (count == 0) {
			cout << 0;
			return 0;
		}
	}
	return 0;
}
