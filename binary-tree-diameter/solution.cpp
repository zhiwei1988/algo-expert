using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

struct NodeInfo {
	int height; // 当前节点高度
	int diameter; // 以当前节点为root节点的树的直径
};

NodeInfo GetNodeInfo(BinaryTree *tree) {
	NodeInfo nodeInfo {};
	if (tree == nullptr) {
		return nodeInfo;
	}
	
	NodeInfo leftSubTreeInfo = GetNodeInfo(tree->left);
	NodeInfo rightSubTreeInfo = GetNodeInfo(tree->right);
	
	int pathLenThroughRoot = leftSubTreeInfo.height + rightSubTreeInfo.height;
	int diameterSofar = max(leftSubTreeInfo.diameter, rightSubTreeInfo.diameter);
	nodeInfo.height = max(leftSubTreeInfo.height, rightSubTreeInfo.height) + 1;
	nodeInfo.diameter = max(pathLenThroughRoot, diameterSofar);
	
	return nodeInfo;
}

int binaryTreeDiameter(BinaryTree *tree) {
	NodeInfo nodeInfo = GetNodeInfo(tree);
	return nodeInfo.diameter;
}
