//1번: 일곱난쟁이
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int arr[9] = { 0, };
int visit[9] = { 0, };
priority_queue <int, vector<int>, greater<int> > pq;
int dfs(int count, int idx, int sum) {
	if (pq.empty()) {
		if (sum + arr[idx] <= 100 && visit[idx] == 0 && count <= 7) {
			visit[idx] = 1;
			sum += arr[idx];
			count++;
		}
		if (count == 7 && sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (visit[i] == 1)
					pq.push(arr[i]);
			}
			return 0;
		}
		for (int i = 0; i < 9; i++) {
			if (visit[i] == 0 && sum + arr[i] <= 100) {
				dfs(count, i, sum);
				visit[i] = 0;
			}
		}
	}
	return 0;
}
int main(void) {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 9; i++) {
		if (pq.empty()) {
			memset(visit, 0, 9);
			dfs(0, i, 0);
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << pq.top() << endl;
		pq.pop();
	}
	return 0;
}
