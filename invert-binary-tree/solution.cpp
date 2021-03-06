#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
	if (tree == nullptr) {
		return;
	}
	
	if (tree->left != nullptr) {
		invertBinaryTree(tree->left);
	}
	
	if (tree->right != nullptr) {
		invertBinaryTree(tree->right);
	}
	
	BinaryTree *node = tree->left;
	tree->left = tree->right;
	tree->right = node;
}
