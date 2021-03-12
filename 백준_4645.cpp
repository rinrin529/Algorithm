#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0;
	int a = 0, b = 0, c = 0;
	int Maxdp[3] = { 0, };
	int Mindp[3] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >>a >> b>> c;

		if (i == 0) {
			Maxdp[0] = a;
			Maxdp[1] = b;
			Maxdp[2] = c;
			Mindp[0] = a;
			Mindp[1] = b;
			Mindp[2] = c;
		}
		else {
			int maxtemp[3] = { Maxdp[0] ,Maxdp[1] ,Maxdp[2] };
			int mintemp[3] = { Mindp[0] ,Mindp[1] ,Mindp[2] };
			int tempdp2 = Mindp[1];
			Maxdp[0] = max(maxtemp[0], maxtemp[1]) + a;
			Maxdp[1] = max(max(maxtemp[0], maxtemp[1]), maxtemp[2]) + b;
			Maxdp[2] = max(maxtemp[1], maxtemp[2]) + c;

			Mindp[0] = min(mintemp[0], mintemp[1]) + a;
			Mindp[1] = min(min(mintemp[0], mintemp[1]), mintemp[2]) + b;
			Mindp[2] = min(mintemp[1], mintemp[2]) + c;
		}
	}
	int Max = max(max(Maxdp[0], Maxdp[1]), Maxdp[2]);
	int Min = min(min(Mindp[0], Mindp[1]), Mindp[2]);

	cout << Max << " " << Min;

	return 0;
}
