#include <vector>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {
    // Write your code here.
		queue<Node *> queue;
		queue.push(this);
		while (!queue.empty()) {
			Node *node = queue.front();
			queue.pop();
			array->push_back(node->name);
			for (int i = 0; i < node->children.size(); i++) {
				queue.push(node->children[i]);
			}
		}
		
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
