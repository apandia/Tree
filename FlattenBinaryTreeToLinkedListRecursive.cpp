#include <iostream>
#include <string>
#include <sstream>
#include <queue>

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

// Flatten Binary Tree To Linked List - Recursive Solution
// using reverse post order approach i.e right left root

/*
Input Tree:
         1                  1
        / \                  \
       2   5        -->       2
      / \   \                  \
     3   4   6                  3
                                 \
                                  4
                                   \
                                    5
                                     \
                                      6
Output (Inorder): 1 2 3 4 5 6
*/

//TC: O(N)
//SC: O(N)
void flattenBinaryTreeRecursive(Node* root, Node** prev)
{
    if(root == nullptr)
        return;

    flattenBinaryTreeRecursive(root->right, prev);
    flattenBinaryTreeRecursive(root->left, prev);

    root->right = *prev;
    root->left = nullptr;
    *prev = root;
}

void flattenBinaryTree(Node* root)
{
    Node* prev = nullptr;

    flattenBinaryTreeRecursive(root, &prev);
}

void preorderTraversal(Node* root)
{
    if(root == nullptr)
        return;

    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right = new Node(5);
    root->right->right = new Node(6);

    flattenBinaryTree(root);

    cout<<"Binary Tree after flatten = ";
    preorderTraversal(root);
    cout<<endl;

    return 0;
}
