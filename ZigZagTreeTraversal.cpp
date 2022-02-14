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

/*Tree2
      1
    /   \
   2      3
  /  \   / \
 4    5 6   7
*/

/*Tree Input
1
2 3
4 5
6 7
-1 -1
-1 -1
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

vector<vector<int>> zigZagTraversal(Node* root)
{
	vector<vector<int>> ans;

	if (root == nullptr)
	{
		return ans;
	}

	queue<Node*> q;
	q.push(root);

	bool zigZag = false;

	while (!q.empty())
	{
		int size = q.size();
		vector<int> level;

		for (int counter = 0; counter < size; counter++)
		{
			Node* current = q.front();
			q.pop();			

			if (current->left != nullptr) 
			{
				q.push(current->left);
			}

			if (current->right != nullptr)
			{
				q.push(current->right);
			}

			level.push_back(current->data);
		}

		if (zigZag == false) {
			ans.push_back(level);
			zigZag = true;
		}
		else {
			reverse(level.begin(), level.end());
			ans.push_back(level);
			zigZag = false;
		}	
	}

	return ans;
}


//Driver function
int main() {
	Node* root = buildTree();

	cout << "Levelorder Traversal Print: " << endl;
	vector<vector<int>> lo = zigZagTraversal(root);

	for (int i = 0; i < lo.size(); i++)
	{
		vector<int> level = lo[i];
		for (int j = 0; j < level.size(); j++)
		{
			cout << level[j] << " ";
		}
		cout << endl;
	}

	return 0;
}