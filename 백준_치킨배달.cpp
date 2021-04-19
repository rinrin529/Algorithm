#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector <pair<int, int>> chicken;
vector<pair<int, int>> house;
int dist[100] = { 0, };
int n = 0, m = 0;
int ans = 99999999;
int map[51][51];

void dfs(int count, int befo, int chi_size, int house_size) {
	for (int i = 0; i < house_size; i++) {
		int now_dist = abs(chicken[befo].first - house[i].first) + abs(chicken[befo].second - house[i].second);
		dist[i] = min(dist[i], now_dist);
	}
	if (count == m) {
		int sum = 0;
		for (int i = 0; i < house_size; i++) {
			sum += dist[i];
		}
		if (sum < ans) {
			ans = sum;
		}
		return;
	}
	int tmp_dist[100] = { 0, };
	memcpy(tmp_dist, dist, house_size * 4);
	for (int i = befo+1; i < chi_size; i++) {
		dfs(count + 1, i, chi_size, house_size);
		memcpy(dist, tmp_dist, house_size * 4);
	}
}

int main(void) {
	cin >> n >> m;
	int chi_count = 0;
	int house_count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (map[i][j] == 2) {
				chicken.push_back({ i,j });
				chi_count++;
			}
		}
	}
	house_count = house.size();
	for (int i = 0; i < house_count; i++) {
		dist[i] = 9999999;
	}
	int tmp_dist[100] = { 0, };
	memcpy(tmp_dist, dist, house_count * 4);

	for (int i = 0; i < chi_count; i++) {
		memcpy(dist, tmp_dist, house_count * 4);
		dfs(1, i, chi_count, house_count);
	}
	cout << ans;
	return 0;
 }
