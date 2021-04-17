#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	int size = denoms.size();
  vector<int> way(n+1, 0); // way[i] 表示当目标面额是 i 时，有多少种组合
	way[0] = 1; 
	
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < n+1; j++) {
			if (j >= denoms[i]) {
				way[j] += way[j - denoms[i]];
			}
		}
	}
  return way[n];
}
