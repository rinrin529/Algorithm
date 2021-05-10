#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	stack <int> del;
	int cmdSize = cmd.size();
	int arr[1000] = { 0, };
	//int arr[1000005] = { 0, };

	for (int i = 0; i < cmdSize; i++) {
		if (cmd[i][0] == 'D') { // 아래로 이동
			int ss = cmd[i].size();
			string tmp = cmd[i].substr(2, ss);
			int x = stoi(tmp);
			int start = k;
			int to_go = k + x;
			for (int j = start + 1; j <= to_go; j++) {
				if (arr[j] == -1) {
					to_go += 1;
				}
			}
			k = to_go;
		}
		else if (cmd[i][0] == 'U') { // 위로 이동
			int ss = cmd[i].size();
			string tmp = cmd[i].substr(2, ss);
			int x = stoi(tmp);
			int start = k;
			int to_go = k - x;
			for (int j = start - 1; j >= to_go; j--) {
				if (arr[j] == -1) {
					to_go -= 1;
				}
			}
			k = to_go;
		}
		else if (cmd[i][0] == 'C') { // 삭제
			arr[k] = -1;
			del.push(k);
			int count = 0;
			for (int j = k + 1; j < n; j++) {
				if (arr[j] == 0) {
					k = j;
					count = 1;
					break;
				}
			}
			if (count == 0) { // 맨 마지막이다.
				for (int j = k - 1; j >= 0; j--) {
					if (arr[j] == 0) {
						k = j;
						break;
					}
				}
			}
		}
		else {   // 'Z' 복귀
			int idx = del.top();
			del.pop();
			arr[idx] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] == -1) {
			answer += 'X';
		}
		else {
			answer += 'O';
		}
	}

	return answer;
}

int main(void) {
	int n = 8;
	int k = 0;
	vector <string> cmd = { "D 347","C","U 1","C","C" };
	solution(n, k, cmd);
	return 0;
}
