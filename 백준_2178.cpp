#include <iostream>
#include <queue>
using namespace std;
  
int inside_arr(int x, int y);
char arr[100][100] = { 0 };
int N = 0;
int M = 0;

int main(void) {
	int col = 0, row = 0;
	int count[100][100] = { 0 };
	int move_col[4] = { -1,1,0,0 };  //left, right, up, down
	int move_row[4] = { 0,0,-1,1 };

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	queue<pair<int, int>> q;
	q.push(make_pair(row, col));

	count[row][col] = 1;

	while (!q.empty()) {
		row= q.front().first;
		col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = row + move_row[i];
			int next_col = col + move_col[i];
			
			if (inside_arr(next_row,next_col)) {
				if ((count[next_row][next_col] == 0) && (arr[next_row][next_col] == '1')) {
					count[next_row][next_col] = count[row][col] + 1;
					q.push(make_pair(next_row, next_col));
				}
			}
		}
	}

	cout << count[N - 1][M - 1] << endl;
	return 0;
}

int inside_arr(int x, int y)
{
	if ((x > -1) && (x < N) && (y > -1) && (y < M)) {
		return 1;
	}
	else {
		return 0;
	}
} 
