#include <iostream>
#include <queue>
using namespace std;
queue <int> q;
int n = 0;
int arr[16][2];
int total_cnt[16] = { 0, };
int check_do(int a, int before);
int cnt = 0;

int main(void) {

	cin >> n;
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int day = 1; day < n + 1; day++) {
		if (check_do(day, day)) {
			cnt = arr[day][1];
			if (total_cnt[day] < cnt) {
				total_cnt[day] = cnt;
			}
			q.push(day);
			while (!q.empty()) {
				int before = q.front();
				q.pop();
				for (int i = before + 1; i < n + 1; i++) {
					if (check_do(i, before)) {
						q.push(i);
						cnt = total_cnt[before] + arr[i][1];
						if (total_cnt[i] < cnt) {
							total_cnt[i] = cnt;
						}
					}
				}
			}
		}
	}
	int output = 0;
	for (int k = 1; k < 16; k++) {
		if (total_cnt[k] > output)
			output = total_cnt[k];
	}
	cout << output;

	return 0;
}

int check_do(int next, int before)
{
	if (next == before) {
		if ((arr[next][0] + next) < n + 2) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if ((arr[next][0] + next) < n + 2 && (before + arr[before][0] <= next)) {
			return 1;
		}
		else {
			return 0;
		}
	}
}