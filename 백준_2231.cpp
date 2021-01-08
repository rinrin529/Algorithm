#include <iostream>

using namespace std;

int cal_count(int num);

int main(void) {
	int n = 0;
	cin >> n;
	int min = 0;
	int num = 0;
	int result = n;

	for (int i = n; i > n / 3; i--) {
		num = i;
		if (cal_count(num) == n) {
			if (result > num) {
				result = num;
			}
		}
	}
	if (result == n) {
		cout << 0;
	}
	else {
		cout << result;
	}

	return 0;
}

int cal_count(int num)
{
	int cal = 0;
	cal += num;
	if (num == 1000000) {
		cal += (num / 1000000);
		num = num % 1000000;

		cal += (num / 100000);
		num = num % 100000;

		cal += (num / 10000);
		num = num % 10000;

		cal += (num / 1000);
		num = num % 1000;

		cal += (num / 100);
		num = num % 100;

		cal += (num / 10);
		num = num % 10;

		cal += (num / 1);
		num = num % 1;
	}
	else if (num > 100000) {
		cal += (num / 100000);
		num = num % 100000;

		cal += (num / 10000);
		num = num % 10000;

		cal += (num / 1000);
		num = num % 1000;

		cal += (num / 100);
		num = num % 100;

		cal += (num / 10);
		num = num % 10;

		cal += (num / 1);
		num = num % 1;
	}
	else if (num > 10000) {
		cal += (num / 10000);
		num = num % 10000;

		cal += (num / 1000);
		num = num % 1000;

		cal += (num / 100);
		num = num % 100;

		cal += (num / 10);
		num = num % 10;

		cal += (num / 1);
		num = num % 1;

	}
	else if (num > 1000) {
		cal += (num / 1000);
		num = num % 1000;

		cal += (num / 100);
		num = num % 100;

		cal += (num / 10);
		num = num % 10;

		cal += (num / 1);
		num = num % 1;
	}
	else if (num > 100) {
		cal += (num / 100);
		num = num % 100;

		cal += (num / 10);
		num = num % 10;

		cal += (num / 1);
		num = num % 1;
	}
	else if (num > 10) {
		cal += (num / 10);
		num = num % 10;

		cal += (num / 1);
		num = num % 1;
	}
	else {
		cal += (num / 1);
		num = num % 1;
	}

	return cal;
}
