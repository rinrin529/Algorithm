#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int t = 0, n = 0;
	vector <int> jusik;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int now = 0;
		int total = 0;
		for (int j = 1; j <= n; j++) {
			cin >> now;
			jusik.push_back(now);
		}
		long long int big = -1;
		long long int sum = 0;
		for (int j = n-1; j >= 0; j--) {
			if (big < jusik[j]) {
				big = jusik[j];
			}
			else {
				sum += big - jusik[j];
			}
		}
		cout << sum << '\n';
		jusik.clear();
	}
	return 0;
}
