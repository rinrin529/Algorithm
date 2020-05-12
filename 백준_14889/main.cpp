#include <iostream>
using namespace std;

int main(void) {
	int people = 0;
	char skill[20][20] = { -1, };
	int info_num[2][190] = { -1, };
	int start_point[190] = { -1, };
	int sum_Sij[190]= { -1, };
	int team[20] = { 0, };
	int ch = -1;

	cin >> people;
	if ((people % 2 == 1) || (people < 4) || (people > 20)) {
		return 0;
	}
	for (int i = 0; i < people; i++) {
		for (int j = 0; j < people; j++) {
			cin >> skill[i][j];
		}
	}
	int total = 0;
	for (int i = 0; i < people; i++) {
		start_point[i] = total;
		for (int j = i; j < people; j++) {
			if (i != j) {
				info_num[0][total] = i;
				info_num[1][total] = j;
				sum_Sij[total] = skill[i][j]-48 + skill[j][i]-48;
				total++;
			}
		}
	}



	cout << sum_Sij[3];
	return 0;
}