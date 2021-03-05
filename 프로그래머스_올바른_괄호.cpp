#include <string>
using namespace std;
bool solution(string s)
{
    int size = s.size();
    int head=0;
    for(int i=0; i< size; i++){
        if(s[i]=='('){
            head++;
        }
        if(s[i]==')'){
            if(head==0){
                return false;
            }
            else{
                head--;
            }
        }
    }
    
    if(head!=0)
        return false;
    return true;
}
