#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int solution(int n, vector<vector<int>> results) {
   int answer = 0;
   int size = results.size();
   int map[101][101] = { 0, }; // row: winner, col: loser
   int win[101] = { 0, };
   int visit[101] = { 0, };
   int lose[101] = { 0, };
   for (int i = 0; i < size; i++) {
      int winner = results[i][0];
      int loser = results[i][1];
      map[winner][loser] = 1;
   }
   for (int i = 1; i <= n; i++) {
        for(int r = 1; r <= n; r++){
            for (int j = 1; j <= n; j++) {
                if (map[i][j] == 1 ) {   //win
                    if(visit[j]==0)
                        win[i]++;
                    visit[j] = 1;
                    for (int k = 1; k <= n; k++) {
                        if (map[j][k] == 1 && visit[k] == 0) {
                            win[i]++;
                            map[i][k] = 1;
                            visit[k] = 1;
                        }
                    }
                }
            }
        }
      memset(visit, 0, (n + 1)*4);
   }

   for (int i = n; i >= 1; i--) {
        for(int r = 1; r <= n; r++){
            for (int j = 1; j <= n; j++) {
                if (map[j][i] == 1) {   //lose
                    if(visit[j] == 0)
                        lose[i]++;
                    visit[j] = 1;
                    for (int k = 1; k <= n; k++) {
                        if (map[k][j] == 1 && visit[k] == 0) {
                            lose[i]++;
                            map[k][i] = 1;
                            visit[k] = 1;
                        }
                    }
                }
            }
        }
      memset(visit, 0, (n + 1) * 4);
   }
   for (int i = 1; i <= n; i++) {
      if (win[i] + lose[i] == n-1)
         answer++;
      else continue;
   }
   return answer;
}
