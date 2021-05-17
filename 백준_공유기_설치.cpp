#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0, c = 0;
	int answer = -1;
	vector <int> x;
	cin >> n >> c;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		x.push_back(tmp);
	}
	sort(x.begin(), x.end());
	int min_d = 1;
	int max_d = x.back();

	while (min_d <= max_d) {
		int count = 1; // 공유기 설치 갯수
		int befo = 0;  // 이전 idx
		int mid = (min_d + max_d) / 2;  // 사이 거리

		for (int i = 1; i < n; i++) {
			if (x[i] - x[befo] >= mid) {
				befo = i;
				count++;
			}
		}
		if (count >= c) {
			min_d = mid + 1;
		}
		else {
			max_d = mid - 1;
		}
		if (answer < mid && count >= c) {
			answer = mid;
		}
	}

	cout << answer;
	return 0;
}
