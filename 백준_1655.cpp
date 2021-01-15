#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue< int, vector<int>, greater<int> > pq;
	int arr[100001] = { 0, };
	int n = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if ((i+1) % 2 == 1 && (i+1) != 1) { //홀수개일때
			pq.push(arr[i]);
			pq.pop();
		}
		else {
			pq.push(arr[i]);
		}
		cout << pq.top() << endl;
	}
	return 0;
}
