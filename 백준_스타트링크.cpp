#include <iostream>
using namespace std;
int main(void) {
	int visit[1000001] = { 0, };
	int f = 0, s = 0, g = 0, u = 0, d = 0;
	cin >> f >> s >> g >> u >> d;
	int now = s;
	int count = 0;
	visit[now] = 1;
	while (1) {
		if (g > now) {
			if (now + u <= f) {
				now += u;
				if (visit[now] == 1) {
					cout << "use the stairs\n";
					return 0;
				}
				visit[now] = 1;
				count++;
			}
			else {
				if (now - d >= 1) {
					now -= d;
					if (visit[now] == 1) {
						cout << "use the stairs\n";
						return 0;
					}
					visit[now] = 1;
					count++;
				}
				else {
					cout << "use the stairs\n";
					return 0;
				}
			}
		}
		else if (g < now) {
			if (now - d >= 1) {
				now -= d;
				if (visit[now] == 1) {
					cout << "use the stairs\n";
					return 0;
				}
				visit[now] = 1;
				count++;
			}
			else {
				if (now + u <= f) {
					now += u;
					if (visit[now] == 1) {
						cout << "use the stairs\n";
						return 0;
					}
					visit[now] = 1;
					count++;
				}
				else {
					cout << "use the stairs\n";
					return 0;
				}
			}
		}
		else {
			break;
		}
	}
	cout << count;
	return 0;
}
