#include <iostream>
#include <vector>
using namespace std;
int map[103][103];
int n = 0;
int move_x[4] = { 1,0,-1,0 };
int move_y[4] = { 0,-1,0,1 };
int dir_x[4] = { 1,-1,-1,1 };
int dir_y[4] = { -1,-1,1,1 };
int change_d[4] = { 1,2,3,0 };
int change_map_d[4] = { 3,0,1,2 };
int main(void) {
	int x = 0, y = 0, d = 0, g = 0;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		vector <pair<int, int>> dragon_xy;
		vector <int> dragon_d;
		dragon_xy.push_back({ x,y });
		dragon_d.push_back(d);
		for (int j = 0; j < g; j++) {
			int size = dragon_xy.size();
			int end_x = dragon_xy[size - 1].first + move_x[dragon_d[size - 1]];
			int end_y = dragon_xy[size - 1].second + move_y[dragon_d[size - 1]];
			for (int i = size - 1; i >= 0; i--) {
				int x_a = dragon_xy[i].first;
				int y_a = dragon_xy[i].second;
				int x_b = dragon_xy[i].first + move_x[dragon_d[i]];
				int y_b = dragon_xy[i].second + move_y[dragon_d[i]];
				int x_dist = end_x - x_b;
				int y_dist = end_y - y_b;
				end_x = x_a + dir_x[dragon_d[i]] + x_dist;
				end_y = y_a + dir_y[dragon_d[i]] + y_dist;
				dragon_xy.push_back({ (x_b+x_dist), (y_b+y_dist) });
				dragon_d.push_back(change_d[dragon_d[i]]);

			}
		}
		int dsize = dragon_xy.size();
		for (int k = 0; k < dsize; k++) {
			int x_a = dragon_xy[k].first;
			int y_a = dragon_xy[k].second;
			int x_b = dragon_xy[k].first + move_x[dragon_d[k]];
			int y_b = dragon_xy[k].second + move_y[dragon_d[k]];
			map[y_a][x_a]++;
			map[y_b][x_b]++;
		}
	}
	int answer = 0;
	for (int i = 0; i <= 100-1; i++) {
		for (int j = 0; j <=100-1; j++) {
			if (map[i][j] > 0 && map[i][j + 1] > 0 && map[i + 1][j] > 0 && map[i + 1][j + 1] > 0) {
				answer++;
			}
		}
	}

	cout << answer;

	return 0;
 }
