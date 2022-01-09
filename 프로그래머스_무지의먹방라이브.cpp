#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> food_times, long long k) {
	long long sum = 0;
	int size = food_times.size();
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // time, idx
	for (int i = 0; i < size; i++) {
		sum += food_times[i];
		pq.push({ food_times[i], i + 1 });
	}
	if (sum <= k) {
		return -1;
	}
	long long befo = 0;
	while (1) {
		long long time = (long long)pq.top().first - befo;
		long long total = time * (long long)pq.size();
		if (k - total < 0) {
			break;
		}
		k -= total;
		pq.pop();
		befo += time;
	}

	vector<int> v;
	while (!pq.empty()) {
		v.push_back(pq.top().second);
		pq.pop();
	}
	sort(v.begin(), v.end());
	return v[k % v.size()];
}
