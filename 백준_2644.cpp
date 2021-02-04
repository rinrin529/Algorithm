#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	int total = 0;
	int a = 0, b = 0;
	int num = 0;

	cin >> total;
	cin >> a >> b;
	cin >> num;

	vector<int> fam[102];


	for (int i = 0; i < num; i++) {
		int pa = 0; //parent
		int ch = 0; //child
		cin >> pa >> ch;
		fam[pa].push_back(ch);
		fam[ch].push_back(pa);
	}

	queue<int> q;
	int dist[102] = { 0, };
	q.push(a);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == b) {
			cout << dist[b];
			return 0;
		}
		int size = fam[x].size();
		for (int i = 0; i < size; i++) {
			int y = fam[x][i];
			if (!dist[y]) {
				q.push(y);
				dist[y] = dist[x] + 1;
			}
		}
	}
	cout << -1;
	return 0;
}
