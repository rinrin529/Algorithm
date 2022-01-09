#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int done[501] = { 0, };

bool compare(vector<int> a, vector<int> b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	return a[1] < b[1];
}

int find_to_do(int now_time, vector<vector<int>> jobs) {
	for (int i = 0; i < jobs.size(); i++) {
		if (done[i] == 0 && now_time>=jobs[i][0]) {
			done[i] = 1;
			return i;
		}
	}
	return -1;
}

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int time = 0;
	int size = jobs.size();

	sort(jobs.begin(), jobs.end(), compare);

	for (int i = 0; i < size; i++) {
		int idx = find_to_do(time, jobs);
		if (idx == -1) {
			time++;
			i--;
		}
		else {
			time += jobs[idx][1];
			answer += (time - jobs[idx][0]);
		}
	}

	return answer/ size;
}
