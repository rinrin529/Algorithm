#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int num = 1;
	int count = 0;
	int arr[1001] = { 0, };

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + num);

	for (int i = 0; i < num; i++) {
		if (count + 1 < arr[i]) {
			break;
		}
		count += arr[i];
	}

	cout << (count + 1);
	return 0;
}
