#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int crush = 0, number = 1;
	int n = 0, h = 0;
	int num = 0;
		
	cin >> n >> h;
	vector <int> total(h+1, 0);
	vector <int> jong(h+1, 0);
	vector <int> suk(h + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (i % 2 == 0) {
			suk[num]++;
		}
		else {
			jong[h - num + 1 ]++;
		}	
	}
	for (int i = h; i > 1; i--) {
		suk[i-1] += suk[i];
	}
	for (int i = 2; i <= h; i++) {
		jong[i] += jong[i - 1];
	}
	for (int i = 1; i <= h; i++) {
		total[i] = suk[i] + jong[i];
	}
	sort(total.begin(), total.end());
	crush = total[1];
	for (int i = 2; i <= h; i++) {
		if (total[i] == crush) {
			number++;
		}
		else {
			break;
		}
	}
	cout << crush << " " << number;
	return 0;
}
