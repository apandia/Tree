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

void bottomView(Node* root)
{
	if (root == nullptr) {
		return;
	}

	map<int, int> m;

	queue<pair<Node*, int>> q;
	q.push({ root, 0 }); //level 0 for root node

	while (!q.empty())
	{
		auto it = q.front();
		q.pop();

		Node* current = it.first;
		int vLine = it.second;

		m[vLine] = current->data;

		if (current->left) {
			q.push({ current->left, vLine - 1 });
		}

		if (current->right) {
			q.push({ current->right, vLine + 1 });
		}		
	}

	for (auto data : m) {
		cout << data.second << " ";
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

    output: 4 6 5 3 7

	Usecase2:
	    1
	  /   \
	 2     3
	  \
	   4
	    \
		  5

	output: 2 4 5
	*/

	Node* root1 = new Node(1);

	root1->left = new Node(2);
	root1->left->left = new Node(4);
	root1->left->right = new Node(5);
	root1->left->right->left = new Node(6);

	root1->right = new Node(3);
	root1->right->right = new Node(7);

	Node* root2 = new Node(1);

	root2->left = new Node(2);
	root2->left->right = new Node(4);
	root2->left->right->right = new Node(5);

	root2->right = new Node(3);

	cout << "\nBottom view Tree1: " << endl;
	bottomView(root1);

	cout << "\nBottom view Tree2: " << endl;
	bottomView(root2);

	return 0;
}