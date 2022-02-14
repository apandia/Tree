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

/*Tree1
    -10
   /   \
  9     20
       /  \
      15   7
*/

/*Tree Input
-10
9 20
-1 -1
15 7
-1 -1
-1 -1
*/

/*Tree2
    15
   /   \
 10     20
       /  \
     -15   -30
*/

/*Tree Input
15
10 20
-1 -1
-15 -30
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

int getMaxPathSum(Node* root, int& maxSum)
{
	if (root == nullptr)
	{
		return 0;
	}

	//If the left or right sum return negative then consider 0;
	//So that we can address scenario like Tree2 above.
	int leftSum = max(0, getMaxPathSum(root->left, maxSum));
	int rightSum = max(0, getMaxPathSum(root->right, maxSum));

	maxSum = max(maxSum, (leftSum + rightSum + root->data));

	return root->data + max(leftSum, rightSum);
}

int getMaxSum(Node* root)
{
	int maxSum = 0;
	int sum = getMaxPathSum(root, maxSum);
	return maxSum;
}

//Driver function
int main() {

	Node* root = buildTree();

	cout << "Max path Sum = " << getMaxSum(root) << endl;

	return 0;
}