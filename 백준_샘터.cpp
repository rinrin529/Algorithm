#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int main(void) {
	long long n = 0, k = 0;
	long long answer = 0;
	long long count = 0;
	map <long long, long long> m;
	queue <pair<long long, long long>> q;
	cin >> n >> k; // n개의 샘터, k개의 집
	vector <long long> water(n);
	for (long long i = 0; i < n; i++) {
		cin >> water[i];
		m[water[i]] = 1;
		q.push({ water[i],0 });
	}
	
	while (1) {
		int num = q.front().first;
		int d = q.front().second;
		q.pop();
		if (m[num + 1] != 1) {
			q.push({ num + 1, d + 1 });
			count += 1;
			answer += d + 1;
			m[num + 1] = 1;
		}
		if (count == k) {
			cout << answer;
			return 0;
		}
		if (m[num - 1] != 1) {
			q.push({ num - 1, d + 1 });
			count += 1;
			answer += d + 1;
			m[num - 1] = 1;
		}
		if (count == k) {
			cout << answer;
			return 0;
		}
	}
	return 0;
}
