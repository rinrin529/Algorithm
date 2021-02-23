#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

bool compare(int i, int j) { // top is +
	if (i < 0 && j < 0) {
		return i > j;
	}
	else {
		return i < j;
	}
}


int main(void) {
	int n = 0, m = 0;
	int point = 0;
	int answer = 0;
	int max_plus_point = 0;
	int max_minus_point = 0;
	cin >> n >> m;

	vector<int> books;

	for (int i = 0; i < n; i++) {
		cin >> point;
		if (point >= 0) {
			if (point > max_plus_point) { //+에서 최대값 찾기
				max_plus_point = point;
			}
		}
		if (point < 0) {
			if (point < max_minus_point) { //-에서 최대값 찾기
				max_minus_point = point;
			}
		}
		books.push_back(point);
	}

	point = 0; //사용자 시작 포인트
	sort(books.begin(), books.end(), compare);

	while (!books.empty()) {
		if (m == 0)
			break;

		for (int i = 0; i < m; i++) {
			if (books.empty()) {
				break;
			}
			int top = books[books.size()-1];
			if (point * top >= 0) { //이동 전-> 이동 후 부호에 따라 계산 다르게 하기
				answer += abs(abs(point) - abs(top));
			}
			else {
				answer += abs(abs(point) + abs(top));
			}
			point = top;
			books.pop_back();
		}
		answer += abs(point);
		point = 0;
	}

	if (abs(max_minus_point) > max_plus_point) {
		answer -= abs(max_minus_point);
	}
	else {
		answer -= abs(max_plus_point);
	}

	cout << answer;
	return 0;
}
