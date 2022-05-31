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

// LCA of 2 nodes in BST
/*
Input Tree:
         6
        / \
       2   8
      / \   \
     0   4   9
        / \
       3   5

LCA[2,8] = 6
LCA[0,9] = 6
LCA[2,5] = 2
LCA[8,9] = 8
*/

//TC: O(H
//SC: O(H) (H for stack space)
Node* lcaRecursive(Node* root, int p, int q)
{
    if(root == nullptr)
        return nullptr;

    if(p < root->data && q < root->data)
        return lcaRecursive(root->left, p, q);

    if(p > root->data && q > root->data)
        return lcaRecursive(root->right, p, q);

    return root;
}

//TC: O(H
//SC: O(1) (No recursive stack space is used. Implemented using one while loop)
Node* lca(Node* root, int p, int q)
{
    while(root != nullptr)
    {
        if(p < root->data && q < root->data)
            root = root->left;
        else if(p > root->data && q > root->data)
            root = root->right;
        else
            break;
    }
    return root;
}

//Driver function
int main()
{
    Node* root = new Node(6);

    root->left = new Node(2);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    root->right = new Node(8);
    root->right->right = new Node(9);

    //TODO - Add nullcheck (for ->data) in case returned node is null
    //Currently testing only for nodes available in tree

    cout<<"Recursive solution for LCA:"<<endl;
    cout<<"LCA[2,8] = "<<lcaRecursive(root, 2, 8)->data<<endl;
    cout<<"LCA[0,9] = "<<lcaRecursive(root, 0, 9)->data<<endl;
    cout<<"LCA[2,5] = "<<lcaRecursive(root, 2, 5)->data<<endl;
    cout<<"LCA[8,9] = "<<lcaRecursive(root, 8, 9)->data<<endl;

    cout<<"Non Recursive solution for LCA:"<<endl;
    cout<<"LCA[2,8] = "<<lca(root, 2, 8)->data<<endl;
    cout<<"LCA[0,9] = "<<lca(root, 0, 9)->data<<endl;
    cout<<"LCA[2,5] = "<<lca(root, 2, 5)->data<<endl;
    cout<<"LCA[8,9] = "<<lca(root, 8, 9)->data<<endl;

    return 0;
}
