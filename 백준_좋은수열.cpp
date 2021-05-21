#include <iostream>
#include <string>
using namespace std;
string answer = "";
int n = 0;
int fend = 0;
bool bad_line(string s) {
	int size = s.size();
	for (int ss = 1; ss <= size/2; ss++) {
		for (int i = 0; i < size - ss; i++) {
			string a = s.substr(i, ss);
			string b = s.substr(i + ss, ss);
			if (a.size() != b.size()) {
				break;
			}
			if (a == b) {
				return true;
			}
		}
	}
	return false;
}
void dfs(string s) {
	int size = s.size();
	if (bad_line(s) == true) {
		return;
	}
	if (size == n) {
		answer = s;
		fend = 1;
		return;
	}
	if (s[size - 1] == '1') {
		if (fend != 1) {
			dfs(s + '2');
		}
		if (fend != 1) {
			dfs(s + '3');
		}
	}
	else if (s[size - 1] == '2') {
		if (fend != 1) {
			dfs(s + '1');
		}
		if (fend != 1) {
			dfs(s + '3');
		}
	}
	else {
		if (fend != 1) {
			dfs(s + '1');
		}
		if (fend != 1) {
			dfs(s + '2');
		}
	}
}
int main(void) {
	cin >> n;
	dfs("1");
	cout << answer;
	return 0;
}
