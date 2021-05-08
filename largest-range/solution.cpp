#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array) {
  unordered_map<int, bool> hashMap;
	for (int i = 0; i < array.size(); i++) {
		hashMap[array[i]] = true;
	}
	
	set<int> larget_range {};
	for (int i = 0; i < array.size(); i++) {
		int value = array[i];
		if (!hashMap[value]) {
			continue;
		}
		
		set<int> range {};
		range.insert(value);
		int left = value-1;
		int right = value+1;
		while (hashMap.count(left) != 0) {
			hashMap[left] = false;
			range.insert(left);
			left--;
		}
		
		while (hashMap.count(right) != 0) {
			hashMap[right] = false;
			range.insert(right);
			right++;
		}
		
		if (range.size() > larget_range.size()) {
			larget_range = range;
		}
	}
	
	int start = *larget_range.begin();
	int end = *larget_range.rbegin();
	
  return vector<int> {start, end};
}
