#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int broke[10] = { 0, };
int can_make(int num) {
	if (num == 0) {
		if (broke[0] == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	while (num > 0) {
		if (broke[num % 10] == 1) {
			return 0;
		}
		num /= 10;
	}
	return 1;
}
int main(void) {
	int answer = 0;
	int channel = 0;
	int number = 0;
	int num = 0;
	cin >> channel;
	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> num;
		broke[num] = 1;
	}
	if (channel == 100) {
		cout << 0;
		return 0;
	}
	answer = abs(channel - 100);
	for (int i = 0; i <= 1000000; i++) {
		if (can_make(i) == 1) {
			num = abs(channel - i) + to_string(i).length();
			answer = min(answer, num);
		}
		if (answer == 1) {
			break;
		}
	}
	cout << answer;
	return 0;
}



