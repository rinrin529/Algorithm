#include <vector>
using namespace std;
int solution(vector<int> cookie) {
	vector <int> sum;
	int answer = 0;
	int start = -1;
	int size = cookie.size();
	int end = cookie.size() - 1;
	int stop = 0;
	sum.push_back(cookie[0]);
	for (int i = 1; i < cookie.size(); i++) {
		sum.push_back(sum[i - 1] + cookie[i]);
	}
	while (start < end) {
		if (answer * 2 < sum[end] - sum[start]) {
			for (int mid = start + 1; mid < end; mid++) {
				if (start == -1) {
					if (sum[mid] == sum[end] - sum[mid]) {
						if (sum[mid] > answer)
							answer = sum[mid];
						break;
					}
				}
				else {
					if (sum[mid] - sum[start] == sum[end] - sum[mid]) {
						if (sum[end] - sum[mid] > answer)
							answer = sum[end] - sum[mid];
						break;
					}
				}
			}
		}
		end -= 1;
		if (end == start) {
			end = cookie.size() - 1;
			start += 1;
		}
	}
	return answer;
}
