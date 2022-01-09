#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	long long k = 0, n = 0;
	long long tmp = 0;
	long long min = 1, max = 0;
	long long vsize = 0;
	vector <long long> lines;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		vsize++;
		lines.push_back(tmp);
		if (tmp > max) {
			max = tmp;
		}
	}
	while (min <= max) {
		long long mid = (min + max) / 2;
		long long cnt = 0;
		for (long long i = 0; i < vsize; i++) {
			cnt += lines[i] / mid;
			if (cnt > n) {
				break;
			}
		}
		if (cnt >= n) {
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
	}
	cout << max;
	return 0;
}
