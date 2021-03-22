#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> day;
    int size = progresses.size();
    for(int i=0; i<size; i++){
        int cal = 100 - progresses[i];
        cal = cal /speeds[i];
        if(progresses[i]+(cal*speeds[i])<100){
            cal+=1;
        }
        day.push_back(cal);
    }
    int count = 0;
    int front_day = -1;
    for(int i=0; i<size; i++){
        if(front_day<day[i]){
            if(front_day!=-1)
                answer.push_back(count);
            front_day = day[i];
            count=1;
        }
        else{
            count++;
        }
    }
    answer.push_back(count);
    return answer;
}
