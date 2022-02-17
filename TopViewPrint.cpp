#include<iostream>
#include<queue>
#include <vector>
#include<map>
#include <set>

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

void traverseTree(Node* root, int vLevel, map<int, int>& m)
{
	if (root == nullptr) {
		return;
	}

	if (!m.count(vLevel)) {
		m[vLevel] = root->data;
	}

	traverseTree(root->left, vLevel - 1, m);
	traverseTree(root->right, vLevel + 1, m);
}

//recursive implementation fails in usecase2
void topViewPrint(Node* root)
{
	int vLevel = 0;
	map<int, int> m;

	traverseTree(root, vLevel, m);

	for (auto element : m) {
		auto data = element.second;

		cout << data << " ";
	}
}

//Works for both usecase
void topView(Node* root)
{
	if (root == nullptr) {
		return;
	}

	vector<int> result;

	map<int, int> m;
	queue<pair<Node*, int>> q;

	q.push({root, 0 });

	while (!q.empty())
	{
		auto it = q.front();
		q.pop();

		Node* current = it.first;

		int line = it.second;

		if (m.find(line) == m.end()) {
			m[line] = current->data;
		}

		if (current->left != nullptr) {
			q.push({ current->left, line - 1 });
		}

		if (current->right != nullptr) {
			q.push({ current->right, line + 1 });
		}
	}

	for (auto it : m) {
		cout << it.second << " ";
	}
}

//Driver function
int main()
{
	/*
	Usecase1:
        1
      /   \
	 2     3
   /   \    \
  4     5    7
       /
	  6

    output: 4 2 1 3 7

	Usecase2:
	    1
	  /   \
	 2     3
	  \
	   4
	    \
		  5

	output: 2 1 3
	*/

	/*Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(6);

	root->right = new Node(3);
	root->right->right = new Node(7);*/

	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->right = new Node(4);
	root->left->right->right = new Node(5);

	root->right = new Node(3);

	topViewPrint(root);

	cout << "\nTopview: " << endl;
	topView(root);

	return 0;
}