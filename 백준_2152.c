#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n = 0;
	int arr[10001];
	int max = 0;
	int limit = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max)
			max = arr[i];
	}
	scanf("%d", &limit);

	int start = 0, end = max, mid; 
	while (start <= end) { 
		mid = (start + end) / 2; 
		int sum = 0; 
		for (int i = 0; i < n; i++) { 
			if (arr[i] > mid) 
				sum += mid; 
			else 
				sum += arr[i]; 
		} 
		if (sum > limit)
			end = mid - 1; 
		else 
			start = mid + 1; 
	} 
	printf("%d", end);
	return 0;
}
