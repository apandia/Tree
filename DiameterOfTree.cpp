#include<iostream>
#include<stack>
#include <vector>
#include <algorithm>

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

/*Binary Tree
Input:
       1
      / \
     2   3
        / \
       4   7
      /     \
     5       8
    /         \
   6           9
*/

//Diameter of Tree : 6 (6->5->4->3->7->8->9)
/** Complexity:
  * TC: O(N)
  * SC: O(N)
 **/
int getTreeHeight(Node* root, int& diameter)
{
    if(root == nullptr)
        return 0;

    int leftHeight = getTreeHeight(root->left, diameter);
    int rightHeight = getTreeHeight(root->right, diameter);

    diameter = max(leftHeight+rightHeight, diameter);

    return 1 + max(leftHeight, rightHeight);
}

int getTreeDiameter(Node* root)
{
    int diameter = 0;

    int height = getTreeHeight(root, diameter);

    return diameter;
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);

    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->left->left->left = new Node(6);

    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right = new Node(9);

    cout<<"Diameter of Tree = "<<getTreeDiameter(root)<<endl;

    return 0;
}
