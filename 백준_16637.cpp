#include<iostream>
#include<string>
using namespace std;
  
int n;
string s;
int num[10], index1, index2, max_val = -100;
char op[10];
void dfs(int sum, int cnt);
int func(int a, int b, char c);

int main()
{
	//cin.tie(0);
	//cin.sync_with_stdio(false);
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		//숫자면 숫자배열에저장
		if (i % 2 == 0) {
			num[index1] = s[i] - '0';
			index1++;
		}
		else {
			op[index2] = s[i];
			index2++;
		}
	}
	dfs(num[0], 0);
	cout << max_val << '\n';
}

void dfs(int sum, int cnt)
{
	//모든 연산자를 사용하게됐을 때는 종료
	if (cnt == index2)
	{
		if (max_val < sum)
			max_val = sum;
		return;
	}
	//앞에서부터 계산하기
	int res = func(sum, num[cnt + 1], op[cnt]);
	//dfs돌려서 확인하기(더 계산할 수 있는지)
	dfs(res, cnt + 1);
	//괄호를 쳐서 계산하기
	//만약 계산할 연산자가 아직 남았으면 계산하기
	if (cnt + 1 < index2)
	{
		//1+2*3+5일  1+(2*3)+5하는 과정
		int a = func(num[cnt + 1], num[cnt + 2], op[cnt + 1]);
		//조심!) func의 1,2번 인자 순서바꾸면 틀림
		//조심!)func의 첫번째인자는 num[cnt]가 아님
		int b = func(sum, a, op[cnt]);
		//+5계산하기위해 2칸 건너뜀(+:0, *:1, +:2)
		dfs(b, cnt + 2);
	}
}

int func(int a, int b, char c)
{
	if (c == '+')
		return a + b;
	else if (c == '-')
		return a - b;
	else if (c == '*')
		return a * b;
	else
		exit(1);
}
