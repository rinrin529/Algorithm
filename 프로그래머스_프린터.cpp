#include <string>
#include <vector>
#include <queue>

using namespace std;
int info[10]={0,};

int find_max(){
    for(int i=9; i>=1; i--){
        if(info[i]>0){
            return i;
        }
    }
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int max=0;
    queue<pair<int,int>> q; // 중요도, 위치
    int size = priorities.size();
    for(int i=0; i<size; i++){
        q.push({priorities[i], i});
        info[priorities[i]]+=1;
    }
    
    max = find_max();
    
    while(!q.empty()){
        int priority = q.front().first;
        int idx = q.front().second;
        q.pop();
        if(priority<max){
            q.push({priority, idx});
        }
        else{
            info[priority]-=1;
            answer+=1;
            max = find_max();
            if(idx == location){
                break;
            }
        }
    }
    
    return answer;
}
