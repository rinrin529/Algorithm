#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <queue>

using namespace std;

int row[4] = { 0,-1,0,1 };
int col[4] = { -1,0,1,0 };
int town_cnt[700] = { 0, };
int map[26][26] = { 0, };
queue<pair<int, int>> q;
int fun_town(int n);
int check_near(int n, int i, int j);

int main(void) {
	int n = 0;
	char ch[26] = { 0, };
	int num = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch[j];
			map[i][j] = ch[j] - '0';
		}
	}

	num = fun_town(n);
	cout << num ;
	if (num != 0) {
		sort(town_cnt, town_cnt + num);

		for (int i = 0; i < num; i++)
			cout << endl << town_cnt[i];
	}
	else {
		cout << endl << 0;
	}

	return 0;
}

int fun_town(int n)
{
	int num = 0;
	int rr = 0, cc = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > 0) {
				if (check_near(n, i, j) > -1) {
					while (!q.empty()) {
						rr = q.front().first;
						cc = q.front().second;
						q.pop();
						if (map[rr][cc] > 0) {
							town_cnt[num]++;
							int p = check_near(n, rr, cc);
							if (p == 5) { // 주변에 다 방문
								map[rr][cc] = -1;
							}
							else if (p > -1) { // 주변에 방문 안한점 있음
								map[rr][cc] = -1;
							}
						}
					}
				}
				else {
					map[i][j] = -1;
					town_cnt[num]++;
				}
				num++;
			}
		}
	}
	return num;
}

int check_near(int n, int i, int j)
{
	int have_near_plus = 0;
	int have_near_minus = 0;

	int near_p = 0;
	for (int k = 0; k < 4; k++) {
		if ((i + row[k] > -1) && (i + row[k] < n) && (j + col[k] > -1) && (j + col[k] < n)) {
			if (map[i][j] == abs(map[i + row[k]][j + col[k]])) {
				if (map[i + row[k]][j + col[k]] > 0) {
					q.push(make_pair(i + row[k], j + col[k]));
					have_near_plus++;
				}
				else {
					have_near_minus++;
				}
			}
		}
	}

	if (have_near_plus != 0) { //주변에 아직 방문안한 단지 있음
		return 2;
	}
	else if (have_near_minus == 0) { //주변에 같은 단지 없음
		return -1;
	}
	else { //주변이 다 방문한 단지임
		return 5;
	}
}
