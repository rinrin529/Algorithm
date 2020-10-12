#include <iostream>
using namespace std;

int bridge(int N, int L, int arr[][100]);

int main(void) {
	int N = 0;
	int L = 0;
	int arr[100][100] = { 0 };

	cin >> N >> L;
	if (N > 100 || L > 100 || N < 2 || L < 1)
		return 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	cout << bridge(N, L, arr) << endl;
	return 0;

}

int bridge(int N, int L, int arr[][100])
{
	//check row
	int go = 0;
	int before = 0;
	int count = 0;
	for (int i = 0; i < N; i++) {
		int j = 0;
		go = 0;
		before = 0;
		while (j != N-1) {
			if (arr[i][j] - arr[i][j + 1] == 1) {
				int check_L = 0;
				if (j + L < N) {
					for (int k = 1; k < L+1; k++) {
						if (arr[i][j + k] == arr[i][j + 1])
							check_L++;
					}
					if (check_L == L) {
						j += L;
						j--;
						go += L;
						before = L;
					}
					else {
						break;
					}
				}
				j++;
			}
			else if (arr[i][j] - arr[i][j + 1] == -1) {
				if (before < 1) {
					int check_L = 0;
					if (j - L + 1 > -1) {
						for (int k = 0; k < L; k++) {
							if (arr[i][j - k] == arr[i][j])
								check_L++;
						}
						if (check_L == L) {
							go++;
						}
						else {
							break;
						}
					}
					else {
						break;
					}
				}
				else {
					break;
				}
				j++;
				before--;
			}
			else if (arr[i][j] - arr[i][j + 1] == 0) {
				j++;
				go++;
				before--;
			}
			else {
				before--;
				break;
			}
		}
		if (go == N-1) {
			count++;
		}
	}

	//check col
	for (int i = 0; i < N; i++) {
		int j = 0;
		go = 0;
		before = 0;
		while (j != N - 1) {
			if (arr[j][i] - arr[j + 1][i] == 1) {
				int check_L = 0;
				if (j + L < N) {
					for (int k = 1; k < L + 1; k++) {
						if (arr[j+k][i] == arr[j+1][i])
							check_L++;
					}
					if (check_L==L) {
						j += L;
						j--;
						go += L;
						before = L;
					}
					else {
						break;
					}
				}
				j++;
			}
			else if (arr[j][i] - arr[j + 1][i] == -1) {
				if (before < 1) {
					int check_L = 0;
					if (j - L + 1 > -1) {
						for (int k = 0; k < L; k++) {
							if (arr[j-k][i] == arr[j][i])
								check_L++;
						}
						if (check_L == L) {
							go++;
						}
						else {
							break;
						}
					}
					else {
						break;
					}
				}
				else {
					break;
				}
				j++;
				before--;
			}
			else if (arr[j][i] - arr[j + 1][i] == 0) {
				j++;
				go++;
				before--;
			}
			else {
				before--;
				break;
			}
		}
		if (go == N - 1) {
			count++;
		}
	}

	return count;
}
