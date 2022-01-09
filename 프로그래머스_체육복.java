import java.util.*;

class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n-lost.length;
        int idx=0;
        Arrays.sort(lost);
        Arrays.sort(reserve);
        
        for(int i=0; i<reserve.length; i++){ // 같은거 체크
            for(int j=0; j<lost.length; j++){
                if(reserve[i]==lost[j] && lost[j]!=-2){
                    reserve[i]=-2;
                    lost[j]=-2;
                    answer+=1;
                    break;
                }
            }
        }
        
        for(int i=0; i<reserve.length; i++){ // 같은거 체크
            for(int j=0; j<lost.length; j++){
                if((reserve[i]-1==lost[j] || reserve[i]+1==lost[j])){
                    lost[j]=-2;
                    reserve[i]=-2;
                    answer+=1;
                    break;
                }
            }
        }
        
        
        return answer;
    }
}
