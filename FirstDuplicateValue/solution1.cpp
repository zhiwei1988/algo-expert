#include <vector>
#include <unordered_map>
using namespace std;

int firstDuplicateValue(vector<int> array) 
{
	unordered_map<int, int> duplicateValueMap;
	for (int i = 0; i < array.size(); i++) {
		int value = array[i];
		duplicateValueMap[value]++;
		if (duplicateValueMap[value] > 1) {
			return value;
		}
	}
	return -1; 
}

