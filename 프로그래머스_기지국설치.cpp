#include <iostream>
#include <vector>
using namespace std;
int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int idx = 0;
	int size = stations.size();
	for (int i = 1; i <= n;) {
		if (idx < size) {
			if (i <= stations[idx] + w && i >= stations[idx] - w) {
				i = stations[idx] + w + 1;
				idx++;
			}
			else {
				answer++;
				i = i + w + w + 1;
			}
		}
		else {
			answer++;
			i = i + w + w + 1;
		}
	}
	return answer;
}
