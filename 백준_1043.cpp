#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int m = 0;
int know[51] = { 0, }; //아는 사람
int visit[51] = { 0, };
int answer = 0;
vector<int> party[51];

int find_party_index() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			if (know[party[i][j]] == 1 && visit[i] == 0) {
				visit[i] = 1;
				return i; // 파티에 진실을 아는 사람이 있는 파티 먼저 찾기
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			return i;
		}
	}
}

void party_check(int idx) {
	int check = 0; //진실을 아는 사람이 있을 시에 1, 없으면 0
	for (int j = 0; j < party[idx].size(); j++) {
		if (know[party[idx][j]] == 1) {
			check = 1;
			break;
		}
	}
	if (check == 1) {
		for (int j = 0; j < party[idx].size(); j++) {
			know[party[idx][j]] = 1;
		}
	}
	else {
		answer++;
	}
	return;
}

int main() {
	int n = 0; //N=사람수, M=파티수
	int num = 0; 
	int p = 0;
	
	cin >> n >> m;
	cin >> num;
	
	for (int i = 0; i < num; i++) {
		cin >> p;
		know[p] = 1;
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> p;
			party[i].push_back(p);
		}
	}
	for (int i = 0; i < m; i++) {
		p = find_party_index();
		party_check(p);
	}

	cout << answer;

	return 0;
}
