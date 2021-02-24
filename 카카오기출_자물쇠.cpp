// 2번 자물쇠
#include <string>
#include <vector>
using namespace std;
vector<int> lock_point[400];
vector<int> key_point[400];
void rotate(int size, int key_size) {
	int row = 0;
	int col = 0;
	for (int i = 0; i < key_size; i++) { //90도 회전
		row = key_point[i][1];
		col = size - key_point[i][0] - 1;
		key_point[i][0] = row;
		key_point[i][1] = col;
	}
}
int check(int key_size, int lock_size, int size) {
	vector<int> tmp_key[400];
	int r = 0;
	int c = 0;
	int count = 0;
	for (int i = 0; i < lock_size; i++) {
		for (int p = 0; p < key_size; p++) {
			r = lock_point[i][0] - key_point[p][0];
			c = lock_point[i][1] - key_point[p][1];
			for (int j = 0; j < key_size; j++) { // key 값 이동하기(상하좌우)
				tmp_key[j].push_back(key_point[j][0] + r);
				tmp_key[j].push_back(key_point[j][1] + c);
			}
			for (int k = 0; k < lock_size; k++) {
				for (int l = 0; l < key_size; l++) {
					if (tmp_key[l][0] == lock_point[k][0] && tmp_key[l][1] == lock_point[k][1]) {
						count++; // 열쇠의 돌기와 lock의 홈이 만났을 때
						break;
					}
				}
			}
			if (count == lock_size) {
				return 1;
			}
			for (int j = 0; j < key_size; j++) { // tmp key 초기화
				tmp_key[j].clear();
			}
			count = 0;
		}
	}
	return 0;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	int lock_size = 0;
	int key_size = 0;
	for (int i = 0; i < lock[0].size(); i++) { //lock 에서 0 세기
		for (int j = 0; j < lock[0].size(); j++) {
			if (lock[i][j] == 0) {
				lock_point[lock_size].push_back(i);
				lock_point[lock_size].push_back(j);
				lock_size++;
			}
		}
	}
	for (int i = 0; i < key[0].size(); i++) { //key 에서 1 세기
		for (int j = 0; j < key[0].size(); j++) {
			if (key[i][j] == 1) {
				key_point[key_size].push_back(i);
				key_point[key_size].push_back(j);
				key_size++;
			}
		}
	}
	if (lock_size == 1 && key_size > 0 || lock_size == 0) // lock이 1개인 경우
		return true;
	if (lock_size > key_size || key_size == 0)
		return false;
	for (int i = 0; i < 4; i++) { // 90도 4번 회전
		rotate(key[0].size(), key_size); // 90도 회전
		if (check(key_size, lock_size, lock[0].size()) == 1) //lock과 key 체크
			return true;
	}
	return false;
}
