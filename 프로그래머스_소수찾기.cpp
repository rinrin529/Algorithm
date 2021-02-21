#include <string>
#include <vector>
#include <algorithm>
#include <functional>
int *primeNum;
using namespace std;
void Eratos(int num)
{   
    primeNum = new int[num+1]; 
    primeNum[0] = 0;
    primeNum[1] = 0;
    
    for(int i=2; i<=num; i++)
        primeNum[i] = i;
    
    for(int i=2; i*i<=num; i++) {
        if(primeNum[i]!=0) {
            for(int j=i*i; j<=num; j+=i)
                primeNum[j] = 0;
        }
    }
}
int Cardcheck(int num, string card) {
    string strNum = to_string(num);
    int check=0;
    for(int i=0; i<strNum.size(); i++){
        check=0;
        for(int j=0; j<card.size(); j++){
            if(strNum[i]==card[j]){
                card[j]=0;
                check=1;
                break;
            }
        }
        if(check==0){
            return 0;
        }
    }
    return 1;
}
int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<int>());
    int maxNum = stoi(numbers);
    
    Eratos(maxNum);
    for(int i=0; i<=maxNum; i++){
        if(primeNum[i] && Cardcheck(i,numbers)){
            answer++;
        }
    }
    
    return answer;
}
