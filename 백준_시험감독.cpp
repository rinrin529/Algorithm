#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n = 0, b = 0, c = 0;
	long long num = 0;
	long long answer = 0;
	cin >> n;
	vector <long long> a;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		answer += 1;
		long long min = 0;
		long long max = a[i] / c;
		long long mid = (min + max) / 2;
		if (a[i] > 0) {
			while (min <= max) {
				if (mid*c > a[i]) {
					max = mid - 1;
				}
				else if(mid*c < a[i]) {
					min = mid + 1;
				}
				else {
					break;
				}
				mid = (min + max) / 2;
			}
			answer += min;
		}
	}
	cout << answer;
	return 0;
}
