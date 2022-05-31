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

// Kth Largets element in BST
/*
Input Tree:
         5
        / \
       3   6
      / \
     2   4
    /
   1

K = 3
Output: 4

K = 2
Output: 5

*/

//TC: O(min(K,N))
//SC: O(min(K,N))
Node* kLargesttElementHelper(Node* root, int& k)
{
    if(root == nullptr)
        return nullptr;

    Node* right = kLargesttElementHelper(root->right, k);
    if(right != nullptr)
        return right;
    k--;
    if(k == 0)
        return root;

    return kLargesttElementHelper(root->left, k);
}

int kLargestElement(Node* root, int k)
{
    Node* result = kLargesttElementHelper(root, k);

    if(result != nullptr)
        return result->data;
    else
        return -1;
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
    Node* root = new Node(5);

    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);

    root->right = new Node(6);

    cout<<"Tree = ";
    inorderPrint(root);
    cout<<endl;

    cout<<"3rd Largest Element = "<<kLargestElement(root, 3)<<endl;
    cout<<"2nd Largest Element = "<<kLargestElement(root, 2)<<endl;

    return 0;
}
