#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dist[101] = { 0, };
int cycle[101] = { 0, };
int is_cycle(int size) {
	int check = 1;
	for (int i = 0; i < size - 1; i++) {
		if (cycle[i] != cycle[i + 1]) {
			check = 0;
			break;
		}
	}
	return check;
}
void update_cycle(int size, int new_cy, int befo_cy) {
	int small_update = min(cycle[new_cy],cycle[befo_cy]);
	int bigger = max(cycle[new_cy], cycle[befo_cy]);
	for (int i = 0; i < size; i++) {
		if (cycle[i] == bigger) {
			cycle[i] = small_update;
		}
	}
}
int find_smallest(vector<vector<int>> costs) {
	int idx = 10000;
	int cost = 10000;
	for (int i = 0; i < costs.size(); i++) {
		if (cycle[costs[i][0]]!= cycle[costs[i][1]]) {
			if (costs[i][2] < cost) {
				cost = costs[i][2];
				idx = i;
			}
		}
	}
	return idx;
}
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	int idx = 0;
	int size = costs.size();
	for (int i = 0; i < n; i++)
		cycle[i] = i;
	while (1) {
		idx = find_smallest(costs);
		if (is_cycle(n))
			break;
		update_cycle(n, costs[idx][0], costs[idx][1]);
		answer += costs[idx][2];
	}
	return answer;
}



