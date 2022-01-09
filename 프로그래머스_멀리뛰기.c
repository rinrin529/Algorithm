#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
long long solution(int n) {
    long long dp[4]={0,};
    long long answer = 0;
    dp[0]=1;
    dp[1]=2;
    if(n==1)
        answer = dp[0];
    else if(n==2)
        answer =dp[1];
    else{
        for(int i=3; i<=n; i++){
            answer=(dp[0]+dp[1])%1234567;
            dp[0]=dp[1];
            dp[1]=answer;
        }
    }
    return answer;
}
