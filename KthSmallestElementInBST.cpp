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

// Kth Smallest element in BST
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
Output: 2

K = 5
Output: 5

*/

//TC: O(min(K,N))
//SC: O(min(K,N))
Node* kSmallestElementHelper(Node* root, int& k)
{
    if(root == nullptr)
        return nullptr;

    Node* left = kSmallestElementHelper(root->left, k);
    if(left != nullptr)
        return left;
    k--;
    if(k == 0)
        return root;

    return kSmallestElementHelper(root->right, k);
}

int kSmallestElement(Node* root, int k)
{
    Node* result = kSmallestElementHelper(root, k);

    if(result != nullptr)
        return result->data;
    else
        return -1;
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

    cout<<"3rd Smallest Element = "<<kSmallestElement(root, 3)<<endl;
    cout<<"5th Smallest Element = "<<kSmallestElement(root, 5)<<endl;

    return 0;
}
