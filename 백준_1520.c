#include <stdio.h>

int answer = 0;
int map[502][502] = { 0, };
int dp[502][502] = { 0, };
int dir_r[4] = { -1,0,+1,0 };
int dir_c[4] = { 0,+1,0,-1 };

int dfs(int a, int b, int row, int col)
{
	if (a == row && b == col) return 1;
	if (dp[a][b] == -1) {
		dp[a][b] = 0;
		for (int k = 0; k < 4; k++) {
			int new_r = a + dir_r[k];
			int new_c = b + dir_c[k];
			if (map[new_r][new_c] != 0)
				if (map[a][b] > map[new_r][new_c]) 
					dp[a][b] += dfs(new_r, new_c, row, col);
		}
	}
	return dp[a][b];
}

int main(void) {
	int row = 0, col = 0;
	scanf("%d %d",&row, &col);
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			scanf("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}

	dfs(1, 1, row, col);
	printf("%d", dp[1][1]);
	return 0;
}
