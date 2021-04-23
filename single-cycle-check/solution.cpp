using namespace std;

bool hasSingleCycle(vector<int> array) {
  int size = array.size();
	int n = size;
	int curIndex = 0;
	while (n > 0) {
		int tmp = array[curIndex] % size;
		curIndex += tmp;
		if (curIndex < 0) {
			curIndex += size;
		} else if (curIndex >= size) {
			curIndex = curIndex % size;
		}
		
		if (n > 1 && curIndex == 0) {
			return false;
		}
		
		if (n == 1 && curIndex != 0) {
			return false;
		}
		
		n--;
	}
	
  return true;
}
