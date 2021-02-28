#include <string>
#include <vector>
using namespace std;
int idx;
int clo_num[30] = { 0, };
string clo_type[30];
void set_closet(string clothes_type) {
	for (int i = 0; i < idx; i++) {
		if (clothes_type == clo_type[i]) {
			clo_num[i]++;
			return;
		}
	}
	clo_type[idx] = clothes_type;
	clo_num[idx]++;
	idx++;
	return;
}
int solution(vector<vector<string>> clothes) {
	int answer = 1;
	for (int i = 0; i < clothes.size(); i++) {
		set_closet(clothes[i][1]);
	}
	for (int i = 0; i < idx; i++) {
		answer *= (clo_num[i] + 1);
	}
	answer -= 1;
	return answer;
}
