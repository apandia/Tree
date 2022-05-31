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

// Check if below BST is valid or not
/*
Input Tree:
         5
        / \
       3   6
      / \
     2   4
    /
   1

Output: Valid BST

Input Tree:
         5
        / \
       3   6
      / \
     2   4
    /
   7

Output: Invalid BST
*/

//TC: O(N))
//SC: O(1)
bool isValid(Node* root, long min, long max)
{
    if(root == nullptr)
        return true;

    if(root->data <= min || root->data >= max)
        return false;

    return isValid(root->left, min, root->data) && isValid(root->right, root->data, max);
}

bool isValidBST(Node* root)
{
    return isValid(root, LONG_MIN, LONG_MAX);
}

//Driver function
int main()
{
    Node* root1 = new Node(5);

    root1->left = new Node(3);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->left->left->left = new Node(1);

    root1->right = new Node(6);

    Node* root2 = new Node(5);

    root2->left = new Node(3);
    root2->left->left = new Node(2);
    root2->left->right = new Node(4);
    root2->left->left->left = new Node(7);

    root2->right = new Node(6);

    if(isValidBST(root1))
        cout<<"Tree1 is Valid BST"<<endl;
    else
        cout<<"Tree1 is not Valid BST"<<endl;

    if(isValidBST(root2))
        cout<<"Tree2 is Valid BST"<<endl;
    else
        cout<<"Tree2 is not Valid BST"<<endl;

    return 0;
}
