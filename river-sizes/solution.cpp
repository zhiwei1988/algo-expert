#include <vector>
using namespace std;

void backtrack(vector<vector<int>> &matrix, vector<vector<bool>> &visted, int row, int col, int width, int height, int &number);

vector<int> riverSizes(vector<vector<int>> matrix) {
	vector<int> result;
  vector<vector<bool>> visted(matrix.size(), vector<bool>(matrix[0].size(), false));
	int width = matrix[0].size();
	int height = matrix.size();
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			int number = 0;
			backtrack(matrix, visted, i, j, width, height, number);
			if (number != 0) {
				result.push_back(number);
			}
		}
	}
  return result;
}

void backtrack(vector<vector<int>> &matrix, vector<vector<bool>> &visted, int row, int col, int width, int height, int &number) {
	if (row < 0 || row >= height) {
		return;
	}
	
	if (col < 0 || col >= width) {
		return;
	}
	
	if (matrix[row][col] == 0 || visted[row][col]) {
		return;
	}
	
	number++;
	visted[row][col] = true;
	
	backtrack(matrix, visted, row-1, col, width, height, number);
	backtrack(matrix, visted, row+1, col, width, height, number);
	backtrack(matrix, visted, row, col-1, width, height, number);
	backtrack(matrix, visted, row, col+1, width, height, number);
}
