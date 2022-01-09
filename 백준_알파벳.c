#include <stdio.h>
int dir_r[4] = { -1,0,1,0 };
int dir_c[4] = { 0,1,0,-1 };
char arr[25][25] = { 0, };
int visit[50] = { 0, };
int r = 0, c = 0;
int answer = 0;
void dfs(int *visit, int count, int row, int col ) {
	int end_check = 1;
	for (int i = 0; i < 4; i++) {
		int new_r = row + dir_r[i];
		int new_c = col + dir_c[i];
		if (new_r >= 0 && new_c >= 0 && new_r < r&& new_c < c) {
			if (visit[arr[new_r][new_c] - '0'] == 0) {
				visit[arr[new_r][new_c] - '0'] = 1;
				dfs(visit, count + 1, new_r, new_c);
				visit[arr[new_r][new_c] - '0'] = 0;
				end_check = 0;
			}
		}
	}
	if (end_check == 1) {
		if(answer < count) {
			answer = count;
		}
		return;
	}
}
int main(void) {
	scanf("%d %d", &r, &c);
	for (int row = 0; row < r; row++) {
		scanf("%s", &arr[row]);
	}
	visit[arr[0][0]-'0'] = 1;
	dfs(visit, 1, 0, 0);
	printf("%d", answer);
	return 0;
}
