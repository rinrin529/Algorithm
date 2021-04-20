int maxArea(vector<int>& height) {
    int x1 = 0;
    int x2 = height.size()-1;
    int answer = ((height[x1]<height[x2]) ? height[x1]:height[x2])*(x2-x1);
    int num=0;
        
    while(x1!=x2){
       if(height[x1]>height[x2]){
            x2-=1;
            num = ((height[x1]<height[x2]) ? height[x1]:height[x2])*(x2-x1);
            answer = (num>answer) ? num : answer;
        }
        else{
           x1+=1;
            num = ((height[x1]<height[x2]) ? height[x1]:height[x2])*(x2-x1);
            answer = (num>answer) ? num : answer; 
        }
    }
        
    return answer;
}
