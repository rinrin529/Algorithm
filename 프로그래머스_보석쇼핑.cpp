#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
	int size = gems.size();
	vector<int> answer = { 0,size };
	map <string, int> m;
	set<string> total (gems.begin(), gems.end());
	int start = 0;
	int end = 0;

	for (int i = 0; i < size; i++) {
		m[gems[i]]++;
		if (m.size() == total.size()) {
			end = i;
			break;
		}
	}
	answer[0] = start;
	answer[1] = end;

	while (end < size) {
		string gem = gems[start];
		m[gem] -= 1;
		start += 1;

		if (m[gem] == 0) {
			end++;
			for (; end< size; end++) {
				m[gems[end]]++;
				if (gems[end] == gem) {
					break;
				}
			}
			if (end == size) {
				break;
			}
		}
		if (answer[1] - answer[0] > end - start) {
			answer[0] = start;
			answer[1] = end;
		}
	}
	answer[0] += 1;
	answer[1] += 1;
	return answer;
}
