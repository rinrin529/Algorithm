#include <string>
#include <vector>
#include <iostream>
using namespace std;
int visit[21] = { 0, };
pair<int, int> find_point(string name, int nowPoint) {
	int sum = 0;
	pair<int, int> check;	// sum, idx
	check.first = 50; check.second = 50;
	int size = name.size();
	for (int i = 0; i < size; i++) {
		if (visit[i] == 0) {
			if (abs(i - nowPoint) > size - i + nowPoint) {
				sum = size - i + nowPoint;
			}
			else {
				sum = abs(i - nowPoint);
			}
			if (sum < check.first) {
				check.first = sum;
				check.second = i;
			}
		}
	}
	return check;
}
int solution(string name) {
	int answer = 0;
	int size = name.size();
	int char_to_num[43] = { 0, };   // A(idx):17 ~ Z(idx):42
	for (int i = 17; i <= 30; i++)
		char_to_num[i] = i - 17;    // A ~ M
	for (int i = 42; i >= 31; i--)
		char_to_num[i] = 43 - i;    // Z ~ O
	for (int i = 0; i < size; i++) {
		if (name[i] == 'A')
			visit[i] = 1;
	}
	pair<int, int> point; // sum, idx
	while (1) {
		point = find_point(name, point.second);
		if (point.second == 50)
			break;
		answer += char_to_num[name[point.second] - '0'];
		answer += point.first;
		visit[point.second] = 1;
	}
	return answer;
