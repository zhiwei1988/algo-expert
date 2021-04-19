#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  vector<int> coins(n+1, INT_MAX); // coins[i] 表示当目标面额是 i 时，最少需要多少枚硬币
	coins[0] = 0;
	
	for (int i = 0; i < denoms.size(); i++) {
		for (int j = 1; j < n+1; j++) {
			if (denoms[i] <= j && coins[j-denoms[i]] != INT_MAX) {
				if (coins[j-denoms[i]] != INT_MAX) {
					coins[j] = min(coins[j], coins[j-denoms[i]]+1);
				} else {
					coins[j] = min(coins[j], coins[j-denoms[i]]);
				}	
			}
		}
	}
	
  return coins[n] == INT_MAX ? -1 : coins[n];
}
