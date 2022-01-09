#include <string>
#include <vector>
using namespace std;
string solution(int n) {
    string answer = "";
	while (n > 0) {
        string temp = "";
        if(n%3==0){
            temp = to_string(4);
            answer.insert(0, temp);
		    n = n / 3;
            n--;
        }
        else{
            temp = to_string((n % 3));
            answer.insert(0, temp);
		    n = n / 3;
        }
	}
    
    return answer;
}
