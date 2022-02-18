#include<iostream>
#include<queue>
#include<map>

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

/* Complexity:
 * TC - O(N)
 * SC - O(N) (For skewed tree)
 */
bool traverse(Node* tree1, Node* tree2)
{
	if (tree1 == nullptr || tree2 == nullptr)
		return (tree1 == tree2);

	return ((tree1->data == tree2->data)
		&& traverse(tree1->left, tree2->right)
		&& traverse(tree1->right, tree2->left));
}

bool checkSymmetricalTree(Node* root)
{
	if (root == nullptr)
	{
		return true;
	}
		
	return traverse(root->left, root->right);
}


//Driver function
int main()
{
/*
        1
      /   \
	 2     2
    / \   / \
   4   5 5   4

   left and right side are mirror of one another
*/

	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right = new Node(2);
	root->right->left = new Node(5);
	root->right->right = new Node(4);	

	if (checkSymmetricalTree(root)) {
		cout << "Tree is Symmetrical" << endl;
	}
	else {
		cout << "Tree is Not Symmetrical" << endl;
	}

	return 0;
}
