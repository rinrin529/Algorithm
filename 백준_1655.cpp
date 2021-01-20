#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int arr[100001] = { 0, };
	int n = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (maxHeap.empty()) {
			maxHeap.push(arr[i]);
		}
		else if (maxHeap.size() == minHeap.size()) {
			maxHeap.push(arr[i]);
		}
		else {
			minHeap.push(arr[i]);
		}

		if (!(maxHeap.empty())&&!(minHeap.empty()) &&maxHeap.top() >= minHeap.top()) {
			int a = maxHeap.top();
			int b = minHeap.top();

			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		printf("%d\n", maxHeap.top());
	}
	
	return 0;
}
