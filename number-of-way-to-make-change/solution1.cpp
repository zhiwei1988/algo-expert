#include <vector>
using namespace std;

void backtrack(vector<int> &denoms, int value, int begin, int end);

int result = 0;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  // Write your code here.
	result = 0;
	if (n == 0) {
		return 1;
	}
	
	if (denoms.empty()) {
		return result;
	}
	
	int begin = 0;
	int end = 0;
	
	std::sort(denoms.begin(), denoms.end());
	
	if (n < denoms[0]) {
		return result;
	}
	
	int i = 1;
	for (; i < denoms.size(); i++) {
		if (denoms[i] > n) {
			end = i - 1;
			break;
		}
	}
	
	if (i == denoms.size()) {
		end = denoms.size() - 1;
	}
	
	backtrack(denoms, n, begin, end);
	
  return result;
}

void backtrack(vector<int> &denoms, int value, int begin, int end) {
	if (value == 0) {
		result++;
		return;
	}
	
	for (int i = begin; i <= end; i++) {
		if (value - denoms[i] < 0) {
			return;
		}
		
		value -= denoms[i];
		backtrack(denoms, value, i, end);
		value += denoms[i];
	}
}

