using namespace std;

int numberOfWaysToTraverseGraph(int width, int height) {
  // Write your code here.
	vector<vector<int>> ways(height+1, vector<int>(width+1, 1));
	
	for (int i = 2; i < height+1; i++) {
		for (int j = 2; j < width+1; j++) {
			ways[i][j] = ways[i-1][j] + ways[i][j-1];
		}
	}
	
  return ways[height][width];
}
