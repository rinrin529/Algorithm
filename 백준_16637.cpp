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
		//���ڸ� ���ڹ迭������
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
	//��� �����ڸ� ����ϰԵ��� ���� ����
	if (cnt == index2)
	{
		if (max_val < sum)
			max_val = sum;
		return;
	}
	//�տ������� ����ϱ�
	int res = func(sum, num[cnt + 1], op[cnt]);
	//dfs������ Ȯ���ϱ�(�� ����� �� �ִ���)
	dfs(res, cnt + 1);
	//��ȣ�� �ļ� ����ϱ�
	//���� ����� �����ڰ� ���� �������� ����ϱ�
	if (cnt + 1 < index2)
	{
		//1+2*3+5�� �� 1+(2*3)+5�ϴ� ����
		int a = func(num[cnt + 1], num[cnt + 2], op[cnt + 1]);
		//����!) func�� 1,2���� ���� �����ٲٸ� Ʋ��
		//����!)func�� ù��°���ڴ� num[cnt]�� �ƴ�
		int b = func(sum, a, op[cnt]);
		//+5����ϱ����� 2ĭ �ǳʶ�(+:0, *:1, +:2)
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