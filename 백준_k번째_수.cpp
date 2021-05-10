#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	long long n = 0, k = 0;
	cin >> n;
	cin >> k;
	long long low = 1;
	long long high = k;
	long long result = 0;
	
	while (low <= high) {
		int cnt = 0;
		long long mid = (low + high) / 2;
		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}
		if (cnt < k) {
			low = mid + 1;
		}
		else {
			result = mid;
			high = mid - 1;
		}
	}
	cout << result;
	return 0;
}
