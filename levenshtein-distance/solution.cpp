using namespace std;

int levenshteinDistance(string str1, string str2) {
	int m = str1.length();
	int n = str2.length();
	
	vector<vector<int>> minChanges(m+1, vector<int>(n+1, 0));
	for (int i = 1; i < n+1; i++) {
		minChanges[0][i] = i;
	}
	
	for (int i = 1; i < m+1; i++) {
		minChanges[i][0] = i;
	}
	
	for (int i = 1; i < m+1; i++) {
		for (int j = 1; j < n+1; j++) {
			if (str1[i-1] == str2[j-1]) {
				minChanges[i][j] = minChanges[i-1][j-1];
			} else {
				int minChange = min(minChanges[i-1][j-1], minChanges[i][j-1]);
				minChange = min(minChange, minChanges[i-1][j]);
				minChanges[i][j] = minChange + 1;
			}
		}
	}
	
  return minChanges[m][n];
}
