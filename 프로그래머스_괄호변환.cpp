#include <string>
#include <vector>

using namespace std;

pair<string,string> make_u(string s) {
	int right = 0;
	int left = 0;
	pair<string, string> output;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		if (s[i] == '(') {
			right += 1;
		}
		else {
			left += 1;
		}
		if (right == left) {
			output.first = s.substr(0, i + 1);
			output.second = s.substr(i + 1);
			return output;
		}
	}
	return { "", s };
}

int g_fun(string s) { // 균형 체크
	int right = 0;
	int left = 0;
	int size = s.size();
	if (size == 0) {
		return -1;
	}
	for (int i = 0; i < size; i++) {
		if (s[i] == '(') {
			right += 1;
		}
		else {
			left += 1;
		}
	}

	if (left == right) {
		return 1;
	}
	else {
		return -1;
	}
}

int o_fun(string s) {	// 올바른 괄호 체크
	int right = 0;
	int size = s.size();
	for (int i = 0; i < size; i++) {
		if (s[i] == '(') {
			right += 1;
		}
		else {
			if (right == 0) {
				return -1;
			}
			else {
				right -= 1;
			}
		}
	}
	return 1;
}

string first_fun(string w) {
	if (w == "") {
		return { "","" };
	}
	
	pair<string, string> tmp = make_u(w);
	string u = tmp.first;
	string v = tmp.second;
	if (o_fun(tmp.first) > 0) {
		u += first_fun(v);
		return u;
	}
	else {
		string s = "(";
		s += first_fun(v);
		s += ')';
		int size = u.size();
		for (int i = 1; i < size - 1; i++) {
			if (u[i] == '(') {
				s += ')';
			}
			else {
				s += '(';
			}
		}
		return s;
	}
}

string solution(string p) {
	string answer = "";
	string w = p;
	string u = "";
	string v = "";
	if (p.size() == 0) {
		return answer;
	}

	if (g_fun(p) > 0) {
		if (o_fun(p) > 0) {
			return p;
		}
		answer = first_fun(w);
	}
	return answer;
}
