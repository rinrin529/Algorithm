#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n = 0, m = 0;
	int temp = 0;
	int answer = 0;
	vector <int> plus_books;
	vector <int> minus_books;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp >= 0) {
			plus_books.push_back(temp);
		}
		else {
			minus_books.push_back(temp);
		}
		
	}
	sort(plus_books.begin(), plus_books.end(), greater<int>());
	sort(minus_books.begin(), minus_books.end());
	int plus_idx = 0;
	int plus_size = plus_books.size();
	int minus_size = minus_books.size();
	int minus_idx = 0;
	if (minus_size > 0) {
		while (1) {
			answer += (abs(minus_books[minus_idx]) * 2);
			minus_idx += m;
			if (minus_idx >= minus_size) {
				break;
			}
		}
	}
	if (plus_size > 0) {
		while (1) {
			answer += (abs(plus_books[plus_idx]) * 2);
			plus_idx += m;
			if (plus_idx >= plus_size) {
				break;
			}
		}
	}
	if (plus_size > 0 && minus_size > 0) {
		if (abs(plus_books[0]) > abs(minus_books[0])) {
			answer -= abs(plus_books[0]);
		}
		else {
			answer -= abs(minus_books[0]);
		}
	}
	else if (plus_size > 0) {
		answer -= abs(plus_books[0]);
	}
	else {
		answer -= abs(minus_books[0]);
	}
	cout << answer;
	return 0;
}
