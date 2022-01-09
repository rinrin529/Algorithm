#include <iostream>
#include <string>
#include <stack>
using namespace std;
int solution(string s)
{
	int size = s.size();
	stack <char> st;
	for (int i = 0; i < size; i++) {
		if (st.empty()) {
			st.push(s[i]);
		}
		else {
			if (st.top() == s[i]) {
				st.pop();
			}
			else {
				st.push(s[i]);
			}
		}
	}
	if (st.empty()) {
		return 1;
	}
	return 0;
}
