#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> people, int limit) {
	int answer = 0;
	int idx1 = people.size() - 1; // 끝에서 시작
	int idx2 = 0; // 처음에서 시작
	int count = 0;
	
	sort(people.begin(), people.end());
	while (idx1>=idx2) {
		if (idx1 == idx2) {
			idx1--;
			answer++;
			count++;
		}
		else {
			if (people[idx1] + people[idx2] > limit) {
				idx1--;
				answer++;
				count++;
			}
			else {
				idx1--;
				idx2++;
				count += 2;
				answer++;
			}
		}
		if (count == people.size()) {
			break;
		}
	}
	
	return answer;
}
