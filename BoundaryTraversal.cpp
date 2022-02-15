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

bool isLeafNode(Node* node)
{
	bool val1 = ((node->left == nullptr) && (node->right == nullptr));
	bool val2 = (node->left && node->right );
	bool val3 = (!node->left && !node->right);

	return ((node->left == nullptr) && (node->right == nullptr));
}

void addLeftBoundary(Node* root, vector<int>& result)
{
	Node* current = root->left;
	while (current)
	{
		if (!isLeafNode(current)) {
			result.push_back(current->data);
		}

		if (current->left)
			current = current->left;
		else
			current = current->right;
	}
}

void addLeftNodes(Node* root, vector<int>& result)
{
	if (isLeafNode(root)) {
		result.push_back(root->data);
		return;
	}

	if (root->left)
		addLeftNodes(root->left, result);

	if (root->right)
		addLeftNodes(root->right, result);
}

void  addRightBoundary(Node* root, vector<int>& result)
{
	Node* current = root->right;
	vector<int> temp;
	while (current)
	{
		if (!isLeafNode(current)) {
			temp.push_back(current->data);
		}

		if (current->right)
			current = current->right;
		else
			current = current->left;
	}

	for (int counter = temp.size()-1; counter >= 0; counter--) {
		result.push_back(temp[counter]);
	}
}

void printBoundary(Node* root)
{
	if (root == nullptr)
		return;

	vector<int> result;

	if (!isLeafNode(root)) {
		result.push_back(root->data);
	}

	addLeftBoundary(root, result);
	addLeftNodes(root, result);
	addRightBoundary(root, result);

	//print the result
	for (int data : result)
		cout << data << " ";
}

//Driver function
int main()
{
	/*		1
		  /   \
		2		5
	  /		  /
	3		6
	 \	   / \
	  4   7	  8

    output - 1 2 3 4 7 8 6 5
	*/
	
	Node* root = new Node(1);
	
	root->left = new Node(2);
	root->left->left = new Node(3);
	root->left->left->right = new Node(4);

	root->right = new Node(5);
	root->right->left = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	printBoundary(root);	

	return 0;
}