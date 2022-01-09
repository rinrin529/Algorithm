#include <iostream>
#include <vector>

using namespace std;
#define MAX 505

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector <int> answer;
	int dist[MAX] = { 0, };
	int tc = 0;
	int n = 0, m = 0, w = 0;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		vector <pair<int, int>> adj[MAX];
		cin >> n >> m >> w;
		for (int j = 0; j < m; j++) {
			int s = 0, e = 0, t = 0;
			cin >> s >> e >> t;
			adj[s].push_back(make_pair(e, t));	//도로는 방향 X
			adj[e].push_back(make_pair(s, t));
		}
		for (int i = 0; i < w; i++) {
			int s = 0, e = 0, t = 0;
			cin >> s >> e >> t;
			adj[s].push_back(make_pair(e, -t)); // 웜홀은 방향 O
		}
		fill(dist, dist + MAX, 999999999);
		dist[1] = 0;
		int check = 0;
		for (int i = 0; i < n; i++) {
			for (int start = 1; start <= n; start++) {
				for (int j = 0; j < adj[start].size(); j++) {
					int nextNode = adj[start][j].first;
					int cost = adj[start][j].second;
					if (dist[start] + cost < dist[nextNode]) {
						dist[nextNode] = dist[start] + cost;	//음수가 되는 경우를 찾아야 하니 최소값으로
						if (i == (n-1)) {
							check = 1;
						}
					}
				}
			}
		}
		if (check) {
			answer.push_back(1);
		}
		else {
			answer.push_back(0);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		if(answer[i]==1)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}
