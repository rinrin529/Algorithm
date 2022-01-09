#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
long long n = 0, k = 0, answer = 0;
string number = "";
vector <int> arr;
int get_num(int num) {
	for (int i = k-1; i >= 0; i--) {
		if (arr[i] <= num) {
			return arr[i];
		}
	}
	return -1;
}
void dfs(string num, int idx) {
	if (idx == number.size()) {
		if (stoi(num) > answer) {
			answer = stoi(num);
		}
		return;
	}
	string tmp = number;
	tmp.erase(idx, sizeof(number)-idx);
	if (tmp != "") {
		if (stoi(num) > stoi(tmp)) {
			return;
		}
	}
	for (int i = k - 1; i >= 0; i--) {
		dfs(num + to_string(arr[i]), idx + 1);
	}
}
int main(void) {
	int tmp;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());
	number = to_string(n);
	int getNum = get_num(number[0] - '0');
	if (getNum == -1) {
		dfs("0", 1);
	}
	else {
		dfs("", 0);
	}
	cout << answer;
	return 0;
}
