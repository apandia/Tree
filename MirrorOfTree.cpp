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

//Create Mirror tree
/*
Input Tree: 2 1 4 3 5 (inorder traversal)
         1
        / \
       2   3
          / \
         4   5
Output Tree: 5 3 4 1 2 (inorder traversal)
         1
        / \
       3   2
      / \
     5   4
*/

//TC: O(N)
//SC: O(N) (for skewed tree)
void mirrorTree(Node* root)
{
    if(root == nullptr)
        return;

    mirrorTree(root->left);
    mirrorTree(root->right);

    //swap left and right node
    Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}

void inOrderPrint(Node* root)
{
    if(root == nullptr)
        return;

    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

//Driver function
int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);

    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    cout<<"Input tree is (inorder traversal): ";
    inOrderPrint(root);
    cout<<endl;

    //Mirror of tree
    mirrorTree(root);

    cout<<"Mirror tree is (inorder traversal): ";
    inOrderPrint(root);
    cout<<endl;


    return 0;
}
