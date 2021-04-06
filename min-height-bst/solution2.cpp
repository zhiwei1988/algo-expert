/* 时间复杂度 n, 空间复杂度 n */
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST *helper(vector<int> &array, int left, int right);

BST *minHeightBst(vector<int> array) {
  return helper(array, 0, array.size() - 1);
}

BST *helper(vector<int> &array, int left, int right) {
	if (left > right) {
		return nullptr;
	}
	
	int mid  = (left + right) / 2;
	BST *node = new BST(array[mid]);
	node->left = helper(array, left, mid-1);
	node->right = helper(array, mid+1, right);
	
	return node;
}
