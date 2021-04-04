#include <string>
using namespace std;
string solution(string number, int k) {
	string answer = "";
	int biggest_idx = 0;
	int start_idx = 0;
	while (k > 0) {	// k개 빼내기
		for (int i = start_idx; i <= start_idx + k; i++) {	// k 범위 속에서 가장 최대 찾기
			if (number[biggest_idx] - '0' < number[i] - '0') {
				biggest_idx = i;
			}
		}
		answer += number[biggest_idx];
		if (answer.size() == number.size() - k) {
			return answer;	// 완성
		}
		else {
			k -= (biggest_idx - start_idx);	// 빼낸 만큼 k 감소
			biggest_idx += 1;
			start_idx = biggest_idx;
		}
	}
	for (int i = biggest_idx; i < number.size(); i++) {	// 나머지 복사
		answer += number[i];
	}
	return answer;
}
