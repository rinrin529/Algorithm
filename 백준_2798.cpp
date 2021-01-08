#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	int n = 0;
	int m = 0;
	int arr[100] = { 0 };
	int num = 0;
	int com = 1;

	cin >> n >> m;

	int result = 1;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 2; i++) {
		num += arr[i];
		for(int j = i+1; j < n - 1; j++) {
			num += arr[j];
			for (int k = j+1; k < n; k++) {
				num += arr[k];
				if (num<=m && num>result) {
					result = num;
				}
				num -= arr[k];
			}
			num -= arr[j];
		}
		num -= arr[i];
	}
	cout << result;

	return 0;
}