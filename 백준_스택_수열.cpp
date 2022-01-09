#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int num = 0;
	stack <int> st;
	vector <int> v(n);
	vector <char> answer;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v[i] = num;
	}
	int idx = 0;

	for (int i = 1; i <= n; i++) {
		st.push(i);
		answer.push_back('+');
		if (!st.empty()) {
			while (st.top() == v[idx]) {
				idx++;
				st.pop();
				answer.push_back('-');
				if (st.empty()) {
					break;
				}
			}
		}
		if (!st.empty()) {
			if (st.top() > v[idx]) {
				cout << "NO";
				return 0;
			}
		}
	}

	int ssize = answer.size();
	for (int i = 0; i < ssize; i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}
