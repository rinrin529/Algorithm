#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int a_plus_b = (brown / 2) - 2;
	int a_multiple_b = yellow;
	int a = 0, b = 0;
	for (int i = a_plus_b - 1; i >= a_plus_b / 2; i--) {
		a = i;
		b = a_plus_b - i;
		if (a*b == a_multiple_b) {
			answer.push_back(a + 2);
			answer.push_back(b + 2);
			break;
		}
	}
	return answer;
}
