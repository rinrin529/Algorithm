#include <iostream>

using namespace std;

int get_num(int num) {
	if (num % 2 == 1) {
		num = (num / 2) + 1;
	}
	else {
		num = num / 2;
	}
	return num;
}

int solution(int n, int a, int b)
{
	int answer = 1;
	while (1) {
		a = get_num(a);
		b = get_num(b);
		if (a == b) {
			return answer;
		}
		answer += 1;
	}
}
