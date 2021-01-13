#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
int n = 0, k = 0;
int w = 0, v = 0;

int main(void) {
	multiset <int> bag;
	int b = 0;
	long long result = 0;
	cin >> n >> k;
	vector<pair<int, int>> gem(n);
	for (int i = 0; i < n; i++) {
		cin >> gem[i].second >> gem[i].first; //가치 , 무게
	}
	sort(gem.begin(), gem.end());

	for (int i = 0; i < k; i++) {
		cin >> b;
		bag.insert(b);
	}

	int pos = n - 1;
	while (!bag.empty() && pos >= 0) {
		multiset<int>::iterator it;
		it = bag.lower_bound(gem[pos].second); //무게
		if (it != bag.end()) {
			result += gem[pos].first; //가치
			bag.erase(it);
		}
		pos--;
	}

	cout << result;
	return 0;
}
