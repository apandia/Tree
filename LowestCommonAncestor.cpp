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
 * SC - O(N)
 */
Node* lowestCommonAncestor(Node* root, int value1, int value2)
{
	if (root == nullptr) {
		return root;
	}

	if (root->data == value1 || root->data == value2) {
		return root;
	}

	Node* left = lowestCommonAncestor(root->left, value1, value2);
	Node* right = lowestCommonAncestor(root->right, value1, value2);

	//If in place of values nodes are given then use below code in place of code above
	/*
	if(root == nullptr || node1 == nullptr || node2 == nullptr)
	{
		return root;
	}

	Node* left = lowestCommonAncestor(root->left, node1, node2);
	Node* right = lowestCommonAncestor(root->right, node1, node2);
	*/

	if (left == nullptr) {
		return right;
	}
	else if(right == nullptr) {
		return left;
	}
	else {
		return root;
	}
}


//Driver function
int main()
{
/*
        1
      /   \
	 2     3
    / \   / \
   4   5 6   7
    \
     8

   lca(8, 5) = 2
   lca(6, 3) = 3
*/

	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->left->right = new Node(8);

	root->right = new Node(3);
	root->right->left = new Node(6);
	root->right->right = new Node(7);	

	Node* lca = lowestCommonAncestor(root, 8, 5);
	cout << "LCA of 8 and 5 = "<<lca->data<<endl;

	lca = lowestCommonAncestor(root, 6, 3);
	cout << "LCA of 6 and 3 = " << lca->data;

	return 0;
}