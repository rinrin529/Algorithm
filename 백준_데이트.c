#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
	return strcmp((char *)a, (char *)b);
}

int find_letter(char name[], char like[], char alpha) {
	int output = 0;
	for (int i = 0; i < strlen(name); i++) {
		if (name[i] == alpha) {
			output += 1;
		}
	}
	for (int i = 0; i < strlen(like); i++) {
		if (like[i] == alpha) {
			output += 1;
		}
	}
	return output;
}

int main(void) {
	char name[25];
	char likes[55][25];
	char answer[25];
	int max = -1;
	int n = 0;
	scanf("%s", name);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", likes[i]);
	}
	qsort(likes, n, sizeof(likes[0]),compare);

	for (int i = 0; i < n; i++) {
		int sum = (find_letter(name, likes[i], 'L') + find_letter(name, likes[i], 'O'));
		sum *= (find_letter(name, likes[i], 'L') + find_letter(name, likes[i], 'V'));
		sum *= (find_letter(name, likes[i], 'L') + find_letter(name, likes[i], 'E'));
		sum *= (find_letter(name, likes[i], 'O') + find_letter(name, likes[i], 'V'));
		sum *= (find_letter(name, likes[i], 'O') + find_letter(name, likes[i], 'E'));
		sum *= (find_letter(name, likes[i], 'V') + find_letter(name, likes[i], 'E'));
		sum = sum % 100;
		if (sum > max) {
			strcpy(answer, likes[i]);
			max = sum;
		}
	}
	printf("%s", answer);
	return 0;
}
