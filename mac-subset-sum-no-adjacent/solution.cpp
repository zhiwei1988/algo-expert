#include <vector>
using namespace std;

// dp[i] 表示从下标 0 到下标 i 之前不相邻元素的最大和
int maxSubsetSumNoAdjacent(vector<int> array) {
	if (array.size() == 0) {
		return 0;
	}
	
	if (array.size() < 2) {
		return array[0];
	}
	
  vector<int> dp(array.size(), 0);
	dp[0] = array[0];
	dp[1] = max(array[0], array[1]);
	
	for (int i = 2; i < array.size(); i++) {
		dp[i] = max(dp[i-1], dp[i-2] + array[i]);
	}
	
  return dp[array.size()-1];
}
