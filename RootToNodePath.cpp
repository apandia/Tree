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
 * SC - O(H) (For skewed tree O(N))
 */
bool traverse(Node* root, vector<int>& path, int value)
{
	if (root == nullptr)
		return false;

	path.push_back(root->data);

	if (root->data == value)
		return true;

	if (traverse(root->left, path, value) || traverse(root->right, path, value)) {
		return true;
	}

	path.pop_back();
	return false;
}

void printPath(Node* root, int value)
{
	if (root == nullptr)
	{
		return;
	}

	vector<int> path;
		
	bool pathExist = traverse(root, path, value);

	for (auto data : path) {
		cout << data << " " ;
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

   Output: 1 2 4 8 (path to 8)
*/

	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->left->right = new Node(8);

	root->right = new Node(3);
	root->right->left = new Node(6);
	root->right->right = new Node(7);	

	cout << "Root to Node path: ";
	printPath(root, 8);

	return 0;
}