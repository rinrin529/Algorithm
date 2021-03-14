#include <stdio.h>
#include <stdlib.h>
int visit[101][101] = { 0, };
int count = 1;
int dir_r[4] = { -1,0,+1,0 };
int dir_c[4] = { 0,+1,0,-1 };
char arr[102][102] = { 0, };
void dfs(int row, int col,int n) {
	if (row == n-1 && col == n-1)
		return;
	for (int i = 0; i < 4; i++) {
		int new_r = row + dir_r[i];
		int new_c = col + dir_c[i];
		if (new_r < n && new_r >= 0 && new_c < n && new_c >= 0) {
			if (visit[new_r][new_c] == 0) {	
				if (arr[row][col] == arr[new_r][new_c]) {	// 같은 색
					visit[new_r][new_c] = visit[row][col];
					dfs(new_r, new_c, n);
				}
			}
		}
	}
}
int main(void) {
	int n = 0;
	char ch = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1c", &arr[i][j]);
			if (arr[i][j] == '\n') {
				j--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				visit[i][j] = count;
				dfs(i, j, n);
				count++;
			}
		}
	}
	int num_n = count - 1;
	count = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
			if (arr[i][j] == 'G')
				arr[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0) {
				visit[i][j] = count;
				dfs(i, j, n);
				count++;
			}
		}
	}
	int num_y = count - 1;
	printf("%d %d", num_n, num_y);
	return 0;
}
