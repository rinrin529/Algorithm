#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<string> operations) {
	vector <int> answer;
	vector <int> q;
	for (int i = 0; i < operations.size(); i++) {
		if (operations[i][0] == 'D') { // 삭제
			if (operations[i][2] == '1') {  // 최대값 삭제
                if(!q.empty())
				    q.erase(q.begin() + q.size() - 1);
			}
			else { // 최소값 삭제
                if(!q.empty())
				    q.erase(q.begin() + 0);
			}
		}
		else {  // 숫자 삽입
			string num = "";
			for (int j = 2; j < operations[i].size(); j++) {
				num += operations[i][j];
			}
			q.push_back(stoi(num));
		}
		sort(q.begin(), q.end());
	}
	if (q.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(q[q.size()-1]);
		answer.push_back(q[0]);
	}
	return answer;
}
