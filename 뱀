#include <iostream>
#include <vector>

using namespace std;
int n = 0;
vector <pair<int, char>> dir;	// X,C
vector <pair<int, int>> snake;
vector <pair<int, int>> apple;

int dir_r[4] = { -1,0,1,0 };	// 위, 오른쪽, 아래, 왼쪽
int dir_c[4] = { 0,1,0,-1 };

int check_end(int row, int col) {
	for (int i = 1; i < snake.size(); i++) {
		if (row == snake[i].first && col == snake[i].second) {
			return 1;
		}
	}
	return 0;
}

int eat_apple(int row, int col) {
	for (int i = 0; i < apple.size(); i++) {
		if (row == apple[i].first && col == apple[i].second) {
			apple.erase(apple.begin() + i);
			return 1;
		}
	}
	return 0;
}

void input() {
	int k = 0, l = 0;
	int a = 0, b = 0;

	snake.push_back(make_pair(1, 1));
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		apple.push_back(make_pair(a, b));
	}
	cin >> l;
	int x = 0;
	char c = 0;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		dir.push_back(make_pair(x, c));
	}
}

int main(void) {
	input();

	int answer = 0;
	int now_dir = 1;
	while (1) {
		int row = snake[0].first;
		int col = snake[0].second;
		if (!dir.empty()) {
			if (answer == dir[0].first) {
				if (dir[0].second == 'D') {
					now_dir += 1;
					if (now_dir == 4) {
						now_dir = 0;
					}
				}
				else {
					now_dir -= 1;
					if (now_dir == -1) {
						now_dir = 3;
					}
				}
				dir.erase(dir.begin());
			}
		}
		snake.insert(snake.begin(), make_pair(row + dir_r[now_dir], col + dir_c[now_dir]));
		answer++;
		if (snake[0].first <= 0 || snake[0].first >= n + 1 || snake[0].second <= 0 || snake[0].second >= n + 1) {
			break;
		}
		if (eat_apple(snake[0].first, snake[0].second) == 0) {
			if (check_end(snake[0].first, snake[0].second) == 1) {
				break;
			}
			else {
				snake.erase(snake.begin() + snake.size() - 1);
			}
		}
	}

	cout << answer;
	return 0;
}
