// 1번 더 맵게
#include <vector>
#include <queue>
using namespace std;
priority_queue<int,vector<int>, greater<int> > pq;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    int a = 0;
    int b = 0;
    
    for(int i=0; i<scoville.size(); i++)
        pq.push(scoville[i]); //priority queue 사용
    
    while(1){
        if(pq.top() >= K)
            break;
        else{
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(a+(b*2)); //스코빌 지수 섞기
            answer++;
        }
        if(pq.size()==1){
            if(pq.top() < K)
            return -1;
        }
    }
    return answer;
}
