#include <iostream>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0, k = 0;
	cin >> n >> k;
	int Eratos[1001] = { 0, };
	int num = 1;
	int last_num = 0;
	int count = 0;
	while (1) {
		if (count == k) {
			break;
		}
		num++;
		int cut = n / num;
		for (int i = 1; i <= cut; i++) {
			if (Eratos[num*i] == 0) {
				count++;
				Eratos[num*i] = count;
				last_num = num * i;
			}
			if (count == k) {
				break;
			}
		}
	}
	cout << last_num;
	return 0;
}
