#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n = 0, m = 0;
vector <int>  boxes;
vector <int> cranes;

void input() {
	int tmp = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		cranes.push_back(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		boxes.push_back(tmp);
	}
}

int main(void) {
	int answer = 0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);
	input();
	sort(cranes.begin(), cranes.end(), greater<int>());
	sort(boxes.begin(), boxes.end(), greater<int>());

	while (!boxes.empty()) {
		answer++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < boxes.size(); j++) {
				if (i == 0) {
					if (boxes[j] > cranes[0]) {
						cout << -1;
						return 0;
					}
					else {
						boxes.erase(boxes.begin() + j);
						break;
					}
				}
				else {
					if (boxes[j] <= cranes[i]) {
						boxes.erase(boxes.begin() + j);
						break;
					}
				}
			}
		}
	}

	cout << answer;
	return 0;
}
