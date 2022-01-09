#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int result[2][1000000]={0,};
    int answer = 2;
    int left_min=a[0];
    int right_min=a[a.size()-1];
    for(int i=1; i<a.size()-1; i++) {
        if(left_min>a[i]){
            result[0][i]=1;
            left_min=a[i];
        }
        if(right_min>a[a.size()-1-i]){
            result[1][a.size()-1-i]=1;
            right_min= a[a.size()-1-i];
        }
    }
    
    for(int i=1; i<a.size()-1; i++){
        if(result[0][i] || result[1][i] == 1){
            answer++;
        }
    }
    
    return answer;
}
