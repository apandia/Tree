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

/*Tree
	    1
      /   \
    2       3
          /   \
        4       7
       /         \
      5           8
     /             \
    6               9
*/

/*Tree Input
1
2 3
-1 -1
4 7
5 -1
-1 8
6 -1
-1 9
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

int getHeight(Node* root, int& maxDiameter)
{
	if (root == nullptr)
	{
		return 0;
	}

	int lh = getHeight(root->left, maxDiameter);
	int rh = getHeight(root->right, maxDiameter);

	maxDiameter = max(maxDiameter, lh + rh);

	return 1 + max(lh, rh);
}

int getDiameter(Node* root)
{
	int diameter = 0;
	int height = getHeight(root, diameter);
	return diameter;
}

//Driver function
int main() {

	Node* root = buildTree();

	cout << "Height of Tree = " << getDiameter(root) << endl;

	return 0;
}