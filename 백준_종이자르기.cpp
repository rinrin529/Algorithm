#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int row = 0, col = 0;
int map[4][4] = { 0, };
int visit_map[4][4] = { 0, };
int answer = 0;
vector <int> shape_row[7] = {{0},{0,0},{0,0,0},{0,0,0,0},{0,1},{0,1,2},{0,1,2,3}};
vector <int> shape_col[7] = {{0},{0,1},{0,1,2},{0,1,2,3}, {0,0},{0,0,0},{0,0,0,0}};
// (idx) 0:한칸, 1:가로 2칸, 2:가로 3칸, 3:가로 4칸, 4:세로 2칸, 5:세로 3칸, 6:세로 4칸
int check_end() {	// 전부 다 잘랐는지 체크
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visit_map[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}
int visit_fun(int now_r, int now_c, int num, int bit) {	// bit가 1이면 visit 무효처리
	int size = shape_row[num].size()-1;
	int number = 0;
	for (int i = 0; i < shape_row[num].size(); i++) {
		int new_r = now_r + shape_row[num][i];
		int new_c = now_c + shape_col[num][i];
		if (bit == 1) {
			visit_map[new_r][new_c] = 1;
			number += map[new_r][new_c] * pow(10, size);
			size--;
		}
		else {
			visit_map[new_r][new_c] = 0;
		}
	}
	return number;
}
int check_shape(int now_r, int now_c, int num) {	// 원하는 모양으로 자를 수 있는지 체크
	for (int i = 0; i < shape_row[num].size(); i++) {
		int new_r = now_r + shape_row[num][i];
		int new_c = now_c + shape_col[num][i];
		if (new_r < row && new_c < col) {
			if (visit_map[new_r][new_c] == 1) {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	return 1;
}
void dfs(int now_r, int now_c,int sum) {
	if (check_end() == 1) {
		if (answer < sum) {
			answer = sum;
		}
		return;
	}
	int check = 0;
	for (int i = 0; i < 7; i++) {
		if (check_shape(now_r, now_c, i) == 1) {
			check = 1;
			int plus = visit_fun(now_r, now_c, i, 1);
			sum += plus;
			int new_r = now_r;
			int new_c = now_c + 1;
			if (new_c == col) {
				new_r = now_r + 1;
				new_c = 0;
			}
			dfs(new_r, new_c, sum);
			sum -= plus;
			visit_fun(now_r, now_c, i, 0);
		}
	}
	if (check == 0) {
		int new_r = now_r;
		int new_c = now_c + 1;
		if (new_c == col) {
			new_r = now_r + 1;
			new_c = 0;
		}
		dfs(new_r, new_c, sum);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char temp[4][4] = { 0, };
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> temp[i][j];
			map[i][j] = temp[i][j] - '0';
		}
	}
	dfs(0, 0, 0);
	cout << answer;
	return 0;
}
