#include <string>
#include <vector>
using namespace std;
int pos_x[]={2,1,2,3,1,2,3,1,2,3,1,3}; //0,1,2,3,4,5,6,7,8,9,*,#
int pos_y[]={4,1,1,1,2,2,2,3,3,3,4,4}; //0,1,2,3,4,5,6,7,8,9,*,#
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int i=0;
    int left=10;
    int right=11;
    
    while(i<numbers.size()){
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7){
            left=numbers[i];
            answer+="L";
        }
        else if(numbers[i]==3||numbers[i]==6||numbers[i]==9){
            right=numbers[i];
            answer+="R";
        }
        else{
            int left_dis=abs(pos_x[numbers[i]]-pos_x[left])+
                abs(pos_y[numbers[i]]-pos_y[left]);
            int right_dis=abs(pos_x[numbers[i]]-pos_x[right])+
                abs(pos_y[numbers[i]]-pos_y[right]);
            if(left_dis<right_dis) {
                left=numbers[i];
                answer+="L";
            }
            else if(left_dis>right_dis) {
                right=numbers[i];
                answer+="R";
            }
            else{
                if(hand=="right"){
                    right=numbers[i];
                    answer+="R";
                }
                else{
                    left=numbers[i];
                    answer+="L";
                }
            }
        }
        i++;
    }
    return answer;
}
