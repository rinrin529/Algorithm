#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int n = 0, m = 0, v = 0;
int map[1001][1001];
int visit[1001];
queue<int> q;

void dfs(int v);
void bfs(int v);

int main(void) {

	cin >> n >> m >> v;
	int a = 0, b = 0;
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	dfs(v);
	cout << endl;
	memset(visit, 0, sizeof(visit));

	bfs(v);
	cout << "\n";
	return 0;
}

void dfs(int v)
{
	if (visit[v] == 0) {
		cout << v << " ";
		visit[v] = 1;
		for (int i = 1; i < n + 1; i++) {
			if (visit[i] == 0 && map[v][i] == 1) {
				dfs(i);
			}
		}
	}
}

void bfs(int v)
{
	visit[v] = 1;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v << " ";
		for (int i = 1; i < n + 1; i++) {
			if (visit[i] == 0 && map[v][i] == 1) {
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}
