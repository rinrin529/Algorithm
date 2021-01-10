#include <iostream>

using namespace std;

int main(void) {
	int result[50] = { 0, };
	int arr[50][2] = { 0, };
	int n = 0;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		result[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) { 
				result[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << result[i];
			if (i != n - 1) {
				cout << " ";
		}
	}
	return 0;
}