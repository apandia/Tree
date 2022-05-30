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

// Ceil Value in Binary Search Tree
/*
Input Tree:
          10
        /    \
       5      13
     /   \   /  \
    3     6 11   14
   / \     \
  2   4     9

Output:
Ceil[7] = 9
Ceil[8] = 9
Ceil[11] = 11
Ceil[12] = 13
*/

//TC: O(log N) (Base 2)
//SC: O(N)
int ceilInBinarySearchTree(Node* root, int key)
{
    int ceil = -1;

    while(root)
    {
        if(root->data == key)
        {
            return root->data;
        }

        if(root->data > key)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return ceil;
}

//Driver function
int main()
{
    Node* root = new Node(10);

    root->left = new Node(5);

    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);

    root->left->right = new Node(6);
    root->left->right->right = new Node(9);

    root->right = new Node(13);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

    cout<<"Ceil[7] = "<<ceilInBinarySearchTree(root, 7)<<endl;
    cout<<"Ceil[8] = "<<ceilInBinarySearchTree(root, 8)<<endl;
    cout<<"Ceil[11] = "<<ceilInBinarySearchTree(root, 11)<<endl;
    cout<<"Ceil[12] = "<<ceilInBinarySearchTree(root, 12)<<endl;

    return 0;
}
