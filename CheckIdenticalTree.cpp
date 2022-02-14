#include<iostream>
#include<queue>
#include <vector>

using namespace std;

class Node {

public:
	int data;
	Node* left;
	Node* right;

	Node(int d) {
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

/*Tree2
    1
  /   \
 2     3
      / \
     4   5
*/

/*Tree Input
1
2 3
-1 -1
4 5
-1 -1
-1 -1
*/
Node* buildTree()
{
	int d;
	cin >> d;

	Node* root = new Node(d);
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* current = q.front();
		q.pop();

		int c1, c2;
		cin >> c1 >> c2;

		if (c1 != -1) {
			current->left = new Node(c1);
			q.push(current->left);
		}
		if (c2 != -1) {
			current->right = new Node(c2);
			q.push(current->right);
		}
	}

	return root;
}

bool isIdenticalTree(Node* tree1, Node* tree2)
{
	if ((tree1 == nullptr) || (tree2 == nullptr)) {
		return (tree1 == tree2);
	}

	return ((tree1->data == tree2->data) && isIdenticalTree(tree1->left, tree2->left) && isIdenticalTree(tree1->right, tree2->right));
}

//Driver function
int main() {
	cout << "First tree: " << endl;
	Node* tree1 = buildTree();

	cout << "Second tree: " << endl;
	Node* tree2 = buildTree();

	if (isIdenticalTree(tree1, tree2))
		cout << "Trees Aare Identical" << endl;
	else
		cout << "Trees are not identical" << endl;

	return 0;
}