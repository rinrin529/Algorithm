using namespace std;
long long fun_gcd(int a, int b){ //최대 공약수
    long c=0;
    while(b!=0){
        c = a%b;
        a=b;
        b=c;
    }
    return a;
}
long long solution(int w,int h) {
    long long W = w;
    long long H = h;
    long long gcd = fun_gcd(w, h);
    long long answer = (W*H)-((W+H)-gcd);
    return answer;
}
