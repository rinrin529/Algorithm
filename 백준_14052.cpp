#include <iostream>
#include <queue>
using namespace std;
   
char arr[9][9] = { 0 };
char lab[9][9] = { 0 };
int zero_point[2][70] = { 0 };
int total = 0;
int first = 0;
queue <pair<int, int>> q;
int N = 0, M = 0;

int arr_check(int n, int m);
void copy_lab();


int main(void) {
	int count = 0;
	cin >> N >> M;
	if (N < 3 || M > 8) {
		return 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cin >> lab[i][j];
	}
	int b = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (lab[i][j] == '0') { 
				zero_point[0][b] = i;
				zero_point[1][b] = j;
				b++;
			}
		}
	}

	for (int i = 0; i < b - 2; i++) {
		for (int j = i + 1; j < b - 1; j++) {
			for (int k = j + 1; k < b; k++) {
				copy_lab();

 				arr[zero_point[0][i]][zero_point[1][i]] = '1';
				arr[zero_point[0][j]][zero_point[1][j]] = '1';
				arr[zero_point[0][k]][zero_point[1][k]] = '1';

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (arr[i][j] == '2') {
							q.push(make_pair(i, j));
						}
					}
				}
				int n = 0, m = 0;
				while (!q.empty()) {
					n = q.front().first;
					m = q.front().second;
					q.pop();

					if (arr[n - 1][m] == '0') {
						if (arr_check(n - 1, m)) {
							arr[n - 1][m] = '2';
							q.push(make_pair(n - 1, m));
						}
					}
					if (arr[n + 1][m] == '0') {
						if (arr_check(n + 1, m)) {
							arr[n + 1][m] = '2';
							q.push(make_pair(n + 1, m));
						}
					}
					if (arr[n][m - 1] == '0') {
						if (arr_check(n, m - 1)) {
							arr[n][m - 1] = '2';
							q.push(make_pair(n, m - 1));
						}
					}
					if (arr[n][m + 1] == '0') {
						if (arr_check(n, m + 1)) {
							arr[n][m + 1] = '2';
							q.push(make_pair(n, m + 1));
						}
					}
				}

				count = 0;

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (arr[i][j] == '0') {
							count++;
						}
					}
				}
				if (first == 0) {
					total = count;
					first = 1;
				}
				else {
					if (count>total) {
						total = count;
					}
				}
			}
		}
	}
	cout << total << endl;

	return 0;
}

int arr_check(int n, int m)
{
	if (n > N || n == -1 || m == -1 || m > M) {
		return -1;
	}
	else {
		return 1;
	}
}

void copy_lab()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			arr[i][j] = lab[i][j];
	}
}
