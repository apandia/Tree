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

// Floor Value in Binary Search Tree
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
Floor[7] = 6
Floor[8] = 6
Floor[11] = 11
Floor[12] = 11
*/

//TC: O(log N) (Base 2)
//SC: O(N)
int floorInBinarySearchTree(Node* root, int key)
{
    int floor = -1;

    while(root)
    {
        if(root->data == key)
        {
            return root->data;
        }

        if(root->data > key)
        {
            root = root->left;
        }
        else
        {
            floor = root->data;
            root = root->right;
        }
    }

    return floor;
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

    cout<<"Floor[7] = "<<floorInBinarySearchTree(root, 7)<<endl;
    cout<<"Floor[8] = "<<floorInBinarySearchTree(root, 8)<<endl;
    cout<<"Floor[11] = "<<floorInBinarySearchTree(root, 11)<<endl;
    cout<<"Floor[12] = "<<floorInBinarySearchTree(root, 12)<<endl;

    return 0;
}
