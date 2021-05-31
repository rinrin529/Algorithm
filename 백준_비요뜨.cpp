#include <iostream>
#define NUM 1000000007
using namespace std;
long long pow(long long a, long long b) {
	if (b == 0) {
		return 1;
	}
	else if (b % 2 == 0) {
		long long mul = pow(2, b / 2);
		return (mul * mul) % NUM;
	}
	else {
		long long mul = pow(a, b / 2);
		return a * ((mul * mul) % NUM) % NUM;
	}
}
int main(void) {
	int t = 0;
	long long n = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		long long tmp = 1;
		long long answer = 1;
		if (n == 1) {
			cout << 1 << '\n';
		}
		else {
			long long answer = pow(2, n - 2);
			cout << answer << '\n';
		}
	}
	return 0;
}
