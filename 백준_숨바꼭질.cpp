#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n = 0, k = 0;
	int visit[200005] = { 0, };
	
	cin >> n >> k;

	visit[n] = 1;
	queue <pair<int,int>> q;
	q.push({ n, 0 });

	while (!q.empty()) {
		int subin = q.front().first;
		int time = q.front().second;
		q.pop();

		if (subin == k) {
			cout << time;
			return 0;
		}

		if (subin + 1 <= 200000) {
			if (visit[subin + 1] == 0) {
				visit[subin + 1] = 1;
				q.push({ subin + 1, time + 1 });
			}
		}
		if (subin - 1 >= 0) {
			if (visit[subin - 1] == 0) {
				visit[subin - 1] = 1;
				q.push({ subin - 1, time + 1 });
			}
		}
		if (subin * 2 <= 200000) {
			if (visit[subin * 2] == 0) {
				visit[subin * 2] = time + 1;
				q.push({ subin * 2, time + 1 });
			}
		}
	}
	return 0;
}
