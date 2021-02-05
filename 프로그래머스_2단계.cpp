#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
	int idx = 0;
	int count = 0;
	int size = truck_weights.size();
	queue <int> pass;
	queue <int> passby;

	while (1) {
		if (pass.size()== bridge_length) {
			if (pass.front() != 0) {
				passby.push(pass.front());
			}
			count -= pass.front();
			pass.pop();
		}
		if (idx < size) {
			if (count + truck_weights[idx] <= weight ) {
				pass.push(truck_weights[idx]);
				count += truck_weights[idx];
				idx++;
			}
			else {
				pass.push(0);
			}
		}
		else {
			pass.push(0);
		}
		answer++;

		if (passby.size() == size) {
			break;
		}
	}
    return answer;
}
