#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int solution(int a[], size_t a_len) {
    int answer = 0;
    int count[a_len];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < a_len; i++)
		count[a[i]]++;	// 갯수 체크
	for (int i = 0; i < a_len; i++) {
		if (count[i] <= answer || count[i] == 0)
			continue;
		int temp = 0;
		for (int j = 0; j < a_len-1; j++) {
			if (a[j] != i && a[j + 1] != i) 
                continue; // 1번째 조건
            if (a[j] == a[j + 1]) 
                continue; // 2번째 조건
            temp++;
            j++;
		}
		if (temp > answer)
			answer = temp;
	}
	
	return answer * 2;
}
