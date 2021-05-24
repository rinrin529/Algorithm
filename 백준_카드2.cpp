#include <iostream>
#include <queue>
using namespace std;
queue <int> q;
void erase_odd() {
	queue <int> new_q;
	int idx = 1;
	while (!q.empty()) {
		if (idx % 2 == 0) {
			new_q.push(q.front());
		}
		q.pop();
		idx++;
	}
	q = new_q;
}
void erase_even() {
	queue <int> new_q;
	int idx = 1;
	while (!q.empty()) {
		if (idx % 2 == 1) {
			new_q.push(q.front());
		}
		q.pop();
		idx++;
	}
	q = new_q;
}
int main(void) {
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		q.push(i);
	}
	int erase_odd_idx = 1;
	while (q.size() != 1) {
		int size = q.size();
		if (erase_odd_idx == 1) { // 짝수 지우기
			erase_odd();
		}
		else {
			erase_even();
		}
		if (size % 2 == 1) {
			erase_odd_idx = !(erase_odd_idx);
		}
	}
	
	cout << q.front();
	return 0;
}
