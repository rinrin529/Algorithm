#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int dp[100000][4]={0,};
    int size = land.size();
    for(int i=0; i<4; i++){
        dp[0][i]=land[0][i];
    }
    for(int i=1; i<size; i++){
        for(int j=0; j<4; j++){
            if(j==0){
                dp[i][j]=land[i][j]+max(max(dp[i-1][1], dp[i-1][2]), dp[i-1][3]);
            }
            else if(j==1){
                dp[i][j]=land[i][j]+max(max(dp[i-1][0], dp[i-1][2]), dp[i-1][3]);
            }
            else if(j==2){
                dp[i][j]=land[i][j]+max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][3]);
            }
            else{
                dp[i][j]=land[i][j]+max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
            }
        }
    }
    answer = max(max(dp[size-1][0], dp[size-1][1]), max(dp[size-1][2], dp[size-1][3]));
    return answer;
}
