#include <iostream>
#include <string>
using namespace std;
int main(void) {
	string s = "";
	int answer = 1;
	cin >> s;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			if (s[i] == 'c') {
				answer *= 26;
			}
			else {
				answer *= 10;
			}
		}
		else {
			if (s[i] == s[i - 1]) {
				if (s[i] == 'c') {
					answer *= 25;
				}
				else {
					answer *= 9;
				}
			}
			else {
				if (s[i] == 'c') {
					answer *= 26;
				}
				else {
					answer *= 10;
				}
			}
		}
	}
	cout << answer;
	return 0;
}
