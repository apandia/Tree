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

/*Tree2 input
    1
  /   \
 2      3
       / \
      4   5
*/

/*Tree2 input
     1
   /   \
  3      2
 / \
5   4
*/

/*Tree Input
1
2 3
-1 -1
4 5
6 7
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

void mirror(Node *root)
{
	if (root == nullptr) {
		return;
	}

	mirror(root->left);
	mirror(root->right);

	//swap left and right child
	Node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void intOrderPrint(Node *root)
{
	if (root == nullptr)
	{
		return;
	}

	intOrderPrint(root->left);
	cout << root->data << " ";
	intOrderPrint(root->right);
}

//Driver function
int main() {
	Node* root = buildTree();
	cout << "Inorder traversal of tree:" << endl;
	intOrderPrint(root);

	mirror(root);
	cout << "\nInorder traversal of mirror tree:" << endl;
	intOrderPrint(root);

	return 0;
}