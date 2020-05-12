#include <iostream>
#include <algorithm>
using namespace std;

int dice[7] = { 0, };
int new_dice[7] = { 0, };
int x = 0, y = 0;
int n = 0, m = 0;
int order_to_go_dice(int num);
void copy_dice();

int main(void) {
	int k = 0;
	int arr[100][20] = { 0, };
	int order[1000] = { 0, };
	int check = 0;

	cin >> n >> m >> x >> y >> k;
	if (n < 1 || m > 20 || x < 0 || x > n || y < 0 || y > m || k > 1000 || k < 1)
		return 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	
	for (int i = 0; i < k; i++)
		cin >> order[i];

	for (int i = 0; i < k; i++) {
		if (order_to_go_dice(order[i]) > 0) {
			copy_dice();
			if (arr[x][y] == 0) {
				arr[x][y] == dice[0];
			}
			else {
				dice[0] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[5] << endl;
		}

	}

	return 0;
}

int order_to_go_dice(int num)
{
	int temp = 0;
	if (num == 1) {
		if (y + 1 == m || y + 1 < 0)
			return -1;
		else {
			y++;
			new_dice[0] = dice[1];
			new_dice[1] = dice[5];
			new_dice[2] = dice[0];
			new_dice[3] = dice[3];
			new_dice[4] = dice[4];
			new_dice[5] = dice[2];
			return 1;
		}
	}
	else if (num == 2) {
		if (y - 1 < 0 || y - 1 == m)
			return -1;
		else {
			y--;
			new_dice[0] = dice[2];
			new_dice[1] = dice[0];
			new_dice[2] = dice[5];
			new_dice[3] = dice[3];
			new_dice[4] = dice[4];
			new_dice[5] = dice[1];
			return 1;
		}
	}
	else if (num == 3) {
		if (x - 1 < 0 || x - 1 == n)
			return -1;
		else {
			x--;
			new_dice[0] = dice[3];
			new_dice[1] = dice[1];
			new_dice[2] = dice[2];
			new_dice[3] = dice[5];
			new_dice[4] = dice[0];
			new_dice[5] = dice[4];
			return 1;
		}
	}
	else if (num == 4) { //num==4
		if (x + 1 == n || x + 1 < 0)
			return -1;
		else {
			x++;
			new_dice[0] = dice[4];
			new_dice[1] = dice[1];
			new_dice[2] = dice[2];
			new_dice[3] = dice[0];
			new_dice[4] = dice[5];
			new_dice[5] = dice[3];
			return 1;
		}
	}
	else {
		return -1;
	}
}

void copy_dice()
{
	for (int i = 0; i < 6; i++)
		dice[i] = new_dice[i];
}
