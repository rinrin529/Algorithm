#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;
	int start = 0;
	int end = 0;
	sort(routes.begin(), routes.end());
	start = routes[0][0];
	end = routes[0][1];

	for (int i = 0; i < routes.size(); i++) {
		if (routes[i][0] > end) {
			answer++;
			start = routes[i][0];   // 수직선상 교집합 범위 찾기
			end = routes[i][1];
		}
		else {
			start = routes[i][0];    // 수직선상 교집합 범위 찾기
			if (end > routes[i][1]) 
				end = routes[i][1];
		}
	}
	return answer;
}
