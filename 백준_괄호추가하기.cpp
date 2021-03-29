#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
char sik[20] = { 0, };
int mid_result[20] = { 0, };
int result = -9999999999;
int calculate(int num1, int num2, char mid) {
	if (mid == '*') {
		return num1 * num2;
	}
	else if (mid == '-') {
		return num1 - num2;
	}
	else {
		return num1 + num2;
	}
}
void dfs(int idx, int cal, int galho, int size) {
	
	int num = sik[idx] - '0';
	int mid = sik[idx - 1];
	if (galho == 1) {	//괄호 있음
		cal = calculate(cal, mid_result[idx], mid);
		if (idx + 4 > size - 1 || idx == size - 1) {
			if (cal > result) {
				result = cal;
			}
			return;
		}
		dfs(idx + 4, cal, 0, size);
		dfs(idx + 4, cal, 1, size);
	}
	else {
		cal = calculate(cal, num, mid);
		if (idx == size - 1) {
			if (cal > result) {
				result = cal;
			}
			return;
		}
		dfs(idx + 2, cal, 0, size);
		dfs(idx + 2, cal, 1, size);
	}
}
int main(void) {
	int size = 0;
	cin >> size;
	cin >> sik;
	if (size == 1) {
		cout << sik[0];
		return 0;
	}
	for (int i = 0; i < size; i++) {
		if (i == 0 || i == size - 1) {
			mid_result[i] = sik[i] - '0';
		}
		else if (i % 2 == 0) {
			mid_result[i] = calculate(sik[i] - '0', sik[i + 2] - '0', sik[i + 1]);
		}
		else
			continue;
	}
	dfs(2, sik[0] - '0', 0, size);
	dfs(2, sik[0] - '0', 1, size);
	cout << result;
	return 0;
}
