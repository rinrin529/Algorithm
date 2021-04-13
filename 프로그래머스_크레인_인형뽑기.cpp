#include <string>
#include <vector>
#include <stack>
using namespace std;
int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack <int> each_cols[31];
	vector <int> box;
	for (int col = 0; col < board.size(); col++) {
		for (int row = board.size()-1; row >= 0; row--) {
			if (board[row][col] > 0) {
				each_cols[col + 1].push(board[row][col]);
			}
		}
	}
	for (int i = 0; i < moves.size(); i++) {
		if (!each_cols[moves[i]].empty()) {
			box.push_back(each_cols[moves[i]].top());
			each_cols[moves[i]].pop();
			if (box.size() > 1) {
				int idx = box.size() - 1;
				if (box[idx] == box[idx - 1]) {
					box.erase(box.begin() + idx);
					box.erase(box.begin() + (idx - 1));
					answer += 2;
				}
			}
		}
	}
	return answer;
}
