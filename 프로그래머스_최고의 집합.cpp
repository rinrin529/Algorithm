// 최고의 집합
#include <string>
#include <vector>
using namespace std;
vector<int> solution(int n, int s) {
    vector<int> answer;
    long long plus = s%n;
    if(n>s){
        answer.push_back(-1);
        return answer;
    }
    for(int i=1; i<=n; i++){
        answer.push_back(s/n);
    }
    int idx = answer.size()-1;
    while(plus!=0){
        answer[idx]+=1;
        idx-=1;
        plus-=1;
    }
    return answer;
}
//
