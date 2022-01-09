#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int* solution(int prices[], size_t prices_len) {
    int* answer = (int*)malloc(sizeof(int)*prices_len);
    for(int i=0; i<prices_len; i++){
        int check=0;
        for(int j=i+1; j<prices_len; j++){
            if(prices[i]>prices[j]){
                check=1;
                answer[i]= j-i;
                break;
            }
        }
        if(check==0){
            answer[i] = prices_len - i - 1;
        }
    }
    
    return answer;
}
