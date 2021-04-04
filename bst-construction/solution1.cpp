#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
public:
    int value;
    BST *left;
    BST *right;

    BST(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }

    BST &insert(int val) {
        BST *newNode = new BST(val);
        if (value <= val) {
            if (right == nullptr) {
                right = newNode;
            } else {
                right->insert(val);
            }
        } else {
            if (this->left == nullptr) {
                left = newNode;
            } else {
                left->insert(val);
            }
        }
        return *this;
    }

    bool contains(int val) {
        if (value == val) {
            return true;
        } else if (value < val) {
            if (right != nullptr) {
                return right->contains(val);
            } else {
                return false;
            }
        } else {
            if (left != nullptr) {
                return left->contains(val);
            } else {
                return false;
            }
        }
        return false;
    }

    BST &remove(int val, BST *parent = nullptr) {
        if (value > val && left != nullptr) {
            left->remove(val, this); /* 待删除的节点在当前节点的左子树中 */
        } else if (value < val && right != nullptr) {
            right->remove(val, this); /* 待删除的节点在当前节点的右子树中 */
        } else { /* 当前节点即要被删除的节点 */
            if (left != nullptr && right != nullptr) {
                value = right->getMinValue();
                right->remove(value, this);
            } else if (parent == nullptr) { /* 当前节点没有父节点 */
                if (left != nullptr) {
                    value = left->value;
                    right = left->right;
                    left = left->left;
                } else if (right != nullptr) {
                    value = right->value;
                    left = right->left;
                    right = right->right;
                } else {
                    // 只有单个节点，啥都不干
                }
            } else if (parent->left == this) {
                parent->left = left != nullptr ? left : right;
            } else if (parent->right == this) {
                parent->right = left != nullptr ? left : right;
            }	
        }

        return *this;
    }

    int getMinValue() {
        if (left == nullptr) {
            return value;
        } else {
            return left->getMinValue();
        }
    }
};
