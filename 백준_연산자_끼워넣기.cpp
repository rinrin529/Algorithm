#include <iostream>
#include <vector>
using namespace std;
long long ans_max = -1000000000;
long long ans_min = 1000000000;
int n = 0;
vector <int> Number;
vector <int> Temp_Op;
vector <int> Operator;
void dfs(int Op_idx, long long sum, int Num_idx) {
	if (Op_idx == 0) {	// 덧셈
		sum += Number[Num_idx];
	}
	else if (Op_idx == 1) {	// 뺄셈
		sum -= Number[Num_idx];
	}
	else if (Op_idx == 2) { // 곱셈
		sum *= Number[Num_idx];
	}
	else { // 나눗셈
		sum /= Number[Num_idx];
	}
	if (Num_idx == n - 1) {
		if (sum > ans_max) {
			ans_max = sum;
		}
		if (sum < ans_min) {
			ans_min = sum;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (Temp_Op[i] > 0) {
			Temp_Op[i] -= 1;
			dfs(i, sum, Num_idx+1);
			Temp_Op[i] += 1;
		}
	}
}
int main(void) {
	int temp = 0;;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp; 
		Number.push_back(temp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		Operator.push_back(temp);
	}
	
	for (int i = 0; i < 4; i++) {
		Temp_Op = Operator;
		if (Temp_Op[i] > 0) {
			Temp_Op[i] -= 1;
			dfs(i, Number[0], 1);
		}
	}
	cout << ans_max << endl << ans_min;
	return 0;
}
