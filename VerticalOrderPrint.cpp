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

void traverseTree(Node* root, int vLevel, map<int, vector<int>>& m)
//void traverseTree(Node* root, int vLevel, map<int, multiset<int>>& m)
{
	if (root == nullptr)
	{
		return;
	}

	m[vLevel].push_back(root->data);
	//m[vLevel].insert(root->data);

	//traverse left
	traverseTree(root->left, vLevel - 1, m);

	//traverse right
	traverseTree(root->right, vLevel + 1, m);
}

void verticalOrderPrint(Node* root)
{
	int vLevel = 0;
	map<int, vector<int>> m;
	//map<int, multiset<int>> m;

	traverseTree(root, vLevel, m);

	for (auto element : m) {
		auto key = element.first;
		vector<int> levelData = element.second;
		//multiset<int> levelData = element.second;

		cout << "Level[" << key << "]:";
		for (auto data : levelData)
			cout << data << " ";

		cout << endl;
	}
}

//Driver function
int main()
{
	/*		1
	      /   \
	    2	    3
	   / \	   /  \
	  4	  11  6    7
	         / \
	        8   9

	output:
	Level[-2]:4
	Level[-1]:2 8
	Level[0]:1 11 6 --> if sorted output is required then use multiset
	Level[1]:3 9
	Level[2]:7
	*/

	Node* root = new Node(1);

	root->left = new Node(2);
	root->left->left = new Node(4);
	root->left->right = new Node(11);

	root->right = new Node(3);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->left->left = new Node(8);
	root->right->left->right = new Node(9);

	verticalOrderPrint(root);

	return 0;
}