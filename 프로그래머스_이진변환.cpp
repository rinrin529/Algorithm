#include <string>
#include <vector>
using namespace std;
int change = 0;
int zero = 0;
string step_one(string s) {
	string output = "";
	int size = s.size();
	for (int i = 0; i < size; i++) {
		if (s[i] != '0') {
			output += s[i];
		}
		else {
			zero++;
		}
	}
	return output;
}
string step_two(string s) {
	int len = s.size();
	string output = "";
	while (len > 0) {
		output.insert(0, to_string(len % 2));
		len /= 2;
	}
	return output;
}

vector<int> solution(string s) {
	vector<int> answer;
	while (1) {
		change++;
		s = step_one(s);
		if (s == "1") {
			break;
		}
		s = step_two(s);
		if (s == "1") {
			break;
		}
	}
	answer.push_back(change);
	answer.push_back(zero);
	return answer;
}
