#include <iostream>
#define findMin(a, b) a < b ? a:b

using namespace std;

int main(void) {
	int m = 0, n = 0;
	int start_n = 0, start_m = 0;
	int ans = 3000;
	char arr[51][51] = { 0, };
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int num_b = 0;
	int num_w = 0;

	while (start_n + 8 <= n ) {
		start_m = 0;
		while (start_m + 8 <= m) {
			for (int i = start_n; i < start_n + 8; i++) { // 행 체크
				for (int j = start_m; j < start_m + 8; j++) { // 열 체크
					if ((i + j) % 2 == 0) { //시작이 black
						if (arr[i][j] == 'B')
							num_w++;
						else
							num_b++;
					}
					else {
						if (arr[i][j] == 'B') //시작이 white
							num_b++;
						else
							num_w++;
					}
				}
			}
			ans = findMin(ans, num_b);
			ans = findMin(ans, num_w);
			num_b = 0;
			num_w = 0;
			start_m++;
		}
		start_n++;
	}
	if (ans == 3000) {
		ans = 0;
	}
	cout << ans;
	return 0;
}
