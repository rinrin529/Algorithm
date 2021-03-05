// 기둥과 보 설치 ( 성공 못 함 )
#include <string>
#include <vector>
using namespace std;
int map[101][101] = { 0, }; // 기둥 = 1, 보 = 2
int Put_Bo(int row, int col, int n) {
	if (row - 1 >= 0)
		if (map[row - 1][col] == 1) //바로 아래에 기둥 있을 때
			return 1;
	if (col + 1 <= n && row -1 >= 0)
		if (map[row - 1][col + 1] == 1) // 오른쪽 아래에 기둥 있을 때
			return 1;
	if (col + 1 <= n && col - 1 >= 0)
		if (map[row][col + 1] == 2 && map[row][col - 1] == 2) //양 옆에 보 있을 때
			return 1;
	return 0;
}
int Put_Gi(int row, int col, int n) {
	if (row == 0) //바닥에 설치
		return 1;
	if (map[row - 1][col] == 1) //다른 기둥 위에 설치
		return 1;
	if(col -1 <= n)
		if (map[row][col - 1] == 2) //보의 한쪽 끝 부분 위에 설치
			return 1;
	return 0;
}
void Check_Delete(int row, int col, int n) {
	int temp = map[row][col]; // 기둥 = 1, 보 = 2
	int del = 1;
	map[row][col] = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (!(row+i == row && col+j == col)) {
				if (map[row + i][col + j] == 1) {
					if(row+i<= n && row+i>=0 && col+j<=n && col+j>=0)
						if (!Put_Gi(row + i, col + j, n))
							del = 0;
				}
				else if (map[row + i][col + j] == 2) {
					if (row + i <= n && row + i >= 0 && col + j <= n && col + j >= 0)
						if (!Put_Bo(row + i, col + j, n))
							del = 0;
				}
				else continue;
			}
		}
	}
	if (del == 0) { //원상 복구
		map[row][col] = temp;
		return;
	}
	else
		return;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	int size = build_frame.size();
	for (int i = 0; i < size; i++) {
		int row = build_frame[i][1];
		int col = build_frame[i][0];
		if (build_frame[i][2] == 0) { //기둥
			if (build_frame[i][3] == 1) { //설치
				if (Put_Gi(row, col, n))
					map[row][col] = 1;
			}
			else { //삭제
				Check_Delete(row, col, n);
			}
		}
		else { // 보
			if (build_frame[i][3] == 1) { //설치
				if (Put_Bo(row, col, n))
					map[row][col] = 2;
			}
			else { //삭제
				Check_Delete(row, col, n);
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (map[j][i] == 1) { //기둥
				vector<int> box;
				box.push_back(i);
				box.push_back(j);
				box.push_back(0);
				answer.push_back(box);
			}
			else if (map[j][i] == 2) { //보
				vector<int> box;
				box.push_back(i);
				box.push_back(j);
				box.push_back(1);
				answer.push_back(box);
			}
			else continue;
		}
	}
	return answer;
}
