#include <string>
#include <vector>
using namespace std;
int dp[102][102]={0,};
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=1;
        }
    }
    for(int i=0; i<puddles.size(); i++){
        int row = puddles[i][1];
        int col = puddles[i][0];
        dp[row][col]=0;
        if(row == 1){
            for(int c = col; c<=m; c++)
                dp[1][c]=0;
        }
        if(col == 1){
            for(int r = row; r<=n; r++)
                dp[r][1]=0;
        }
    }
    
    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            if(dp[i][j]!=0)
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
        }
    }
    
    return dp[n][m];
}
