#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int dp[3]= {0,1,0};

    for(int i=0; i<n; i++){
        dp[2]=(dp[0]+dp[1])%1000000007;
        dp[0]=dp[1];
        dp[1]=dp[2];
    }
    answer=dp[2];
    return answer;
}
