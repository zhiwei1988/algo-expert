/* 时间复杂度 nlog(n), 空间复杂度 n */
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

BST *helper(vector<int> &array, int left, int right, BST *parent);

BST *minHeightBst(vector<int> array) {
  return helper(array, 0, array.size()-1, nullptr);
}

BST *helper(vector<int> &array, int left, int right, BST *parent) {
	if (left > right) {
		return nullptr;
	}
	
	int mid = (left + right) / 2;
	if (parent == nullptr) {
		parent = new BST(array[mid]);
	} else {
		parent->insert(array[mid]);
	}
	
	helper(array, left, mid-1, parent);
	helper(array, mid+1, right, parent);
	
	return parent;
}
