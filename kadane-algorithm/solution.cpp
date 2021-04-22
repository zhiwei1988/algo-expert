#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
	if (array.size() < 1) {
		return 0;
	}
	
	int maxSofar = array[0];
	int maxEndIndexPre = array[0];
	
	for (int i = 1; i < array.size(); i++) {
		int maxEndIndex = max(maxEndIndexPre+array[i], array[i]);
		maxEndIndexPre = maxEndIndex;
		maxSofar = max(maxSofar, maxEndIndex);
	}
	
	return maxSofar;
}
