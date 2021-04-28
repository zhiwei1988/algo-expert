#include <vector>
using namespace std;

typedef struct {
    int x;
    int y;
} MatrixCoordinate;

void backtrack(vector<vector<int>> &matrix, 
        vector<MatrixCoordinate> &island,
        vector<vector<bool>> &visted,
        int row, int col) {
    if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size()) {
        return;
    } 

    if (visted[row][col]) {
        return;
    }

    int leftStart = 0;
    int topStart = 0;
    int rightEnd = matrix[0].size() - 1;
    int bottomEnd = matrix.size() - 1;

    if (matrix[row][col] == 0) {
        return;
    } else {
        if (row == topStart || row == bottomEnd || col == leftStart || col == rightEnd) {
            if (!island.empty()) {
                island.clear();
            }
            return;
        } else {
            visted[row][col] = true;
            MatrixCoordinate coordinate {};
            coordinate.x = row;
            coordinate.y = col;
            island.push_back(coordinate);
            backtrack(matrix, island, visted, row-1, col);
            backtrack(matrix, island, visted, row+1, col);
            backtrack(matrix, island, visted, row, col-1);
            backtrack(matrix, island, visted, row, col+1);
        }
    }
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    if (matrix.empty()) {
        return matrix;
    }

    vector<vector<MatrixCoordinate>> islands;
    vector<vector<bool>> visted(matrix.size(), vector<bool>(matrix[0].size(), false));
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            vector<MatrixCoordinate> island;
            backtrack(matrix, island, visted, i, j);
            if (!island.empty()) {
                islands.push_back(island);
            }
        }
    }

    for (int i = 0; i < islands.size(); i++) {
        for (int j = 0; j < islands[i].size(); j++) {
            int row = islands[i][j].x;
            int col = islands[i][j].y;
            matrix[row][col] = 0;
        }
    }
    return matrix;
}
