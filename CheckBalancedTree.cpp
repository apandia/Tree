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

/*Binary Tree Traversal
Input:
      1
    /   \
   2     3
  / \   / \
 4   5 6   7
          / \
         8   9
*/

//Output : 4
/** Complexity:
  * TC: O(N)
  * SC: O(N) for skewed tree
 **/
int getTreeHeight(Node* root)
{
    if(root == nullptr)
        return 0;

    int leftHeight = getTreeHeight(root->left);
    if(leftHeight == -1)
        return -1;

    int rightHeight = getTreeHeight(root->right);
    if(rightHeight == -1)
        return -1;

    if(abs(leftHeight - rightHeight) > 1){
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(Node* root)
{
    return (getTreeHeight(root) != -1);
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    if(isBalanced(root))
        cout<<"Tree is balanced"<<endl;
    else
        cout<<"Tree is not balanced"<<endl;

    return 0;
}
