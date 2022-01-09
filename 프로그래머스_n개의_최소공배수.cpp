#include <string>
#include <vector>
using namespace std;
int gcd(int a, int b){
    int r=0;
    while(b!=0){
        r = a%b;
        a=b;
        b=r;
    }
    return a;
}
int solution(vector<int> arr) {
    int answer = 0;
    for(int i=0; i<arr.size()-1; i++){
        arr[i+1] = (arr[i]*arr[i+1])/gcd(arr[i], arr[i+1]);
    }
    answer = arr[arr.size()-1];
    return answer;
}
