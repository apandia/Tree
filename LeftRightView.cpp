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
/* Iterative Solution:
 * TC - O(N)
 * SC - O(number of leaf node)
 * So the number of leaf nodes are high i.e then higher space complexity
 *
 * Recursive Solution:
 * TC - O(N)
 * SC - O(H)
 * Space complexity in case of skewed tree (say tree in one vertical line with many levels) will be O(N)
 */

void leftViewIterative(Node* root)
{
	if (root == nullptr) {
		return;
	}

	queue<pair<Node*,int>> q;
	q.push({ root, 0 });

	map<int, int> result;

	while (!q.empty())
	{
		auto it = q.front();
		q.pop();

		Node* current = it.first;
		int level = it.second;

		if (!result.count(level))
		{
			result[level] = current->data;
		}

		if (current->left != nullptr) {
			q.push({ current->left, level + 1 });
		}
		
		if(current->right != nullptr) {
			q.push({ current->right, level + 1 });
		}
	}

	for (auto data : result) {
		cout << data.second << " ";
	}
}

void rightViewIterative(Node* root)
{
	if (root == nullptr) {
		return;
	}

	queue<pair<Node*, int>> q;
	q.push({ root, 0 });

	map<int, int> result;

	while (!q.empty())
	{
		auto it = q.front();
		q.pop();

		Node* current = it.first;
		int level = it.second;

		if (!result.count(level))
		{
			result[level] = current->data;
		}

		if (current->right != nullptr) {
			q.push({ current->right, level + 1 });
		}

		if (current->left != nullptr) {
			q.push({ current->left, level + 1 });
		}
	}

	for (auto data : result) {
		cout << data.second << " ";
	}
}

void leftViewRecurse(Node* root, int level, vector<int>& result)
{
	if (root == nullptr) {
		return;
	}

	if (result.size() == level) {
		result.push_back(root->data);
	}

	leftViewRecurse(root->left, level + 1, result);
	leftViewRecurse(root->right, level + 1, result);
}

void rightViewRecurse(Node* root, int level, vector<int>& result)
{
	if (root == nullptr) {
		return;
	}

	if (result.size() == level) {
		result.push_back(root->data);
	}

	rightViewRecurse(root->right, level + 1, result);
	rightViewRecurse(root->left, level + 1, result);
}

void leftViewRecursive(Node* root)
{
	vector<int> result;
	int level = 0;

	leftViewRecurse(root, level, result);

	for (auto data : result) {
		cout << data << " ";
	}
}

void rightViewRecursive(Node* root)
{
	vector<int> result;
	int level = 0;

	rightViewRecurse(root, level, result);

	for (auto data : result) {
		cout << data << " ";
	}
}

//Driver function
int main()
{
	/*
        1
      /   \
	 2     3
       \    \
        5    6
            /
	       7

    LeftView : 1 2 5 7
	RightView: 1 3 6 7
	*/

	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->right = new Node(5);

	root->right = new Node(3);
	root->right->right = new Node(6);
	root->right->right->left = new Node(7);

	cout << "\nLeft view of Tree (Iterative Solution): " << endl;
	leftViewIterative(root);

	cout << "\nTight view of Tree (Iterative Solution): " << endl;
	rightViewIterative(root);

	cout << "\nLeft view of Tree (Recursive Solution): " << endl;
	leftViewRecursive(root);

	cout << "\nTight view of Tree (Recursive Solution): " << endl;
	rightViewRecursive(root);

	return 0;
}