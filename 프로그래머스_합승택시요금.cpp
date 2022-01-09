#include <string>
#include <vector>
#define INF 9999999
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 0;
	int size = fares.size();
	int fee[201][201] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				fee[i][j] = 0;
			}
			else {
				fee[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		int Node1 = fares[i][0];
		int Node2 = fares[i][1];
		int cost = fares[i][2];
		fee[Node1][Node2] = cost;
		fee[Node2][Node1] = cost;
	}

	for (int i = 1; i <= n; i++) {	// 중간
		for (int j = 1; j <= n; j++) { // 출발
			for (int k = 1; k <= n; k++) { // 도착
				if (fee[j][k] > fee[j][i] + fee[i][k]) {
					fee[j][k] = fee[j][i] + fee[i][k];
				}
			}
		}
	}
	// 출발점 부터 각자 따로 갈때
	answer += fee[s][a];
	answer += fee[s][b];

	// 중간 점이 있을 때
	for (int i = 1; i <= n; i++) {
		if (s != i) {
			if (answer > fee[s][i] + fee[i][a] + fee[i][b]) {
				answer = fee[s][i] + fee[i][a] + fee[i][b];
			}
		}
	}
	
	return answer;
}
