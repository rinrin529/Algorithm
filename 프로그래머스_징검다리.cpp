#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int check(int num, vector<int> stones, int k) {
	int count = 0;
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] - num <= 0)
			count++;
		else 
			count = 0;
		if (count == k)
			return 0;
	}
	return 1;
}
int solution(vector<int> stones, int k) {
	int min = 1;
	int max = 200000001;
	int mid = (min + max) / 2;
	while (min <= max) {
		if (check(mid, stones, k) == 1) {
			min = mid + 1;
		}
		else {
			max = mid - 1;
		}
		mid = (min + max) / 2;
	}
	return min;
}
