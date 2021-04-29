#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int wei = 0;
	int size = truck_weights.size();
	queue <int> wait;
	queue <int> cross_bridge;
	queue <int> end;
	for (int i = 0; i < size; i++) {
		wait.push(truck_weights[i]);
	}
	wei += truck_weights[0];
	cross_bridge.push(wait.front());
	wait.pop();
	answer += 1;

	while (end.size()!=size) {
		answer++;
		if (!wait.empty()) {
			int next_wei = wait.front();
			if (next_wei + wei <= weight && cross_bridge.size()< bridge_length) {
				wei += next_wei;
				cross_bridge.push(next_wei);
				wait.pop();
			}
			else {
				if (cross_bridge.size() == bridge_length) {
					int out_wei = cross_bridge.front();
					wei -= out_wei;
					cross_bridge.pop();
					if (out_wei > 0) {
						end.push(out_wei);	// 빠져나간 트럭
					}
					if (next_wei + wei <= weight) {
						wei += next_wei;
						cross_bridge.push(next_wei);
						wait.pop();
					}
					else {
						cross_bridge.push(0);
					}
				}
				else {
					cross_bridge.push(0);
				}
			}
		}
		else {
			if (cross_bridge.size() == bridge_length) {
				int out_wei = cross_bridge.front();
				wei -= out_wei;
				cross_bridge.pop();
				if (out_wei > 0) {
					end.push(out_wei);	// 빠져나간 트럭
				}
				cross_bridge.push(0);
			}
			else {
				cross_bridge.push(0);
			}
		}
	}

	return answer;
}
