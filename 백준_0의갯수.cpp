#include <iostream>
#include <string>
using namespace std;
int count_zero(int a, int b) {
	int count = 0;
	for (int num = a; num <= b; num++) {
		string snum = to_string(num);
		for (int i = 0; i < snum.size(); i++) {
			if (snum[i] == '0') {
				count += 1;
			}
		}
	}
	return count;
}
int main(void) {
	int t = 0;
	int ans[50] = { 0, };
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		ans[i] = count_zero(a, b);
	}
	for (int i = 0; i < t; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
