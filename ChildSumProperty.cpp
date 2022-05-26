#include <iostream>

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

// Chils sum property - Value of node should be sum of value of child nodes
// nodeVal = leftNodeVal+rightNodeVal
// Only increment operation is allowed and no decrement operation allowed
/*
Input Tree:
          50                               50
        /    \                           /     \
       /      \                         /       \
      7        2        ------>        19       31
     / \      / \                     /  \     /  \
    /   \    /   \                   /    \   /    \
   3     5  1    30                 14     5 1     30

Inorder traversal:
3 7 5 50 1 2 30                     14 19 5 50 1 31 30
*/

/* Traverse the given tree in post order to convert it, i.e.,
 * first change left and right children to hold the children sum property
 * then change the parent node. Let difference between node’s data and children sum be diff.
 *
 * diff = node’s children sum - node’s data
 * If diff is 0 then nothing needs to be done.
 * If diff > 0 ( node’s data is smaller than node’s children sum) increment the node’s data by diff.
 * If diff < 0 (node’s data is greater than the node’s children sum) then increment one child’s data.
 */
 
//For O(N) algorith, refer https://github.com/apandia/Tree/blob/main/ChildSumPropertyLinearTime.cpp

//TC: O(N^2)
//SC: O(H) O(N) for skewed tree
void incrementNodeValue(Node* node, int diff)
{
    if(node->left)
    {
        node->left->data = node->left->data + diff;

        incrementNodeValue(node->left, diff);
    } else if(node->right)
    {
        node->right->data = node->right->data + diff;
        incrementNodeValue(node->right, diff);
    }
}

void changeBinaryTree(Node* root)
{
    //If root is null or leaf node return
    if(root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    int childValue =0;

    changeBinaryTree(root->left);
    changeBinaryTree(root->right);

    if(root->left)
        childValue += root->left->data;

    if(root->right)
        childValue += root->right->data;

    int diff = root->data - childValue;

    if(diff > 0)
        incrementNodeValue(root, diff);

    if(diff < 0)
        root->data = childValue;

}

void printInorder(Node* root)
{
    if(root == nullptr)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

//Driver function
int main()
{
    Node *root = new Node(50);

    root->left = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    root->right = new Node(2);
    root->right->left = new Node(1);
    root->right->right = new Node(30);

    cout << "\nTree before conversion (Inorder traversal): ";
    printInorder(root);
    cout << endl;

    changeBinaryTree(root);

    cout << "\nTree after conversion (Inorder traversal): ";
    printInorder(root);
    cout << endl;

    return 0;
}
