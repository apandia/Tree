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
 2	   3
	 /   \
	4	  6
   /
  5
*/

/*Level Order Traversal Input
1
2 3
-1 -1
4 6
5 -1
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


/*Level Order Traversal Expected Output
1
2 3
4 6
5
*/
vector<vector<int>> levelOrder(Node *root)
{
	vector<vector<int>> ans;

	if (root == nullptr)
		return ans;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		int size = q.size();
		vector<int> currLevelData;

		for (int counter = 0; counter < size; counter++)
		{
			Node* current = q.front();
			q.pop();

			if (current->left != nullptr) {
				q.push(current->left);
			}

			if (current->right != nullptr) {
				q.push(current->right);
			}

			currLevelData.push_back(current->data);
			cout << current->data << " ";
		}

		cout << endl;

		ans.push_back(currLevelData);
	}

	return ans;
}

int getTreeHeight(Node* root)
{
	if (root == nullptr)
		return 0;

	int lh = getTreeHeight(root->left);
	if (lh == -1) {
		return -1;
	}
	int rh = getTreeHeight(root->right);
	if (rh == -1) {
		return -1;
	}

	if (abs(lh - rh) > 1)
	{
		cout << "Tree is imbalanced at node = " << root->data << endl;
		cout << "Left height = " << lh << " Right height is = " << rh << endl;

		return -1;
	}

	return 1 + max(lh, rh);
}

bool checkBalancedTree(Node* root)
{
	return getTreeHeight(root) != -1;
}

//Driver function
int main() {

	//node* root = buildTree();
	Node* root = buildTree();

	cout << "Levelorder Traversal Print: " << endl;
	vector<vector<int>> lo = levelOrder(root);

	for (int i = 0; i < lo.size(); i++)
	{
		vector<int> level = lo[i];
		for (int j = 0; j < level.size(); j++)
		{
			cout << level[j] << " ";
		}
		cout << endl;
	}

	if(checkBalancedTree(root))
		cout << "Tree is balanced"  << endl;
	else
		cout << "Tree is not balanced" << endl;

	return 0;
}