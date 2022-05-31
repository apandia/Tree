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

// Insert new node to BST
/*
Input Tree:
          4                        4
        /   \                    /   \
       2     7   --->           2     7
      / \                      / \   /
     1   3                    1   3 5


Output:
Tree Before Insertion (Preorder) - 4 2 1 3 7
Tree after Inserting 5 (Preorder) - 4 2 1 3 7 5
*/

//TC: O(log N) (Base 2)
//SC: O(N)
Node* insertIntoBST(Node* root, int key)
{
    if(root == nullptr)
        return new Node(key);

    if(key < root->data)
    {
        root->left = insertIntoBST(root->left, key);
    }
    else
    {
        root->right = insertIntoBST(root->right, key);
    }

    return root;
}

void preorderPrint(Node* root)
{
    if(root == nullptr)
        return;

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void inorderPrint(Node* root)
{
    if(root == nullptr)
        return;

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

//Driver function
int main()
{
    Node* root = new Node(4);

    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    root->right = new Node(7);

    cout<<"Tree before Insertion (preorder)= ";
    preorderPrint(root);
    cout<<endl;

    cout<<"Tree before Insertion (inorder) = ";
    inorderPrint(root);
    cout<<endl;

    root = insertIntoBST(root, 5);

    cout<<"Tree after inserting 5 (preorder) = ";
    preorderPrint(root);
    cout<<endl;

    cout<<"Tree after inserting 5 (inorder) = ";
    inorderPrint(root);
    cout<<endl;

    return 0;
}
