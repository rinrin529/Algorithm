#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());
	int size = reserve.size();
	int end = lost.size();
	int lost_student = end;
	int idx = 0;
	for (int i = 0; i < reserve.size(); i++) {
		for (int j = 0; j < lost.size(); j++) {
			if (reserve[i] == lost[j]) {
				reserve.erase(reserve.begin() + i);
				lost.erase(lost.begin() + j);
				i--;
				j--;
			}
		}
	}
	size = reserve.size();
	end = lost.size();
	idx = 0;
	lost_student = end;
	for (int i = 0; i < size; i++) {
		if (reserve[i] - 1 > lost[idx]) {
			idx++;
			i--;
		}
		else {
			if (reserve[i] - 1 == lost[idx]) {
				lost_student -= 1;
				idx++;
			}
			else if (reserve[i] + 1 == lost[idx]) {
				lost_student -= 1;
				idx++;
			}
			else if (reserve[i] == lost[idx]) {
				lost_student -= 1;
				idx++;
			}
		}
		if (idx == end) {
			break;
		}
	}
	answer = n - lost_student;
	return answer;
}
