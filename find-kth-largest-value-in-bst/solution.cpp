using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void helper(BST *tree, int &k, int &result) {
	if (tree == nullptr) {
		return;
	}
	
	helper(tree->right, k, result);
	
	k--;
	if (k == 0) {
		result = tree->value;
		return;
	}
	
	helper(tree->left, k, result);
}

int findKthLargestValueInBst(BST *tree, int k) {
	int result = -1;
	helper(tree, k, result);
  return result;
}
