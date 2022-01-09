#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<pair<int, string>> genres_count;		// genres, count
	vector<pair<int, int>> plays_count[100];	// play time, idx
	int size = genres.size();
	genres_count.push_back(make_pair(plays[0], genres[0]));
	for (int i = 1; i < size; i++) {  // 장르에서 각각의 갯수 세기
		int check = 0;
		for (int j = 0; j < genres_count.size(); j++) {
			if (genres_count[j].second == genres[i]) {
				genres_count[j].first+=plays[i];
				check = 1;
				break;
			}
		}
		if (check == 0) {
			genres_count.push_back(make_pair(plays[i], genres[i]));
		}
	}
	sort(genres_count.begin(), genres_count.end(), greater<>());
	for (int i = 0; i < plays.size(); i++) {
		for (int j = 0; j < genres_count.size(); j++) {
			if (genres[i] == genres_count[j].second) {
				plays_count[j].push_back(make_pair(plays[i], i));
				break;
			}
		}
	}
	for (int i = 0; i < genres_count.size(); i++) {
		sort(plays_count[i].begin(), plays_count[i].end(), compare);
		if (plays_count[i].size() > 1) {
			answer.push_back(plays_count[i][0].second);
			answer.push_back(plays_count[i][1].second);
		}
		else {
			answer.push_back(plays_count[i][0].second);
		}
	}
	
	return answer;
}
