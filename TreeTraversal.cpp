#include<iostream>


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

//Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
Node* buildTree()
{

	int d;
	cin >> d;

	if (d == -1) {
		return NULL;
	}

	Node* n = new Node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void inOrderPrint(Node *root) 
{
	if (root == nullptr)
	{
		return;
	}

	inOrderPrint(root->left);
	cout << root->data << " ";
	inOrderPrint(root->right);
}

void postOrderPrint(Node *root) 
{
	if (root == nullptr)
	{
		return;
	}

	postOrderPrint(root->left);
	postOrderPrint(root->right);
	cout << root->data << " ";
}

void preOrderPrint(Node *root)
{
	if (root == nullptr)
		return;

	cout << root->data << " ";

	preOrderPrint(root->left);
	preOrderPrint(root->right);
}

//Driver function
int main() {

	//node* root = buildTree();
	Node* root = buildTree();

	cout << "Inorder Print: " << endl;
	inOrderPrint(root);

	cout << "\nPreorder Print: " << endl;
	preOrderPrint(root);

	cout << "\nPostorder Print: " << endl;
	postOrderPrint(root);

	return 0;
}