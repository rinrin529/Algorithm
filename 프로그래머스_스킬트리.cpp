#include <string>
#include <vector>
using namespace std;
int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	pair<int, int> check[21]; // ( skill tree idx, skill idx )
	for (int i = 0; i < skill_trees.size(); i++) {
		check[i].first = 30;
		check[i].second = 30;
	}
	for (int s = 0; s < skill.size(); s++) {
		for (int t = 0; t < skill_trees.size(); t++) {
			if (skill_trees[t].find(skill[s]) != string::npos) { //있을 때 
				int idx = skill_trees[t].find(skill[s]); //스킬 인덱스
				if (check[t].first == 30 && s == 0 && check[t].first != -1) {
					check[t].first = idx;
					check[t].second = s;
				}
				else if (check[t].first < idx && check[t].first != -1 && (check[t].second + 1) == s) {
					check[t].first = idx;
					check[t].second = s;
				}
				else {
					check[t].first = -1;
				}
			}
		}
	}
	for (int i = 0; i < skill_trees.size(); i++) {
		if (check[i].first > -1)
			answer++;
	}
	return answer;
}
