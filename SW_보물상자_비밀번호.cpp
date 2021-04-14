#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;
int n = 0, k = 0;
vector <char> number;
vector <int> answer;
int idx[4] = { 0, };

void change_10_num(string num16, int size) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		if (num16[i] == 'A') {
			num += pow(16, (size - i) - 1) * 10;
		}
		else if (num16[i] == 'B') {
			num += pow(16, (size - i) - 1) * 11;
		}
		else if (num16[i] == 'C') {
			num += pow(16, (size - i) - 1) * 12;
		}
		else if (num16[i] == 'D') {
			num += pow(16, (size - i) - 1) * 13;
		}
		else if (num16[i] == 'E') {
			num += pow(16, (size - i) - 1) * 14;
		}
		else if (num16[i] == 'F') {
			num += pow(16, (size - i) - 1) * 15;
		}
		else {
			num += pow(16, (size - i) - 1) *(num16[i] - '0');
		}
	}
	answer.push_back(num);
}

void make_number(int size) {
	for (int i = 0; i < 4; i++) {
		int start = idx[i];
		string num16 = "";
		for (int j = start; j < start + size; j++) {
			if (j >= n) {
				num16 += number[j-n];
			}
			else {
				num16 += number[j];
			}
		}
		change_10_num(num16, size);
	}
}

void rotate(int size) {
	for (int i = 0; i < 4; i++) {
		idx[i] -= 1;
		if (idx[i] == -1) {
			idx[i] = n - 1;
		}
	}
}

void input() {
	number.clear();
	answer.clear();
	char temp[30] = { 0, };
	cin >> n >> k;
	cin >> temp;
	for (int i = 0; i < n; i++) {
		number.push_back(temp[i]);
	}
	idx[0] = 0;
	idx[1] = 0 + n / 4;
	idx[2] = idx[1] * 2;
	idx[3] = idx[1] * 3;
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}


int main(void) {
	int t = 0;
	freopen("input.txt", "r", stdin);
	init();
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int output = 0;
		input();
		int size = n / 4;
		for (int j = 0; j < size; j++) {
			make_number(size);
			rotate(size);
		}
		sort(answer.begin(), answer.end(), greater<int>());
		answer.erase(unique(answer.begin(), answer.end()), answer.end());
		cout <<"#"<< i << " " << answer[k-1] << endl;
	}

	return 0;
}
