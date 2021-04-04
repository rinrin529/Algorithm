#include <vector>
#include <queue>
using namespace std;
long long solution(int n, vector<int> works) {
	long long answer = 0;
	priority_queue <int> pq;
	for (int i = 0; i < works.size(); i++) {
		pq.push(works[i]);
	}
	while (n) {
		int work = pq.top();
		pq.pop();
		if (work > 0) {
			work -= 1;
			n -= 1;
			pq.push(work);
		}
		if (pq.empty()) {
			break;
		}
	}
	while (!pq.empty()) {
		int temp = pq.top();
		pq.pop();
		answer += (temp*temp);
	}
	return answer;
}
