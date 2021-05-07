#include <vector>
using namespace std;

vector<int> subarraySort(vector<int> array) {
  set<int> unsortedMembers;
	for (int i = 0, j = 1; i < array.size() && j < array.size(); i++, j++) {
		if (array[i] > array[j]) {
			unsortedMembers.insert(array[i]);
			unsortedMembers.insert(array[j]);
		}
	}
	
	vector<int> result(2, -1);
	if (unsortedMembers.empty()) {
		return result;
	}
	
	int min = *unsortedMembers.begin();
	int max = *unsortedMembers.rbegin();
	for (int i = 0; i < array.size(); i++) {
		if (array[i] <= min) {
			continue;
		}
		result[0] = i;
		break;
	}
	
	for (int i = array.size()-1; i >= 0; i--) {
		if (array[i] >= max) {
			continue;
		}
		result[1] = i;
		break;
	}
	
  return result;
}
